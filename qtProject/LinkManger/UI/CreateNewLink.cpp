#pragma execution_character_set("utf-8")
#include "CreateNewLink.h"
#include "linkmanager.h"
#include "ui_CreateNewLink.h"
//#include "SerialLink.h"
//#include "UDPLink.h"
//#include "TCPLink.h"
#include <QMessageBox>
#include <QPixmap>
#include <QBitmap>
#include <QUuid>
quint16 CreateNewLink::mSUDPId     =   1;
quint16 CreateNewLink::mSSerialId  =   1;
quint16 CreateNewLink::mSTCPId     =   1;

CreateNewLink::CreateNewLink(QWidget *parent)
    : QDialog (parent)
    , ui(new Ui::CreateNewLink)
{
    ui->setupUi(this);
    /// 1.init general setting
    //ui->autoConcheck->hide();
    ui->autoConcheck->setChecked(true);
    /// 1.1 设置默认文本
    ui->linkNameLine->setPlaceholderText("Unamed");
    /// 1.1 设置多选
    _initListWidget();
    /// 2.init one link setting
    /// 2.1 serialWid
    mCreateSerialWid = new CreateSerial(ui->proSetGroup);
    mCreateSerialWid->move(50,50);
    /// 2.2 otherLinks
    mCreateOtherLinksWid = new CreateOtherLinks(ui->proSetGroup);
    mCreateOtherLinksWid->move(50,50);
    /// 2.3udpMulti
    mCreateUDPMulWid = new CreateUDPMul(ui->proSetGroup);
    mCreateUDPMulWid->move(50,50);
    /// 2.1设置默认文本
    /// 3.默认显示串口配置界面
    on_linkTypeCom_currentIndexChanged(ui->linkTypeCom->currentText());
    ui->conStausLab->clear();
    /// 4.设置不规则界面
    //    QPixmap pixmap;
    //    pixmap.load(":/LinkMImage/newLBgk.png");
    //    setAttribute(Qt::WA_TranslucentBackground);
    //    this->resize(pixmap.size());
    //    QBitmap bitM=pixmap.mask();
    //    setMask(bitM);

}

CreateNewLink::~CreateNewLink()
{
    mCreateSerialWid->deleteLater();
    mCreateUDPMulWid->deleteLater();
    mCreateOtherLinksWid->deleteLater();
    delete ui;
}


void CreateNewLink::setProtocolList(QList<QString> protoList)
{
    mProtocolLists = protoList;
    ui->protoListW->clear();
    for(auto proto:mProtocolLists)
    {
        QListWidgetItem* item=new QListWidgetItem(ui->protoListW,ItemType::ItemProtocolVersion);
        item->setText(proto);
        _initListWidgetItem(item);
        ui->protoListW->addItem(item);
    }
}

void CreateNewLink::setConnectedStatus(const QString &status)
{
    ui->conStausLab->clear();
    ui->conStausLab->setText(status);
}


void CreateNewLink::on_linkTypeCom_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Serial")
    {
        /// 1.Serial窗口显示
        mCreateOtherLinksWid->hide();
        mCreateUDPMulWid->hide();
        mCreateSerialWid->show();

    }
    else if (arg1 == "UDP组播")
    {
        /// 1.UDPMulWid窗口显示
        mCreateOtherLinksWid->hide();
        mCreateSerialWid->hide();
        mCreateUDPMulWid->show();
    }
    else {
        /// 1.OtherLinksWid窗口显示
        mCreateSerialWid->hide();
        mCreateUDPMulWid->hide();
        mCreateOtherLinksWid->show();
    }
    /// 2.根据链接功能类型设置Serial窗口
    on_linkFunCom_currentIndexChanged(ui->linkFunCom->currentText());
    /// 3.协议设置组合框标题
    _setProSetGroupTitle(1,arg1);
}

void CreateNewLink::on_linkFunCom_currentIndexChanged(const QString &arg1)
{
    /// 1.获取linkTYpe
    QString linkType = ui->linkTypeCom->currentText();
    if(linkType == "Serial")
    {
        /// 2.1Serial窗口显示
        mCreateSerialWid->setSerialEnable(true);
    }
    else if (linkType == "UDP组播")
    {
        /// 2.2UDPMul窗口显示
        if(arg1 == "仅用于发送")
        {
            /// 2.2.1本地不可用  目标可用
            mCreateUDPMulWid->setLocalEnable(false);
            mCreateUDPMulWid->setTargetEnable(true);
        }
        else if (arg1 == "仅用于接收")
        {
            /// 2.2.1本地可用  目标不可用
            mCreateUDPMulWid->setLocalEnable(true);
            mCreateUDPMulWid->setTargetEnable(false);
        }
        else {
            /// 2.2.1本地&目标可用
            mCreateUDPMulWid->setLocalEnable(true);
            mCreateUDPMulWid->setTargetEnable(true);
        }
    }
    else {
        /// 2.3other links窗口显示
        if(arg1 == "仅用于发送")
        {
            /// 2.3.1本地不可用  目标可用
            mCreateOtherLinksWid->setLocalEnable(false);
            mCreateOtherLinksWid->setTargetEnable(true);
        }
        else if (arg1 == "仅用于接收")
        {
            if(linkType == "TCP")
            {
                mCreateOtherLinksWid->setLocalEnable(true);
                mCreateOtherLinksWid->setTargetEnable(true);
                return;
            }
            /// 2.3.1本地可用  目标不可用
            mCreateOtherLinksWid->setLocalEnable(true);
            mCreateOtherLinksWid->setTargetEnable(false);
        }
        else {
            /// 2.3.1本地&目标可用
            mCreateOtherLinksWid->setLocalEnable(true);
            mCreateOtherLinksWid->setTargetEnable(true);
        }
    }
    /// 3.协议设置组合框标题
    _setProSetGroupTitle(2,arg1);
}

void CreateNewLink::_initListWidget()
{
    /// 设置多选
    ui->protoListW->setSelectionMode(QAbstractItemView::MultiSelection);
    //ui->protoListW->setSelectionMode(QAbstractItemView::MultiSelection);
}

void CreateNewLink::_initListWidgetItem(QListWidgetItem *item)
{
    if(item==nullptr)
        return;

    //item->setCheckState(Qt::Unchecked);
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
    //设置字体大小
    //1.1设置字体
    QFont font=item->font();
    font.setFamily("微软雅黑");
    font.setBold(true);
    font.setPointSize(12);
    item->setTextColor(Qt::black);
    item->setFont(font);
}

void CreateNewLink::_setProSetGroupTitle(int loc, const QString &tit)
{
    QString tiltle = ui->proSetGroup->title();
    QStringList tiltleList = tiltle.split("-");
    if(tiltleList.size() != 3)
    {
        return;
    }
    QString newTitle;
    switch (loc) {
    case 1:
        tiltleList[0] = tit;
        newTitle = QString("%1-%2-%3").arg(tiltleList[0]).arg(tiltleList[1]).arg(tiltleList[2]);
        break;
    case 2:
        tiltleList[1] = tit;
        newTitle = QString("%1-%2-%3").arg(tiltleList[0]).arg(tiltleList[1]).arg(tiltleList[2]);
        break;
    case 3:
        tiltleList[2] = tit;
        newTitle = QString("%1-%2-%3").arg(tiltleList[0]).arg(tiltleList[1]).arg(tiltleList[2]);
        break;
    default:
        break;

    }
    ui->proSetGroup->setTitle(newTitle);
}




LinkType CreateNewLink::getLinkType(const QString linktype)
{
    if(linktype == "Serial")
    {
        return LinkTypeSerial;

    }
    else if(linktype == "TCP")
    {
        return LinkTypeTcp;
    }else if(linktype.contains("单播"))
    {
        return LinkTypeUdp;

    }
    else if (linktype.contains("组播"))
    {
        return LinkTypeBroadCastUdp;
    }
    else if(linktype.contains("广播"))
    {
        return LinkTypeMultiCastUdp;
    }
    return LinkTypeLast;
}

LinkFunction CreateNewLink::getLinkFunc(const QString linkFunc)
{
    if(linkFunc == "仅用于发送")
    {
        return LinkFunSend;

    }
    else if (linkFunc == "仅用于接收")
    {
        return LinkFunReceive;
    }
    else if(linkFunc == "即发送又接受")
    {
        return LinkFunSendRece;
    }
    return LinkFunLast;
}

void CreateNewLink::setBaseConfig(BaseConfig* config,const LinkFunction &linkFunc,const LinkType &linkType,const QStringList &topicName)
{
    config->bAutoLink = ui->autoConcheck->isChecked();
    config->linkFunction = linkFunc;
    config->linkID = QUuid::createUuid().toString();
    config->connectType = linkType;
    config->lstProtoName = topicName;
}

void CreateNewLink::on_okButton_clicked()
{

    QString         name            =   ui->linkNameLine->text();
    LinkType        linkType        =   getLinkType(ui->linkTypeCom->currentText());
    LinkFunction    linkFunc        =   getLinkFunc(ui->linkFunCom->currentText());
    QList<QListWidgetItem*>             proVersions = ui->protoListW->selectedItems();

    QString strErrorInfo;
    if(name.isEmpty()){
        strErrorInfo+="请设置链接名称\n";
    }
    if(!proVersions.size()){
        strErrorInfo+="请选择链接协议\n";
    }


    QStringList         proVList;
    for (auto proV:proVersions)
    {
        proVList<<proV->text();
    }
    BaseConfig *config = new BaseConfig;
    config->linkName = name;
    setBaseConfig(config,linkFunc,linkType,proVList);
    bool                isMatch{false};
    switch (linkType) {
    case LinkTypeSerial:     ///< Serial
        mCreateSerialWid->getSerialInf(config);
        isMatch     =   true;
        break;
//    case LinkTypeBroadCastUdp:{
//        mCreateUDPMulWid->getConfig(config);
//        isMatch =   isMatchIPInfo(config,linkFunc);
//        break;
//    }
    default:{
        mCreateOtherLinksWid->getConfig(config);
        isMatch =   isMatchIPInfo(config,linkFunc);}
        break;
    }
    if(isMatch == false)
    {
        strErrorInfo+="IP or port is invalid";
    }
    if(!strErrorInfo.isEmpty()){
        QMessageBox::information(this,"提示",strErrorInfo);
         // MSGZZ::Message::showInformation("error","IP or port is invalid",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok,this);
        return;
    }
    LinkManager::instance()->createNewLink(config);
    emit sig_updateModel();
    this->deleteLater();
}


bool CreateNewLink::isMatchIPInfo(const BaseConfig *socketInfo,LinkFunction fun)
{
    QString singleIp = "[0-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5]";
    QRegExp rxIP("^("+singleIp+")\\.("+singleIp+")\\.("+singleIp+")\\.("+singleIp+")$");
    if(rxIP.isValid() == false)
    {
        return false;
    }

    bool local = rxIP.exactMatch(socketInfo->localIP.toString());
    bool target = rxIP.exactMatch(socketInfo->targetIP.toString());
    bool isMatch{false};
    switch (fun) {
    case LinkFunSend:        ///< Serial
        isMatch = target;
        break;
    case LinkFunReceive:     ///< UDP
        isMatch = local;
        break;
    case LinkFunSendRece:     ///< TCP
        isMatch = target&&local;
        break;
    default:
        break;
    }
    return isMatch;
}


void CreateNewLink::on_cancleButton_clicked()
{
    this->deleteLater();
}

void CreateNewLink::on_closeButton_clicked()
{
    this->deleteLater();
}

