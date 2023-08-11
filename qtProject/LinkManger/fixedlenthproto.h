#ifndef FIXEDLENTHPROTO_H
#define FIXEDLENTHPROTO_H

#include <QObject>
#include <QQueue>
struct LinkItem{
   QByteArray arrCache;
   QQueue<QByteArray> FramDataQueue;
};
class FixedLenthProto : public QObject
{
    Q_OBJECT
public:
    explicit FixedLenthProto(QObject *parent = nullptr);

    void processingData(LinkItem& byArr);

    void processingChangeData(QQueue<QByteArray>& byArr);

signals:

public slots:

};

#endif // FIXEDLENTHPROTO_H
