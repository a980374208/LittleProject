#ifndef TREEITEM_H
#define TREEITEM_H

#include <QVariant>
#include "linkconfig.h"
class TreeItem;
typedef struct ProtoItem_t{
    QString m_name;
    QList<BaseConfig*> m_lstLink;
} ProtoItem;

class TreeItem
{
public:
    enum Type{
      E_UNKNOWN = -1,
      E_PROPTOITEM,
      E_LINKITEM
    };

    TreeItem(TreeItem* parent = nullptr);
    ~TreeItem();

    void addChild(TreeItem* item);
    void removeChild();
    void removeChild(TreeItem *item);
    void removeChild(int row);

    TreeItem* child(int row);
    TreeItem *parent();
    QList<TreeItem*> children();

    int childCount()const;

    QVariant data(int column)const;

    void setPtr(void *p);
    void* ptr()const;

    void setRow(int row);
    int row()const;

    Type getType()const;
    void setType(const Type &value);

    bool getIsDetailRectPressed() const;
    void setDetailRectIsPressed(bool isRectChecked);



    bool getIsSelected() const;
    void setIsSelecteds(bool isSelected);
    void setIsSelected(bool isSelected);


    bool getIsSelectAll() const;
    void setIsSelectAll(bool isSelectAll);

    bool getIsDelRectPessed() const;
    void setIsDelRectPessed(bool isDelRectPessed);

private:
    QList<TreeItem*> m_children;
    TreeItem* m_parent;
    Type m_type;
    void *m_ptr;
    int m_row;
    bool m_isDetailRectPessed = false;
    bool m_isDelRectPessed = false;
    bool m_isSelected = false;
    bool m_isSelectAll = false;

};

#endif // TREEITEM_H
