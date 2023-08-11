#ifndef TCPLINK_H
#define TCPLINK_H

#include <QObject>
#include <QTcpSocket>
#include "ilink.h"

class TcpLink : public ILink
{
    Q_OBJECT
public:
    explicit TcpLink(BaseConfig* baseConfig,QObject *parent = nullptr);

    ~TcpLink() override;

    bool _connectLink() override;

    void _disconnectLink() override;

//    void _processData() override;

    QByteArray readAll()override;

signals:

public slots:

private:
    QTcpSocket*      m_Socket = nullptr;
};

#endif // TCPLINK_H
