#include "CreateUDPMul.h"
#include "ui_CreateUDPMul.h"
#include <QIntValidator>
#include <QRegExp>
#include <QRegExpValidator>
CreateUDPMul::CreateUDPMul(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateUDPMul)
{
    ui->setupUi(this);
    /// 1.设置端口输入范围
    //QRegExp rxPort("^([1-9])|[1-9]\\d|[1-9]\\d{2}|[1-9]\\d{3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5]$");
    QRegExp rxPort("^([1-9])|[1-9]\\d|[1-9]\\d{2}|[1-9]\\d{3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5]$");
    QRegExpValidator*    portValidator  =   new     QRegExpValidator(rxPort,this);
    ui->localPortLine->setValidator(portValidator);
    ui->tarPortLine->setValidator(portValidator);
    /// 2..设置IP输入范围
    QString singleIp = "[0-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5]";
    QRegExp rxIP("^("+singleIp+")\\.("+singleIp+")\\.("+singleIp+")\\.("+singleIp+")$");
    if(rxIP.isValid())
    {
        //qDebug()<<"createOtherLInk rxIP.isValid()";
    }
    QRegExpValidator*    ipValidator  =   new     QRegExpValidator(rxIP,this);
    ui->tarIPLine->setValidator(ipValidator);
    ui->localIPLine->setValidator(ipValidator);
    /// 3.ip地址端口号默认值
    ui->localIPLine->setPlaceholderText("例(224.0.0.22)");
    ui->localPortLine->setPlaceholderText("例(7044)");
    ui->tarIPLine->setPlaceholderText("例(224.0.0.22)");
    ui->tarPortLine->setPlaceholderText("例(7044)");
}

CreateUDPMul::~CreateUDPMul()
{
    delete ui;
}

void CreateUDPMul::setLocalEnable(bool isEnable)
{
    ui->localIPLine->setEnabled(isEnable);
    ui->localPortLine->setEnabled(isEnable);
    _setLocalStyle(isEnable);
}

void CreateUDPMul::setTargetEnable(bool isEnable)
{
    ui->tarIPLine->setEnabled(isEnable);
    ui->tarPortLine->setEnabled(isEnable);
    _setTargetStyle(isEnable);
}

void CreateUDPMul::setConfig(const BaseConfig &config)
{
    ui->localIPLine->setText(config.localIP.toString());
    ui->localPortLine->setText(QString::number(config.localPort));
    ui->tarIPLine->setText(config.targetIP.toString());
    ui->tarPortLine->setText(QString::number(config.targetPort));
}

void CreateUDPMul::getConfig(BaseConfig* config)
{
    qDebug()<<ui->localIPLine->text()<<ui->tarIPLine->text();
    config->localIP   =   ui->localIPLine->text();
    config->localPort  =   ui->localPortLine->text().toInt();
    config->targetIP = ui->tarIPLine->text();
    config->targetPort =   ui->tarPortLine->text().toInt();
    qDebug()<<config->localIP.toString()<<config->targetIP.toString();

}

void CreateUDPMul::_setTargetStyle(bool isEnable)
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

void CreateUDPMul::_setLocalStyle(bool isEnable)
{
    if(isEnable)
    {
        ui->localIPLine->setStyleSheet("QLineEdit#localIPLine{border:1px solid blue; color: black;background: transparent}");
        ui->localPortLine->setStyleSheet("QLineEdit#localPortLine{border:1px solid blue; color: black;background: transparent}");
        return;
    }
    ui->localIPLine->setStyleSheet("QLineEdit#localIPLine{color: black;background: transparent}");
    ui->localPortLine->setStyleSheet("QLineEdit#localPortLine{color: black;background: transparent}");
}
