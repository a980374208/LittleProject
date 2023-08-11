#ifndef UDPLINK_H
#define UDPLINK_H

#include "ilink.h"
#include <QUdpSocket>



class UDPLink : public ILink
{
    Q_OBJECT
public:

    enum HostAddressType
    {
        AddressSingleCast,      ///< UDP单播
        AddressMultiCast,       ///< UDP组播
        AddressBroadCast,       ///< UDP广播
        AddressErrorCast        ///< Last type value (type >= TypeLast == invalid)
    };

    explicit UDPLink(BaseConfig* baseConfig,QObject *parent = nullptr);

    ~UDPLink() override;

    bool _connectLink() override;

    void _disconnectLink() override;

    QByteArray readAll()override;

    UDPLink::HostAddressType getAddressTypeByString(const QHostAddress  &address);

signals:


public slots:

private:

protected:
    QUdpSocket*   m_Socket = nullptr;
};

#endif // UDPLINK_H
