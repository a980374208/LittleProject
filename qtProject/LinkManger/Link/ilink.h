#ifndef ILINK_H
#define ILINK_H

#include <QObject>
#include <QQueue>
#include "linkconfig.h"

class ILink : public QObject
{
    Q_OBJECT
public:
    explicit ILink(BaseConfig *baseConfig,QObject *parent = nullptr);

    virtual QByteArray readAll() = 0;

    virtual bool _connectLink() = 0;

    virtual void _disconnectLink() = 0;

    virtual ~ILink();

    bool  setLinkStatus(LinkStatus status,QString extraDes = "");

    QString getConnectName();


    BaseConfig *getConfig() const;

signals:
    void sig_recvData();

public slots:

protected:
    BaseConfig*        m_config;

private:
    uint16_t m_maxCacheSize;
    QQueue<QByteArray>  m_cacheQueue;
};
Q_DECLARE_METATYPE(ILink*)
#endif // ILINK_H
