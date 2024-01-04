#include "jsonobjectmodel.h"

JsonObjectModel::JsonObjectModel(QObject *parent) :
    QObject(parent)
{

}

JsonObjectModel &JsonObjectModel::operator=(const JsonObjectModel &other)
{
    id = other.id;
    name = other.name;
    parent_ids = other.parent_ids;
    child_ids = other.child_ids;
    return *this;
}

JsonObjectModel::JsonObjectModel(int id, const QString &name, QList<int> &parent_ids, QList<int> &child_ids, QObject *parent) :
    QObject(parent)
{
    this->SetJsonObjectModel(id, name, parent_ids, child_ids);
}

void JsonObjectModel::SetJsonObjectModel(int id, const QString &name, QList<int> &parent_ids, QList<int> &child_ids)
{
    this->id = id;
    this->name = name;
    this->parent_ids = parent_ids;
    this->child_ids = child_ids;
}

void JsonObjectModel::SetId(int id)
{
    this->id = id;
}

void JsonObjectModel::SetName(const QString &name)
{
    this->name = name;
}

void JsonObjectModel::SetPathToIconImage(const QString &pathToIconImage)
{
    this->pathToIconImage = pathToIconImage;
}

void JsonObjectModel::SetParent_ids(const QList<int> &parent_ids)
{
    this->parent_ids = parent_ids;
}

void JsonObjectModel::SetChild_ids(const QList<int> &child_ids)
{
    this->child_ids = child_ids;
}

int JsonObjectModel::Id() const
{
    return id;
}

QString JsonObjectModel::Name() const
{
    return name;
}

QString JsonObjectModel::PathToIconImage() const
{
    return pathToIconImage;
}

QList<int> JsonObjectModel::Parent_ids() const
{
    return parent_ids;
}

QList<int> JsonObjectModel::Child_ids() const
{
    return child_ids;
}
