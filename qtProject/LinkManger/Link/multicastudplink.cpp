#include "multicastudplink.h"


//MultiCastUDPLink::MultiCastUDPLink(BaseConfig& baseConfig,QObject *parent) : UDPLink(parent),
//    m_multicastConfig(baseConfig)
//{

//}

bool MultiCastUDPLink::_connectLink()
{
    if(m_Socket==nullptr)
    {
        return false;
    }
    if(m_config->linkStatus == LinkStatus::ConnectSuccess)
    {
        return true;
    }
//    m_Socket->setSocketOption(QAbstractSocket::MulticastTtlOption,1);
//    if(m_Socket->bind(QHostAddress::AnyIPv4,m_config->localPort,QUdpSocket::ShareAddress)){
//        m_Socket->joinMulticastGroup(m_config->localIP);
//        m_Socket->open(QIODevice::ReadWrite);
//        setLinkStatus(LinkStatus::ConnectSuccess);
//        connect(m_Socket,&QUdpSocket::readyRead,this,&UDPLink::sig_recvData);
//    }
    switch (m_config->linkFunction) {
    case LinkFunSend:{
        if(m_Socket->open(QIODevice::WriteOnly))
        {
            setLinkStatus(LinkStatus::ConnectSuccess);
        }else{
            setLinkStatus(LinkStatus::ConnectFailure);
        }
        break;
    }
    case LinkFunReceive:{
        if(m_Socket->open(QIODevice::ReadOnly) == false)
        {
            setLinkStatus(LinkStatus::ConnectFailure);
        }else{
            setLinkStatus(LinkStatus::ConnectSuccess);
        }
        break;
    }
    case LinkFunSendRece:{
        if(getAddressTypeByString(m_config->targetIP)!= HostAddressType::AddressMultiCast)
        {
            qDebug()<<"UDP Link "<<" Error"<<" ip is not multicast";
            setLinkStatus(LinkStatus::LinkError,"ip地址不是广播地址");
            return false;
        }

        if(m_Socket->bind(QHostAddress::AnyIPv4,m_config->targetPort,QUdpSocket::ShareAddress)){
            m_Socket->joinMulticastGroup(m_config->targetIP);
            setLinkStatus(LinkStatus::ConnectSuccess);
            connect(m_Socket,&QUdpSocket::readyRead,this,&UDPLink::sig_recvData);
        }
        else{
            setLinkStatus(LinkStatus::ConnectFailure);
            return false;
        }
        break;
    }
    default:{
        break;
    }
    }
    return true;
}

QByteArray MultiCastUDPLink::readAll()
{
    QByteArray   datagram;
    while(m_Socket->hasPendingDatagrams())
    {
        datagram.resize(m_Socket->pendingDatagramSize());
        QHostAddress    peerAddr;
        quint16 peerPort;
        m_Socket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort);
    }
    return datagram;
}

MultiCastUDPLink::~MultiCastUDPLink()
{
    _disconnectLink();
}

void MultiCastUDPLink::_disconnectLink()
{
    if(m_Socket){
        m_Socket->disconnect();
    }
}
