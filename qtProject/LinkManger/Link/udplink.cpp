#include "udplink.h"

UDPLink::UDPLink(BaseConfig* baseConfig,QObject *parent) : ILink(baseConfig,parent)
{
    m_Socket = new QUdpSocket(this);

    ///错误信息  error信号在5.15换了名字 error改为了errorOccurred
#if QT_VERSION <QT_VERSION_CHECK(5,15,0)
    void (QAbstractSocket::*pSocketError) (QAbstractSocket::SocketError )=&QAbstractSocket::error;
    //定义信号指针
    connect(m_Socket,pSocketError,this,[&](QAbstractSocket::SocketError error) //->QAbstractSocket::SocketError
    {
        Q_UNUSED(error);
        qDebug()<<"UDP Link "<<" Error"+m_Socket->errorString();
        setLinkStatus(LinkStatus::LinkError,m_Socket->errorString());
        // emit connectedError(mUdpConfig->getLinkType(),mUdpConfig->getLinkID(),mUdpConfig->getConfigName(),mSocket->errorString());
    });
#else
    void (QAbstractSocket::*pSocketError) (QAbstractSocket::SocketError )=&QAbstractSocket::errorOccurred;
    connect(m_Socket,pSocketError,this,[&](QAbstractSocket::SocketError error) //->QAbstractSocket::SocketError
    {
        Q_UNUSED(error);
        qDebug()<<"socketError"+m_Socket->errorString();
    });
#endif
}

UDPLink::~UDPLink(){
    if(m_Socket){
        m_Socket->deleteLater();
    }
}

bool UDPLink::_connectLink()
{
    if(m_Socket==nullptr)
    {
        return false;
    }
    if(m_config->linkStatus == LinkStatus::ConnectSuccess)
    {
        return true;
    }
    if(m_Socket->isOpen())
    {
        m_Socket->close();
    }

    switch (m_config->linkFunction) {
    case LinkFunSend:
        //mSocket = new QUdpSocket(this);
        if(m_Socket->open(QIODevice::WriteOnly))
        {
            setLinkStatus(LinkStatus::ConnectSuccess);
        }else{
            setLinkStatus(LinkStatus::ConnectFailure);
        }
        break;
    case LinkFunReceive:
        if(m_Socket->open(QIODevice::ReadOnly) == false)
        {
            setLinkStatus(LinkStatus::ConnectFailure);
        }else{
            setLinkStatus(LinkStatus::ConnectSuccess);
        }
        break;
    case LinkFunSendRece:{
        if(getAddressTypeByString(m_config->localIP) !=HostAddressType::AddressSingleCast)
        {
            qDebug()<<"UDP Link "<<" Error"<<" ip is not singlecast";
            setLinkStatus(LinkStatus::LinkError,"ip地址不是单播地址");
        }
        if(m_Socket->bind(m_config->localIP,m_config->localPort))
        {
            setLinkStatus(LinkStatus::ConnectSuccess);
            connect(m_Socket,&QUdpSocket::readyRead,this,&UDPLink::sig_recvData);
        }else {
            setLinkStatus(LinkStatus::ConnectFailure);
        }
        break;
    }
    default:
        break;
    }
    return true;
}

UDPLink::HostAddressType UDPLink::getAddressTypeByString(const QHostAddress &address)
{
    HostAddressType addreeType = HostAddressType::AddressErrorCast;
    if(address.isNull() == true)
    {
        addreeType = HostAddressType::AddressErrorCast;
        return HostAddressType::AddressErrorCast;
    }
    if(address.isBroadcast())
    {
        addreeType = HostAddressType::AddressBroadCast;
    }
    else if (address.isMulticast()) {
        addreeType = HostAddressType::AddressMultiCast;
    }
    else {
        addreeType = HostAddressType::AddressSingleCast;
    }
    return addreeType;
}

void UDPLink::_disconnectLink()
{

}

QByteArray UDPLink::readAll()
{
    return m_Socket->readAll();
}
