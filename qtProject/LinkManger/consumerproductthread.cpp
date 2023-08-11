#include "consumerproductthread.h"
#include <QSemaphore>
#include <QByteArray>
#include <QMap>
#include <QQueue>
#define  BufferSize 8
//int buffer1[BufferSize];
//int buffer2[BufferSize];
QMap<std::pair<LinkType,QString>,LinkItem>  buffer1;
QMap<std::pair<LinkType,QString>,LinkItem>  buffer2;

int curBuf = 1;
bool m_Stop = false;

QSemaphore emptyBufs(2);
QSemaphore fullBufs;

QueueProductThread::QueueProductThread()
{
    curBuf=1; //当前写入使用的缓冲区

    int n=emptyBufs.available();
    if (n<2)  //保证 线程启动时emptyBufs.available==2
        emptyBufs.release(2-n);
}

void QueueProductThread::recvLinkData(std::pair<LinkType, QString> linkType, const QByteArray &byteArray)
{
    emptyBufs.acquire();//获取一个空的缓冲区
    if (curBuf==1)
        buffer1[linkType].FramDataQueue.append(byteArray); //向缓冲区写入数据
    else
        buffer2[linkType].FramDataQueue.append(byteArray);
    m_bufMutex.lock();
    if (curBuf==1) // 切换当前写入缓冲区
        curBuf=2;
    else
        curBuf=1;
    m_bufMutex.unlock();
    fullBufs.release(); //有了一个满的缓冲区,available==1
}

QueueConsumerThread::QueueConsumerThread()
{

}

void QueueConsumerThread::run()
{
    m_Stop=false;//启动线程时令m_stop=false

    int n=fullBufs.available();
    if (n>0)
        fullBufs.acquire(n); //将fullBufs可用资源个数初始化为0

    while(!m_Stop)//循环主体
    {
        fullBufs.acquire(); //等待有缓冲区满,当fullBufs.available==0阻塞
        if(curBuf==1){ //当前在写入的缓冲区是1，那么满的缓冲区是2
            qDebug()<<"buff1"<<buffer1.size();
        }
        else{
            qDebug()<<"buff2"<<buffer2.size();
        }
        emptyBufs.release();//释放一个空缓冲区
    }
}

bool QueueConsumerThread::Stop() const
{
    return m_Stop;
}

void QueueConsumerThread::setStop(bool newStop)
{
    m_Stop = newStop;
}
