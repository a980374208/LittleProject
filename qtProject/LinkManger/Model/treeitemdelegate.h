#ifndef TreeItemDelegate_H
#define TreeItemDelegate_H

#include <QStyledItemDelegate>
#include <QItemDelegate>
#include <QObject>
#include <QColor>
#include <QTreeView>

class TreeItem;
class DetailDialog;
class TreeItemDelegate : public QStyledItemDelegate
{
public:
    TreeItemDelegate(QTreeView* treeView);
    ~TreeItemDelegate() override;

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;

     bool editorEvent(QEvent *event, QAbstractItemModel *model,
                      const QStyleOptionViewItem &option, const QModelIndex &index) override;
     QVector<TreeItem *> lstSelecteds() const;

     void closeDetailDialog();
private:
     QColor m_successColor;  //red
     QColor m_errorColor;  //green
     QColor m_defaultColor; //gray
     QColor m_rectPressColor;
     QTreeView* m_pTreeView;
     QVector<TreeItem*> m_lstSelecteds;
     DetailDialog* m_pDetailDia;
};

#endif // TreeItemDelegate_H
