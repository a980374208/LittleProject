#include "tcplink.h"

TcpLink::TcpLink(BaseConfig *baseConfig,QObject *parent) : ILink(baseConfig,parent)
{
    m_Socket = new QTcpSocket(this);
    connect(this->m_Socket,&QTcpSocket::connected,this,[this](){
        qDebug()<<"成功和服务器建立TCP连接";
        setLinkStatus(LinkStatus::ConnectSuccess);
    });
    connect(this->m_Socket,&QTcpSocket::disconnected,this,[this](){
        qDebug()<<"成功和服务器断开TCP连接";
       setLinkStatus(LinkStatus::DisConSuccess);
    });
    /// 错误信息  error信号在5.15换了名字 error改为了errorOccurred
 #if QT_VERSION <QT_VERSION_CHECK(5,15,0)
    void (QAbstractSocket::*pSocketError) (QAbstractSocket::SocketError )=&QAbstractSocket::error;
    /// 定义信号指针
    connect(m_Socket,pSocketError,this,[&](QAbstractSocket::SocketError error) //->QAbstractSocket::SocketError
    {
        Q_UNUSED(error);
        qDebug()<<"TCP Link "<<" Error"+m_Socket->errorString();
        setLinkStatus(LinkStatus::LinkError,m_Socket->errorString());
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

TcpLink::~TcpLink()
{
    if(m_Socket){
        m_Socket->deleteLater();
    }
}

bool TcpLink::_connectLink()
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
    /// 2.获取本地与目标ip与port
    QHostAddress   localIp    = m_config->localIP;
    quint16        localPort  = m_config->localPort;
    QHostAddress   targetIp   = m_config->targetIP;
    quint16        targetPort = m_config->targetPort;
    /// 3.根据链接功能建立链接

    switch (m_config->linkFunction) {
    case LinkFunSend:
        //mSocket = new QTcpSocket(this);
        if(m_Socket->open(QIODevice::WriteOnly) == false)
        {
            break;
        }
        m_Socket->connectToHost(targetIp.toString(),targetPort,QIODevice::WriteOnly,QAbstractSocket::AnyIPProtocol);
        break;
    case LinkFunReceive:
        if(m_Socket->open(QIODevice::ReadWrite) == false)
        {
            break;
        }
        //mSocket = new QTcpSocket(this);
        m_Socket->bind(QHostAddress(localIp),localPort);
        m_Socket->connectToHost(targetIp.toString(),targetPort,QIODevice::ReadWrite,QAbstractSocket::AnyIPProtocol);
        connect(m_Socket,&QTcpSocket::readyRead,this,&TcpLink::sig_recvData);
        break;
    case LinkFunSendRece:
        if(m_Socket->open(QIODevice::ReadWrite) == false)
        {
            break;
        }
        //mSocket = new QTcpSocket(this);
        m_Socket->bind(QHostAddress(localIp),localPort);
        m_Socket->connectToHost(targetIp.toString(),targetPort,QIODevice::ReadWrite,QAbstractSocket::AnyIPProtocol);
        connect(m_Socket,&QTcpSocket::readyRead,this,&TcpLink::sig_recvData);
        break;
    default:
        break;
    };


    connect(m_Socket,&QTcpSocket::readyRead,this,&TcpLink::sig_recvData);

    if (m_Socket->waitForConnected(60 * 3 * 1000))
    {
       setLinkStatus(LinkStatus::ConnectSuccess);
    }
    return true;

}

QByteArray TcpLink::readAll()
{
    return m_Socket->readAll();
}

void TcpLink::_disconnectLink()
{
    m_Socket->close();
    m_Socket->deleteLater();
}

//void TcpLink::_processData()
//{

//}
