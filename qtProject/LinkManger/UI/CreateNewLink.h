#ifndef CREATENEWLINK_H
#define CREATENEWLINK_H

#include <QDialog>
#include <QListWidgetItem>
#include <QList>
#include "CreateSerial.h"
#include "CreateUDPMul.h"
#include "CreateOtherLinks.h"
namespace Ui {
class CreateNewLink;
}

class CreateNewLink : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewLink(QWidget *parent = nullptr);
    ~CreateNewLink();
    void    setProtocolList     (QList<QString> protoList);
    void    setConnectedStatus  (const QString& status);

private slots:
    void on_linkTypeCom_currentIndexChanged(const QString &arg1);

    void on_linkFunCom_currentIndexChanged(const QString &arg1);

    void on_okButton_clicked();

    LinkType getLinkType(const QString linktype);

    LinkFunction getLinkFunc(const QString linktype);

    bool isMatchIPInfo(const BaseConfig *socketInfo,LinkFunction fun);

    void setBaseConfig(BaseConfig* config,const LinkFunction &linkFunc,const LinkType &linkType,const QStringList &topicName);

    void on_cancleButton_clicked();
    void on_closeButton_clicked();

signals:
    void sig_updateModel();

private:
    void                                _initListWidget      ();
    void                                _initListWidgetItem  (QListWidgetItem* item);
    void                                _setProSetGroupTitle (int loc,const QString& tit);

private:
    //自定义单元格类型，在创建单元格Item时使用
    enum ItemType                   {ItemProtocolVersion=1000};
    Ui::CreateNewLink *             ui;
    CreateSerial*                   mCreateSerialWid;
    CreateUDPMul*                   mCreateUDPMulWid;
    CreateOtherLinks*               mCreateOtherLinksWid;

    QList<QString>                  mProtocolLists;
    static  quint16                 mSUDPId;
    static  quint16                 mSSerialId;
    static  quint16                 mSTCPId;
};

#endif // CREATENEWLINK_H
