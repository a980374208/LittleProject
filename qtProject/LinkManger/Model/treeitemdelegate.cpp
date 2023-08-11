#include "treeitemdelegate.h"
#include <QPainter>
#include <QSpinBox>
#include <QDebug>
#include <linkmanager.h>
#include "linktreemodel.h"
#include "treeitem.h"
#include <QMouseEvent>
#include "ui/detaildialog.h"

TreeItemDelegate::TreeItemDelegate(QTreeView* treeView):
    m_pTreeView(treeView)
{
    m_successColor = QColor(0, 255, 0);  //red
    m_errorColor = QColor(255, 0, 0);  //green
    m_defaultColor = QColor(180, 180, 180); //gray
    m_rectPressColor = QColor(Qt::red);
    m_pDetailDia = new DetailDialog;
}

TreeItemDelegate::~TreeItemDelegate()
{
    m_pDetailDia->deleteLater();
}

void TreeItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QRect rect = option.rect;
    int nWidth = rect.width()+rect.x();
    int nHeight = rect.height();
    int nSide = qMin(nWidth,nHeight);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(0, 0);

    //画阴影
    painter->save();
    if(option.state.testFlag(QStyle::State_MouseOver)){
        painter->setPen(Qt::NoPen);
        painter->setBrush(m_defaultColor);
        painter->drawRect(option.rect);
    }
    painter->restore();

    QFontMetrics metric(painter->font());
    int fontHeight = metric.height();
    //画item
    TreeItem* item =  static_cast<TreeItem*>(index.internalPointer());
    if(item){
        if(item->getType() == TreeItem::E_PROPTOITEM){
            ProtoItem* p = static_cast<ProtoItem*>(item->ptr());
            painter->drawText(80,rect.y()+22,p->m_name);
        }else {
            BaseConfig* p = static_cast<BaseConfig*>(item->ptr());
            painter->drawText(40+40,rect.y()+fontHeight,p->linkName);
            painter->save();
            painter->setPen(Qt::NoPen);
            switch (p->linkStatus) {
            case LinkStatus::ConnectSuccess://绿色
            {
                painter->setBrush(m_successColor);
                break;
            }
            case LinkStatus::LinkError://红色
            {
                painter->setBrush(m_errorColor);
                break;
            }
            default://灰色
            {
                painter->setBrush(m_defaultColor);
                break;
            }
            }
            painter->drawEllipse(rect.x()+10,rect.y()+10/2,nSide-10,nSide-10);
            if(item->getIsDetailRectPressed()){
                painter->setBrush(Qt::green);
            }else{
                painter->setBrush(Qt::black);
            }
            QRect btnDetailRect(nWidth-55,rect.y()+5,40,20);
            painter->drawRect(btnDetailRect);
            painter->setPen(QPen(Qt::white));
            painter->drawText(btnDetailRect,Qt::AlignCenter,"详情");
            painter->restore();
            painter->save();
            if(item->getIsDelRectPessed()){
                painter->setBrush(Qt::green);
            }else{
                painter->setBrush(Qt::black);
            }
            QRect btnDelRect(nWidth-100,rect.y()+5,40,20);
            painter->drawRect(btnDelRect);
            painter->setPen(QPen(Qt::white));
            painter->drawText(btnDelRect,Qt::AlignCenter,"删除");
            painter->restore();
        }
    }
}

QSize TreeItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    TreeItem* item =  static_cast<TreeItem*>(index.internalPointer());
    if(item){
        if(item->getType() == TreeItem::E_LINKITEM){
            return QSize(option.rect.width(),30);
        }else {
            return QSize(option.rect.width(),40);
        }
    }
    return QSize(option.rect.width(),40);
}



bool TreeItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    Q_UNUSED(model)
    Q_UNUSED(option)
    qDebug()<<event->type();
    if(event->type() == QMouseEvent::MouseButtonPress){
        TreeItem* item = static_cast<TreeItem*>(index.internalPointer());
        QMouseEvent *mouse = dynamic_cast<QMouseEvent *>(event);
        if(item->getType() == TreeItem::E_LINKITEM){
            QRect checkedDetailRect;
            checkedDetailRect.setRect(option.rect.x()+option.rect.width()-55,option.rect.y()+5,40,20);
            QPoint point = mouse->pos();
            if(checkedDetailRect.contains(point)){
                item->setDetailRectIsPressed(true);
            }
            QRect checkedDelRect;
            checkedDelRect.setRect(option.rect.x()+option.rect.width()-100,option.rect.y()+5,40,20);
            if(checkedDelRect.contains(point)){
                item->setIsDelRectPessed(true);
            }
        }
        return true;
    }else if(event->type() == QMouseEvent::MouseButtonRelease){
        TreeItem* item = static_cast<TreeItem*>(index.internalPointer());
        QMouseEvent *mouse = dynamic_cast<QMouseEvent *>(event);
        if(item->getType() == TreeItem::E_LINKITEM){
            if(item->getIsDetailRectPressed()){
                QRect checkedDetailRect;
                checkedDetailRect.setRect(option.rect.x()+option.rect.width()-55,option.rect.y()+5,40,20);
                QPoint point = mouse->pos();
                if(checkedDetailRect.contains(point)){
                    m_pDetailDia->setConfig(static_cast<BaseConfig*>(item->ptr()));
                    m_pDetailDia->raise();
                    m_pDetailDia->show();
                }
            }else if(item->getIsDelRectPessed()){
                QRect checkedDetailRect(option.rect.x()+option.rect.width()-55,option.rect.y()+5,40,20);
                QPoint point = mouse->pos();
                if(checkedDetailRect.contains(point)){
                    m_pDetailDia->setConfig(static_cast<BaseConfig*>(item->ptr()));
                    m_pDetailDia->raise();
                    m_pDetailDia->show();
                }
                QRect checkedDelRect(option.rect.x()+option.rect.width()-100,option.rect.y()+5,40,20);
                if(checkedDelRect.contains(point)){
                    BaseConfig* itemCon = static_cast<BaseConfig*>(item->ptr());
                    ProtoItem* protoItem =  static_cast<ProtoItem*>(item->parent()->ptr());
                    LinkManager::instance()->removeLink(itemCon->pLink,protoItem->m_name);
                    LinkTreeModel* treeModel = static_cast<LinkTreeModel*>(model);
                    treeModel->removeRow(index.row(),index.parent());
                    treeModel->update();
                }
            }
            item->setDetailRectIsPressed(false);
            item->setIsDelRectPessed(false);
            return true;
        }
        return true;
    }
    else if(event->type() == QEvent::MouseMove){
        TreeItem* item = static_cast<TreeItem*>(index.internalPointer());
        if(item->getIsDelRectPessed()){
            QMouseEvent *mouse = dynamic_cast<QMouseEvent *>(event);
            QRect checkedDelRect(option.rect.x()+option.rect.width()-100,option.rect.y()+5,40,20);
            if(!checkedDelRect.contains(mouse->pos())){
                item->setIsDelRectPessed(false);
            }
        }else if(item->getIsDetailRectPressed()){
            QMouseEvent *mouse = dynamic_cast<QMouseEvent *>(event);
            QRect checkedDetailRect(option.rect.x()+option.rect.width()-55,option.rect.y()+5,40,20);
            if(!checkedDetailRect.contains(mouse->pos())){
                item->setDetailRectIsPressed(false);
            }
        }
    }
    return false;
}

QVector<TreeItem *> TreeItemDelegate::lstSelecteds() const
{
    return m_lstSelecteds;
}

void TreeItemDelegate::closeDetailDialog()
{
    m_pDetailDia->close();
}
