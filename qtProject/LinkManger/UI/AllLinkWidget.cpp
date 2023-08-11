#include "AllLinkWidget.h"
#include "ui_AllLinkWidget.h"
#include "Link/ilink.h"

#include <linkmanager.h>

AllLinkWidget::AllLinkWidget(QWidget *parent)
    :  QDialog(parent)
    ,  ui                     (new Ui::AllLinkWidget)
//    ,  mActionType            (AllLinkWidget::ActionType::UnknowType)
    ,  mCurProtocol           ("")
//    ,  mAddLinkFun            (nullptr)
//   ,  mDelLinksCallBack      (nullptr)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    _initListWidget();
}

void AllLinkWidget::showAllLinkListWid(QVector<ILink *> allLink)
{
    ui->allLinkListW->clear();

    for(auto link:allLink)
    {
        QListWidgetItem*    item = new QListWidgetItem(ui->allLinkListW);
        if(link == nullptr)
        {
            break;
        }
        item->setText(link->getConnectName());
        item->setData(Qt::UserRole,QVariant::fromValue(link));
//        item
        _initListWidgetItem(item);
        ui->allLinkListW->addItem(item);
    }
}

//void AllLinkWidget::setActionType(AllLinkWidget::ActionType type, const QString &protoVersion)
//{
//    mActionType  = type;
//    mCurProtocol = protoVersion;
//}

//void AllLinkWidget::setAddLinksCallBack(AllLinkWidget::AddProtocolLinkCallBack addCallBack)
//{
//    mAddLinkFun = addCallBack;
//}

//void AllLinkWidget::setDelLinksCallBack(AllLinkWidget::DelLinksCallBack addCallBack)
//{
//    mDelLinksCallBack = addCallBack;
//}

AllLinkWidget::~AllLinkWidget()
{
    delete ui;
}

void AllLinkWidget::on_okBtn_clicked()
{
    QList<QListWidgetItem*> selectItems = ui->allLinkListW->selectedItems();
    if(selectItems.size() == 0)
    {
        this->deleteLater();
        return;
    }

    for(auto item : selectItems)
    {
        ILink* link = item->data(Qt::UserRole).value<ILink*>();
        LinkManager::instance()->removeLink(link);
    }
    emit sig_delSuccess();
    this->deleteLater();
}

void AllLinkWidget::on_cancleBtn_clicked()
{
    this->deleteLater();
}

void AllLinkWidget::on_ButtonClose_clicked()
{
    this->deleteLater();
}

void AllLinkWidget::_initListWidget()
{
    ui->allLinkListW->setSelectionMode(QAbstractItemView::MultiSelection);
}

void AllLinkWidget::_initListWidgetItem(QListWidgetItem *item)
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


