#include "treeitem.h"

#include <QAbstractItemModel>

TreeItem::TreeItem(TreeItem* parent):
    m_parent(parent),
    m_type(E_UNKNOWN),
    m_ptr(nullptr),
    m_row(-1)
{

}

TreeItem::~TreeItem()
{
    //qDeleteAll(m_children);
}

void TreeItem::addChild(TreeItem* item)
{
    item->setRow(m_children.size());
    m_children.append(item);
}

void TreeItem::removeChild()
{
    //qDeleteAll(m_children);
    m_children.clear();
}

void TreeItem::removeChild(TreeItem *item)
{
    m_children.removeOne(item);
    item->setRow(m_children.size());
    delete item;
}

void TreeItem::removeChild(int row)
{
    m_children.removeAt(row);
}

TreeItem *TreeItem::child(int row)
{
    return m_children.value(row);
}

TreeItem *TreeItem::parent()
{
    return m_parent;
}

QList<TreeItem *> TreeItem::children()
{
    return m_children;
}

int TreeItem::childCount() const
{
    return m_children.count();
}

QVariant TreeItem::data(int column) const
{
    Q_UNUSED(column);
    if(m_type == E_PROPTOITEM){
        ProtoItem* p = static_cast<ProtoItem*>(m_ptr);
        return p->m_name;
    }else if(m_type == E_LINKITEM){
        BaseConfig* p = static_cast<BaseConfig*>(m_ptr);
        return p->linkName;
    }
    return QVariant();
}

void TreeItem::setPtr(void *p)
{
    m_ptr = p;
}

void *TreeItem::ptr() const
{
    return m_ptr;
}

void TreeItem::setRow(int row)
{
    m_row = row;
}

int  TreeItem::row() const
{
    return m_row;
}

TreeItem::Type TreeItem::getType() const
{
    return m_type;
}

void TreeItem::setType(const TreeItem::Type &value)
{
    m_type = value;
}

bool TreeItem::getIsDetailRectPressed() const
{
    return m_isDetailRectPessed;
}

void TreeItem::setDetailRectIsPressed(bool isRectChecked)
{
    m_isDetailRectPessed = isRectChecked;
}

bool TreeItem::getIsSelected() const
{
    return m_isSelected;
}

void TreeItem::setIsSelecteds(bool isSelected)
{
    m_isSelected = isSelected;
    for(auto children:m_children){
        children->setIsSelected(isSelected);
    }
}

void TreeItem::setIsSelected(bool isSelected)
{
    m_isSelected = isSelected;
}

bool TreeItem::getIsSelectAll() const
{
    return m_isSelectAll;
}

void TreeItem::setIsSelectAll(bool isSelectAll)
{
    m_isSelectAll = isSelectAll;
}

bool TreeItem::getIsDelRectPessed() const
{
    return m_isDelRectPessed;
}

void TreeItem::setIsDelRectPessed(bool isDelRectPessed)
{
    m_isDelRectPessed = isDelRectPessed;
}


