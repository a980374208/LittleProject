#pragma execution_character_set("utf-8")
#include "CreateOtherLinks.h"
#include "ui_CreateOtherLinks.h"
#include <QNetworkInterface>
#include <QIntValidator>
CreateOtherLinks::CreateOtherLinks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateOtherLinks)
{
    ui->setupUi(this);

    /// 1.获取所有的本地ip
    auto          localIpList   = QNetworkInterface::allAddresses();
    QStringList   localIpStrL;
    foreach(auto ip, localIpList)
    {
        /// 1.1判断是否为ipV4
        if(!ip.isLoopback() && ip.scopeId() == "")
        {
            localIpStrL<<ip.toString();

        }
    }
    ui->localIPCom->addItems(localIpStrL);

    /// 2.设置port输入范围
    QRegExp rx("^([1-9])|[1-9]\\d|[1-9]\\d{2}|[1-9]\\d{3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5]$");
    QRegExpValidator*    validator  =   new     QRegExpValidator(rx,this);
    ui->localPortLine->setValidator(validator);
    ui->tarPortLine->setValidator(validator);

    /// 3.设置IP输入范围
    QString singleIp = "[0-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5]";
    QRegExp rxIP("^("+singleIp+")\\.("+singleIp+")\\.("+singleIp+")\\.("+singleIp+")$");
    if(rxIP.isValid())
    {
        //qDebug()<<"createOtherLInk rxIP.isValid()";
    }
    QRegExpValidator*    ipValidator  =   new     QRegExpValidator(rxIP,this);
    ui->tarIPLine->setValidator(ipValidator);
    /// 4.设置默认显示值
    ui->localPortLine->setPlaceholderText("例(7044)");
    ui->tarIPLine->setPlaceholderText("例(224.0.0.22)");
    ui->tarPortLine->setPlaceholderText("例(7044)");
}

CreateOtherLinks::~CreateOtherLinks()
{
    delete ui;
}

void CreateOtherLinks::setLocalEnable(bool isEnable)
{
    ui->localIPCom->setEnabled(isEnable);
    ui->localPortLine->setEnabled(isEnable);
    _setLocalStyle(isEnable);
}

void CreateOtherLinks::setTargetEnable(bool isEnable)
{
    ui->tarIPLine->setEnabled(isEnable);
    ui->tarPortLine->setEnabled(isEnable);
    _setTargetStyle(isEnable);
}

void CreateOtherLinks::setConfig(const BaseConfig &linkIpPort)
{
    int localIPCount = ui->localIPCom->count();
    for (int i=0;i<localIPCount;i++)
    {
        if(ui->localIPCom->itemText(i) == linkIpPort.localIP.toString())
        {
            ui->localIPCom->setCurrentIndex(i);
            break;
        }
    }
    ui->localPortLine->setText(QString::number(linkIpPort.localPort));
    ui->tarIPLine->setText(linkIpPort.targetIP.toString());
    ui->tarPortLine->setText(QString::number(linkIpPort.targetPort));
}

void CreateOtherLinks::getConfig(BaseConfig *linkData)
{
    linkData->localIP    =   ui->localIPCom->currentText();
    linkData->localPort  =   ui->localPortLine->text().toInt();
    linkData->targetIP   =   ui->tarIPLine->text();
    linkData->targetPort =   ui->tarPortLine->text().toInt();
}

void CreateOtherLinks::_setLocalStyle(bool isEnable)
{
    if(isEnable)
    {
        ui->localIPCom->setStyleSheet(R"(QComboBox#localIPCom
                                      {
                                      background-color: rgb(85, 85, 255);
                                      border:1px solid white;
                                      border-radius:3px;
                                      }
                                      QComboBox#localIPCom QAbstractItemView
                                      {
                                      background-color: rgb(85, 170, 255);
                                      selection-background-color:green;

                                      })");
        ui->localPortLine->setStyleSheet("QLineEdit#localPortLine{border:1px solid blue; color: black;background: transparent}");
        return;
    }
    ui->localIPCom->setStyleSheet(R"(QComboBox#localIPCom
                                  {
                                  background: transparent;
                                  /*
                                  border:1px solid white;
                                  border-radius:3px;*/
                                  }
                                  QComboBox#localIPCom QAbstractItemView
                                  {
                                  background-color: rgb(39, 39, 39);
                                  selection-background-color:green;

                                  })");
    ui->localPortLine->setStyleSheet("QLineEdit#localPortLine{color: black;background: transparent}");
}

void CreateOtherLinks::_setTargetStyle(bool isEnable)
{
    if(isEnable)
    {
        ui->tarIPLine->setStyleSheet("QLineEdit#tarIPLine{border:1px solid blue; color: black;background: transparent}");
        ui->tarPortLine->setStyleSheet("QLineEdit#tarPortLine{border:1px solid blue; color: black;background: transparent}");
        return;
    }
    ui->tarIPLine->setStyleSheet("QLineEdit#tarIPLine{color: black;background: transparent}");
    ui->tarPortLine->setStyleSheet("QLineEdit#tarPortLine{color: black;background: transparent}");
}
