#ifndef BROADCASTUDPLINK_H
#define BROADCASTUDPLINK_H
#include "udplink.h"

class BroadCastUDPLink : public UDPLink
{
public:
explicit BroadCastUDPLink(BaseConfig* baseConfig,QObject *parent = nullptr):UDPLink(baseConfig,parent){}

    bool _connectLink() override;

    QByteArray readAll()override;

private:
};

#endif // BROADCASTUDPLINK_H
