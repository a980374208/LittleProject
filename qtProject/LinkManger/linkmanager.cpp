#include "Link/broadcastudplink.h"
#include "linkmanager.h"
#include "Link/multicastudplink.h"
#include "Link/seriaportlink.h"
#include "Link/tcplink.h"
#include "Link/udplink.h"
#include <QMutex>

LinkManager::LinkManager(QObject *parent) : QObject(parent),
    m_plinkconfig(nullptr)
{
    m_plinkconfig = LinkConfig::instance();


    m_pConsumerThread = new QueueConsumerThread;
    m_ProductThread = new QThread;
    m_ProductQueue = new QueueProductThread;
    m_ProductQueue->moveToThread(m_ProductThread);

    m_pConsumerThread->start();
    m_ProductThread->start();

    initConnect();
    initLink();

    //    connect(&m_timer,&QTimer::timeout,this,[&](){
    //       m_ProductQueue->recvLinkData(std::make_pair(LinkTypeTcp,"2"),"aaaaaa");
    //    });
    //    m_timer.start(1);
}

QVector<ILink *> LinkManager::getLstLink() const
{
    QVector<ILink *> lstLink;
    for(auto item:LinkConfig::instance()->getMapConfig()){
        lstLink.append(item->pLink);
    }
    return lstLink;
}

void LinkManager::removeLink(ILink *link,const QString& ProtoName)
{
    LinkConfig::instance()->removeLinkConfig(link->getConfig(),ProtoName);
}

void LinkManager::recvLinkData(std::pair<LinkType,QString> linkType, const QByteArray &byteArray)
{
    m_ProductQueue->recvLinkData(linkType,byteArray);
}

ILink *LinkManager::getLinkClass(BaseConfig* baseconfig)
{
    ILink* pLink = nullptr;
    switch(baseconfig->connectType){
    case LinkTypeTcp:{
        pLink = new TcpLink(baseconfig);
        break;
    }
    case LinkTypeUdp:{
        pLink = new UDPLink(baseconfig);
        break;
    }
    case LinkTypeSerial:{
        pLink = new SeriaPortLink(baseconfig);
        break;
    }
    case LinkTypeMultiCastUdp:{
        pLink = new MultiCastUDPLink(baseconfig);
        break;
    }
    case LinkTypeBroadCastUdp:{
        pLink = new BroadCastUDPLink(baseconfig);
        break;
    }
    default:{
        break;
    }
    }
    if(pLink){
        baseconfig->pLink = pLink;
        connect(pLink,&ILink::sig_recvData,[=](){
            recvLinkData(std::make_pair(baseconfig->connectType,baseconfig->linkID),pLink->readAll());
        });
    }
    return pLink;
}

QScopedPointer<LinkManager> LinkManager::m_instance;
LinkManager *LinkManager::instance()
{
    if(m_instance.isNull()){
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if(m_instance.isNull()){
            m_instance.reset(new LinkManager);
        }
    }
    return m_instance.data();
}

LinkManager::~LinkManager(){
    m_ProductQueue->deleteLater();
    m_ProductThread->exit();
    m_pConsumerThread->Stop();
    m_pConsumerThread->exit();
}

void LinkManager::initLink()
{
    ILink *pLink;
    QMutex mutex;
    QMutexLocker locker(&mutex);
    for(auto item:m_plinkconfig->getMapConfig()){
        pLink = getLinkClass(item);
        if(pLink){
            pLink->_connectLink();
        }
    }
}

void LinkManager::initConnect()
{
    connect(LinkConfig::instance(),&LinkConfig::sig_CreateNewLink,this,[&](BaseConfig* config){
        createNewLink(config);
    });
}

void LinkManager::createNewLink(BaseConfig* config){
    ILink *pLink = getLinkClass(config);
    if(pLink){
        pLink->_connectLink();
        LinkConfig::instance()->appendLinkConfig(config);
    }
}
