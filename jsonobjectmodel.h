#ifndef JSONOBJECTMODEL_H
#define JSONOBJECTMODEL_H

#define ID          "id"
#define NAME        "name"
#define PARENTS     "parent_ids"
#define CHILDS      "child_ids"

#include <qobject.h>


/*!
    \brief Класс, описывающий структуру одного объекта JSON-файла

    Класс-модель данных. Описывает структуру объекта JSON-файла.
    Предоставляет доступ к свойствам через метаинтерфейс QObject.
*/
class JsonObjectModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ Id NOTIFY idChanged)
    Q_PROPERTY(QString name READ Name WRITE SetName NOTIFY nameChanged)
    Q_PROPERTY(QList<int> parent_ids READ Parent_ids WRITE SetParent_ids NOTIFY parentChanged)
    Q_PROPERTY(QList<int> child_ids READ Child_ids WRITE SetChild_ids NOTIFY childrenChanged)
    int id;
    QString name;
    QList<int> parent_ids;
    QList<int> child_ids;

public:
    /*! Создает экземпляр объекта.
    \param[in] parent Родитель объекта, необходимый для построения древовидной структуры в модели.
    */
    explicit JsonObjectModel(QObject *parent = nullptr);
    JsonObjectModel(const JsonObjectModel &other): QObject(other.parent()) {};
    JsonObjectModel& operator=(const JsonObjectModel &other);
    JsonObjectModel(int id, const QString &name, QList<int> &parent_ids, QList<int> &child_ids, QObject *parent = nullptr);
    void SetJsonObjectModel(int id, const QString &name, QList<int> &parent_ids, QList<int> &child_ids);
    void SetId(int id);
    void SetName(const QString &name);
    void SetParent_ids(const QList<int> &parent_ids);
    void SetChild_ids(const QList<int> &child_ids);
    int Id() const;
    QString Name() const;
    QList<int> Parent_ids() const;
    QList<int> Child_ids() const;

Q_SIGNALS:
    void idChanged();
    void nameChanged();
    void parentChanged();
    void childrenChanged();

};

#endif // JSONOBJECTMODEL_H
