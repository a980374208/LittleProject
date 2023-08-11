#include "CreateSerial.h"
#include "ui_CreateSerial.h"

#include <QSerialPortInfo>
CreateSerial::CreateSerial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateSerial)
{
    ui->setupUi(this);
    QStringList  serialPortList;
    QList<QSerialPortInfo> serialPortInfs = QSerialPortInfo::availablePorts();
    foreach(auto info, serialPortInfs)
    {
        serialPortList<<info.portName();
    }
    ui->serialCom->addItems(serialPortList);
}

CreateSerial::~CreateSerial()
{
    delete ui;
}

void CreateSerial::setSerialEnable(bool isEnable)
{
    ui->serialCom->setEnabled(isEnable);
    ui->rateCom->setEnabled(isEnable);
}

void CreateSerial::getSerialInf(BaseConfig     *config)
{
    config->serialPort   =   ui->serialCom->currentText();
    config->boundRate     =   LinkConfig::instance()->switchStringToBaudRate(ui->rateCom->currentText().toInt());
}
