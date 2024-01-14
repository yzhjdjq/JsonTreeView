# JsonTreeView

Проект реализует прототип оконного приложения на Qt/C++, 
которое читает древовидную структуру из JSON-файла и отображает ее в виджете QTreeView.

## Механизм работы

Класс JsonTreeModel необходим для отображения иерархических структур в QTreeView виджетах. 
В качестве входных данных использует объекты класса, унаследованного от QObject. 
Для вывода он использует его свойства, названия которых переданы в setColumns.  
В проекте реализован этот унаследованный от QObject класс JsonObjectModel. 
Он описывает необходимую структуру объекта в JSON-файле. Целевой формат JSON-файла для этого
проекта имеет такую структуру:  
```json
{
    "objects": [
	    {
		"id": 1,
		"name": "Root",
		"parent_ids": [],
		"child_ids": [2]
		},
		{
		"id": 2,
		"name": "Child",
		"parent_ids": [1],
		"child_ids": []
		}
	]
}```
Чтение JSON-файла и создание объектов JsonObjectModel происходит в конструкторе главного окна проекта.  
Построение древовидной структуры происходит за счет хранения объектов, наследников QObject, 
массивов parent и child. То есть объекты из JSON-файла в программе связаны через указатели.  

