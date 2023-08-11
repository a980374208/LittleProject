#include "broadcastudplink.h"


bool BroadCastUDPLink::_connectLink()
{
    /// 1.判断指针是否为空
    if(m_Socket==nullptr)
    {
        return false;
    }
    if(m_config->linkStatus == LinkStatus::ConnectSuccess)
    {
        return true;
    }

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
        if(getAddressTypeByString(m_config->localIP)!= HostAddressType::AddressBroadCast)
        {
            qDebug()<<"UDP Link "<<" Error"<<" ip is not broadcast";
            setLinkStatus(LinkStatus::LinkError,"ip地址不是广播地址");
            return false;
        }
        if(m_Socket->bind(m_config->localPort,QUdpSocket::ShareAddress))
        {
            setLinkStatus(LinkStatus::ConnectSuccess);
            connect(m_Socket,&QUdpSocket::readyRead,this,&UDPLink::sig_recvData);
            return true;
        }else {
            return false;
        }
    default:{
            break;
        }
        }
    }
    return true;
}

QByteArray BroadCastUDPLink::readAll()
{
    return m_Socket->readAll();
}
