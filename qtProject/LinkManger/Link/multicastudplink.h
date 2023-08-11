#ifndef MULTICASTUDPLINK_H
#define MULTICASTUDPLINK_H

#include <QObject>
#include "udplink.h"

class MultiCastUDPLink : public UDPLink
{
    Q_OBJECT
public:
    explicit MultiCastUDPLink(BaseConfig* baseConfig,QObject *parent = nullptr):UDPLink(baseConfig,parent){}

    bool _connectLink() override;

    void _disconnectLink() override;

    QByteArray readAll()override;

    ~MultiCastUDPLink()override;

signals:

public slots:
private:
};

#endif // MULTICASTUDPLINK_H
