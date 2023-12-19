#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QVBoxLayout;
class QTreeView;
class JsonTreeModel;
class JsonObjectModel;

class Widget : public QWidget
{
    Q_OBJECT
    QVBoxLayout *m_mainLayout;
    QTreeView *m_treeView;
    JsonTreeModel *m_jsonTreeModel;
    QList<JsonObjectModel*> m_objects;
    void ReadJsonFile(QString path);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

};
#endif // WIDGET_H
