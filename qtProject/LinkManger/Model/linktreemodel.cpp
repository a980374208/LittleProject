#include "linktreemodel.h"

LinkTreeModel::LinkTreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    m_rootItem = new TreeItem(nullptr);
    m_lstHeader<<"proto";
}

QVariant LinkTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal){
        if(role == Qt::DisplayRole){
            return m_lstHeader.at(section);
        }
    }
    return QVariant();
}

QModelIndex LinkTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row,column,parent)){
        return QModelIndex();
    }
    TreeItem* parentItem = itemFromIndex(parent);
    TreeItem* item = parentItem->child(row);
    if(item){
        return createIndex(row,column,item);
    }else{
        return QModelIndex();
    }
}

QModelIndex LinkTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();
    TreeItem* item = itemFromIndex(index);
    TreeItem* parentItem = item->parent();
    if(parentItem == m_rootItem)
        return QModelIndex();
    if(parentItem){
        return createIndex(parentItem->row(),0,parentItem);
    }else{
        return QModelIndex();
    }
}

int LinkTreeModel::rowCount(const QModelIndex &parent) const
{
    if(parent.column()>0)
        return 0;
    TreeItem* item = itemFromIndex(parent);
    return item->childCount();
}

int LinkTreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_lstHeader.size();
}

QVariant LinkTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    TreeItem* item = itemFromIndex(index);
    if(role == Qt::DisplayRole){
        return item->data(index.row());
    }
    return QVariant();
}

void LinkTreeModel::setModelData(const QMap<QString,BaseConfig*> &mapConfig)
{
    QMap<QString,QList<BaseConfig*>> mapTmp;
    for(auto item:mapConfig){
        for (auto parentItem:item->lstProtoName) {
            mapTmp[parentItem].append(item);
        }
    }
    beginResetModel();
    m_rootItem->removeChild();
    auto iter = mapTmp.begin();
    for(;iter!=mapTmp.end();++iter){
        ProtoItem* pro = new ProtoItem();
        pro->m_name = iter.key();
        //m_rootItem->setPtr(pro);

        TreeItem* proItem = new TreeItem(m_rootItem);
        proItem->setType(TreeItem::E_PROPTOITEM);
        proItem->setPtr(pro);
        m_rootItem->addChild(proItem);
        pro->m_lstLink.append(iter.value());
        for(auto link:iter.value()){
            TreeItem* linkItem = new TreeItem(proItem);
            linkItem->setPtr(link);
            linkItem->setType(TreeItem::E_LINKITEM);
            proItem->addChild(linkItem);
        }
    }
    endResetModel();
}

void LinkTreeModel::update()
{
    emit dataChanged(QModelIndex(),QModelIndex());
}

void LinkTreeModel::insertItem(QString strProtoName, BaseConfig *config)
{
    beginResetModel();
    for(int i = 0;i<m_rootItem->childCount();++i){
        ProtoItem* p = static_cast<ProtoItem*>(m_rootItem->child(i)->ptr());
        if(p->m_name == strProtoName){
            TreeItem* linkItem = new TreeItem(m_rootItem->child(i));
            linkItem->setPtr(config);
            linkItem->setType(TreeItem::E_LINKITEM);
            m_rootItem->child(i)->addChild(linkItem);
        }
    }
    endResetModel();
}

void LinkTreeModel::removeItem(TreeItem *item)
{
    //    beginResetModel();
    item->parent()->removeChild(item);
    //    endResetModel();
}

void LinkTreeModel::removeItems(QVector<TreeItem *> lstItem)
{
    QList<BaseConfig*> lstConfig;
    beginResetModel();
    for(auto item:lstItem){
        if(item->getType() == TreeItem::E_PROPTOITEM){
            for (auto it:item->children()) {
                lstConfig.append(static_cast<BaseConfig*>(it->ptr()));
            }
        }else{
            lstConfig.append(static_cast<BaseConfig*>(item->ptr()));
        }
        removeItem(item);
    }
    endResetModel();
}

TreeItem *LinkTreeModel::itemFromIndex(const QModelIndex &index) const
{
    if (index.isValid())
        return static_cast<TreeItem*>(index.internalPointer());
    return m_rootItem;
}

bool LinkTreeModel::removeRow(int row, const QModelIndex &parent)
{
    if(!parent.isValid())
        return false;
    beginRemoveRows(parent, row, row);
    QSignalBlocker blocker(this);
    TreeItem *itm = static_cast<TreeItem*>(parent.internalPointer());
    if(itm){
        itm->removeChild(row);
    }
    blocker.unblock();
    endRemoveRows();
//    if(!itm->childCount()&&m_rootItem->childCount()){
//        removeRow(itm->row(),createIndex(row,0,itm->parent()));
//    }
    return true;
}
