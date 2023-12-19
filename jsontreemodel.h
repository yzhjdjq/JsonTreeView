#ifndef JSONTREEMODEL_H
#define JSONTREEMODEL_H

#include <QAbstractItemModel>

/*!
    \brief Класс пользовательской модели данных для отображения древовидных структур

    Данный класс необходим для построения модели древовидной структуры. Модель необходима для
    отображения иерархических структур в QTreeView виджетах. В качестве входных данных использует
    объекты класса, унаследованного от QObject. Для вывода он использует его свойства,
    названия которых переданы в setColumns.
*/
class JsonTreeModel : public QAbstractItemModel
{
    Q_OBJECT
    QObject *m_rootItem;
    QStringList m_columns;
    QObject* objByIndex(const QModelIndex &index) const;

public:
    JsonTreeModel(QObject *parent = nullptr);
    /*! Устанавливает названия столбцов. Значения из этого массива используются
     *  для обращения к свойствам объекта, расположенного в ячейке.
    \param[in] columns Массив названий столбцов
    */
    void setColumns(const QStringList &columns);
    /*! Добавляет объект в древовидную структуру. Если у него есть QObject().children(), то
     *  они автоматически добавляются в модель.
    \param[in] item Указатель на добавляемый объект
    \param[in] parentIndex Индекс родительского объекта. Если добавляется корневой объект, то
    родительский индекс - QModelIndex()
    */
    void addItem(QObject *item, const QModelIndex &parentIndex);
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
};

#endif // JSONTREEMODEL_H
