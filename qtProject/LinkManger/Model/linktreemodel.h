#ifndef LINKTREEMODEL_H
#define LINKTREEMODEL_H

#include <QAbstractItemModel>
#include "linkconfig.h"
#include "treeitem.h"


class LinkTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit LinkTreeModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setModelData(const QMap<QString,BaseConfig*> & mapConfig);

    void update();

    void insertItem(QString strProtoName,BaseConfig* config);
    void removeItem(TreeItem* item);
    void removeItems(QVector<TreeItem*> item);

    TreeItem* itemFromIndex(const QModelIndex& index)const;

    bool removeRow(int row, const QModelIndex &parent = QModelIndex());

    void insertSelect();

    void removeSelect();

private:
    TreeItem* m_rootItem;
    QStringList m_lstHeader;
    QSet<TreeItem*>  m_lstSelectItem;

    // QAbstractItemModel interface

};

#endif // LINKTREEMODEL_H
