#pragma execution_character_set("utf-8")
#include "detaildialog.h"
#include "ui_detaildialog.h"
#include "Link/ilink.h"
DetailDialog::DetailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailDialog)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    ui->lab_ConnectInfo->setWordWrap(true);
    ui->lab_ConnectInfo->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

DetailDialog::~DetailDialog()
{
    delete ui;
}

void DetailDialog::setConfig(BaseConfig *config)
{
    m_pConfig = config;
    init();
}

void DetailDialog::init()
{
    setLightAndLinkStatus(m_pConfig->linkStatus,m_pConfig->linkInfo);
    ui->check_AutoConn->setChecked(m_pConfig->bAutoLink);
}

void DetailDialog::setLightAndLinkStatus(LinkStatus status, const QString &extraDes)
{
    //更新状态显示
    QString statusDes = "";
    switch (status) {
    case LinkStatus::ConnectSuccess:
    {
        statusDes = "连接成功";
        break;
    }
    case LinkStatus::DisConSuccess:
    {
        statusDes = "断开连接成功";
        break;
    }
    case LinkStatus::LinkError:
    {
        statusDes = "连接异常 - " + extraDes;
        break;
    }
    case LinkStatus::ConnectFailure:
    {
        statusDes = "连接失败";
        break;
    }
    case LinkStatus::DisConFailure:
    {
        statusDes = "断开连接失败";
        break;
    }
    default:
    {
        statusDes = "未知状态";
        break;
    }
    }
    ui->lab_ConnectInfo->setText(statusDes);
}

void DetailDialog::on_btn_Connect_clicked()
{
    if(m_pConfig->linkStatus == LinkStatus::ConnectSuccess)
    {
        return ;
    }
    m_pConfig->pLink->_connectLink();
    close();
}

void DetailDialog::on_btn_Disconnect_clicked()
{
    m_pConfig->pLink->_disconnectLink();
    close();
}

void DetailDialog::on_ButtonClose_clicked()
{
    close();
}
