#include "seriaportlink.h"

SeriaPortLink::SeriaPortLink(BaseConfig *baseConfig,QObject *parent) : ILink(baseConfig,parent)
{
    m_Serial     =   new QSerialPort(this);
    /// 错误信息
    connect(m_Serial,&QSerialPort::close,this,[&](){
        setLinkStatus(LinkStatus::DisConSuccess);
    });
    connect(m_Serial,&QSerialPort::errorOccurred,this,[&](QSerialPort::SerialPortError error)
    {
        if(error == QSerialPort::NoError)
        {
            return ;
        }
        setLinkStatus(LinkStatus::LinkError,m_Serial->errorString());
    });
}

bool SeriaPortLink::_connectLink()
{
    /// 2.获取串口名字与波特率
    //QString  portName = QString::number(m_config.localPort);
    if(m_Serial==nullptr)
    {
        return false;
    }
    if(m_config->linkStatus == LinkStatus::ConnectSuccess)
    {
        return true;
    }
    /// 3.如果串口已经打开则关闭串口
    if(m_Serial->isOpen())
    {
        m_Serial->clear();
        m_Serial->close();
    }
    /// 4.打开串口
    m_Serial->setPortName(m_config->serialPort);

    switch (m_config->linkFunction) {
    case LinkFunSend:
        if(m_Serial->open(QIODevice::WriteOnly))
        {
            setLinkStatus(LinkStatus::ConnectSuccess);
            initSerialPort(m_config->boundRate);
        }
        break;
    case LinkFunReceive:
        if(m_Serial->open(QIODevice::ReadOnly))
        {
            setLinkStatus(LinkStatus::ConnectSuccess);
            initSerialPort(m_config->boundRate);
            connect(m_Serial,&QSerialPort::readyRead,this,&SeriaPortLink::sig_recvData);
        }
        break;
    case LinkFunSendRece:
        if(m_Serial->open(QIODevice::ReadWrite))
        {
            setLinkStatus(LinkStatus::ConnectSuccess);
            initSerialPort(m_config->boundRate);
            connect(m_Serial,&QSerialPort::readyRead,this,&SeriaPortLink::sig_recvData);
        }
        break;
    default:
        break;
    };
    return true;
}

QByteArray SeriaPortLink::readAll()
{
    return m_Serial->readAll();
}

void SeriaPortLink::_disconnectLink()
{
    if(!m_Serial){
        return;
    }
    if(m_Serial->isOpen())
    {
        //QObject::disconnect(mSerial,&QSerialPort::readyRead, this, &SerialLink::_handleData);
        m_Serial->close();
        setLinkStatus(LinkStatus::DisConSuccess);
    }
}

void SeriaPortLink::initSerialPort(QSerialPort::BaudRate baudRate)
{
    m_Serial->setBaudRate(baudRate,QSerialPort::AllDirections);      ///< 设置波特率和读写方向
    m_Serial->setDataBits(QSerialPort::Data8);                       ///< 设置数据位位8位
    m_Serial->setFlowControl(QSerialPort::NoFlowControl);            ///< 设置无流控制
    m_Serial->setParity(QSerialPort::NoParity);                      ///< 设置无校验位
    m_Serial->setStopBits(QSerialPort::OneStop);                    ///< 设置一位停止位
}

SeriaPortLink::~SeriaPortLink()
{
    if(m_Serial){
        m_Serial->deleteLater();
    }
}
