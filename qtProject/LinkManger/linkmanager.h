#ifndef LINKMANAGER_H
#define LINKMANAGER_H

#include <QObject>
#include <QTimer>
#include "Link/ilink.h"
#include "linkconfig.h"
#include "QQueue"
#include "consumerproductthread.h"

class LinkManager : public QObject
{
    Q_OBJECT
public:
    static LinkManager* instance();

    ~LinkManager();

    void initLink();

    void initConnect();

    void recvLinkData(std::pair<LinkType,QString> linkType,const QByteArray &byteArray);

    ILink *getLinkClass(BaseConfig* baseconfig);

    void createNewLink(BaseConfig* config);

    QVector<ILink *> getLstLink() const;

    void removeLink(ILink* link,const QString& ProtoName = "");

signals:

public slots:

private:
    explicit LinkManager(QObject *parent = nullptr);
    static QScopedPointer<LinkManager> m_instance;

    LinkConfig *m_plinkconfig;

    QMap<std::pair<LinkType,QString>,QQueue<QByteArray>>  m_mapCache;

    QThread *m_ProductThread;
    QueueProductThread *m_ProductQueue;
    QueueConsumerThread *m_pConsumerThread;

    QTimer m_timer;
};

#endif // LINKMANAGER_H
