#include "fixedlenthproto.h"



FixedLenthProto::FixedLenthProto(QObject *parent) : QObject(parent)
{

}
void FixedLenthProto::processingData(LinkItem& linkItem)
{
    linkItem.FramDataQueue.append("abcdcdefcdef");
    QByteArray  &byteArray = linkItem.arrCache;
    while (!linkItem.FramDataQueue.isEmpty()) {
        byteArray += linkItem.FramDataQueue.dequeue();
        if(byteArray.left(4) == "abcd"&&byteArray.right(4) == "cdef"){
            if(byteArray.count("cdef") == 2){
               byteArray.chop(byteArray.indexOf("cdef",0));
                //writeByte;
            }else{
                //writeByte;
            }
            byteArray.clear();
        }else if(byteArray.left(4) == "abcd"){
            byteArray+=linkItem.FramDataQueue.dequeue();
        }else{
            byteArray.clear();
        }
    }
}

void FixedLenthProto::processingChangeData(QQueue<QByteArray> &lstByArr)
{
    while(!lstByArr.isEmpty()){

    }
}
