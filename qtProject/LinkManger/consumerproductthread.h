#ifndef CONSUMERPRODUCTTHREAD_H
#define CONSUMERPRODUCTTHREAD_H

#include <QMutex>
#include <QObject>
#include <QThread>
#include <qqueue.h>
#include "linkconfig.h"
#include <QWriteLocker>

struct LinkItem{
   QByteArray arrCache;
   QQueue<QByteArray> FramDataQueue;
};

class QueueProductThread : public QObject
{
    Q_OBJECT
public:
    explicit QueueProductThread();

public:
     void recvLinkData(std::pair<LinkType,QString> linkType,const QByteArray &byteArray);

signals:
private:
    QMutex m_bufMutex;
    int m_Sec;

};

class QueueConsumerThread : public QThread
{
    Q_OBJECT
public:
    explicit QueueConsumerThread();

    bool Stop() const;
    void setStop(bool newStop);

protected:
    void run() override;

signals:
    void newValue(int *data,int count,int seq);


};

#endif // CONSUMERPRODUCTTHREAD_H
