#include "ilink.h"

//#include <bits/std_mutex.h>
//#include <bits/unique_lock.h>

ILink::ILink(BaseConfig *baseConfig,QObject *parent) : QObject(parent),m_config(baseConfig)
{
    m_maxCacheSize =  LinkConfig::instance()->getMaxCacheSize();
}

ILink::~ILink()
{

}

bool ILink::setLinkStatus(LinkStatus status, QString extraDes)
{
    //    Q_UNUSED(extraDes)
    bool isSetSuccess = false;
    LinkStatus oldStatus = m_config->linkStatus;
    //    if(oldStatus == status)
    //    {
    //        return isSetSuccess;
    //    }
    m_config->linkInfo = extraDes;
    switch (status) {
    case LinkStatus::ConnectSuccess:
    case LinkStatus::DisConSuccess:
    case LinkStatus::LinkError:
    {
        m_config->linkStatus = status;
        isSetSuccess = true;
        break;
    }
    default:
    {
        /// 判断状态优先级
        if(oldStatus <= status)
        {
            break;
        }
        m_config->linkStatus= status;
        isSetSuccess = true;
        break;
    }
    }
    return isSetSuccess;
}

QString ILink::getConnectName()
{
    return m_config->linkName;
}

BaseConfig *ILink::getConfig() const
{
    return m_config;
}
