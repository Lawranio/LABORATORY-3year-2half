/* ЗАДАНИЕ:

Описать двусвязный список элементов. Описать функцию удаления элемента после заданного.
Описать функции заполнения и вывода элементов.

Использовать шаблоны классов

*/

/* СПИСОК ИСКЛЮЧЕНИЙ:

1. Попытка вывести в консоль пустой двусвязный список	:: код -1
2. Неверный индекс для удаления элемента				:: код -2

*/

#include "Doubly_Linked_List.h"

int main() {
	DLL<int> intList;

	intList.pushBack(2);
	intList.pushBack(3);
	intList.pushBack(4);
	intList.pushFront(5);
	intList.pushBack(7);
	intList.Print();

	intList.erase(0);

	intList.Print();

	cout << endl;
	return 0;
}