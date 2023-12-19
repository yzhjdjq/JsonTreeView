#include "jsontreemodel.h"
#include "jsonobjectmodel.h"

QObject *JsonTreeModel::objByIndex(const QModelIndex &index) const
{
    if (!index.isValid())
        return m_rootItem;
    return static_cast<QObject*>(index.internalPointer());
}

JsonTreeModel::JsonTreeModel(QObject *parent) :
    QAbstractItemModel(parent), m_rootItem(new QObject(this))
{

}

void JsonTreeModel::setColumns(const QStringList &columns)
{
    m_columns = columns;
}

void JsonTreeModel::addItem(QObject *item, const QModelIndex &parentIndex)
{
    beginInsertRows(parentIndex, rowCount(parentIndex), rowCount(parentIndex));
    item->setParent(objByIndex(parentIndex));
    endInsertRows();
}


QModelIndex JsonTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column, parent))
        return QModelIndex();
    QObject *parentObj = objByIndex(parent);
    return createIndex(row, column, parentObj->children().at(row));
}

QModelIndex JsonTreeModel::parent(const QModelIndex &child) const
{
    QObject *parentObj = objByIndex(child)->parent();
    if (parentObj == m_rootItem)
        return QModelIndex();
    QObject *grandParentObj = parentObj->parent();
    int row = grandParentObj->children().indexOf(parentObj);
    return createIndex(row, 0, parentObj);
}

int JsonTreeModel::rowCount(const QModelIndex &parent) const
{
    return objByIndex(parent)->children().count();
}

int JsonTreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_columns.count();
}

QVariant JsonTreeModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(role == Qt::DisplayRole)
        return objByIndex(index)->property(m_columns.at(index.column()).toUtf8());
    return QVariant();
}
