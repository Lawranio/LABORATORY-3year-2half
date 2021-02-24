/* ЗАДАНИЕ:

Описать двусвязный список элементов. Описать функцию удаления элемента после заданного.
Описать функции заполнения и вывода элементов.

Использовать шаблоны классов

*/

/* СПИСОК ИСКЛЮЧЕНИЙ:

	<Doubly_Linked_List.h>
1. Попытка вывести в консоль пустой двусвязный список	:: код -1
2. Неверный индекс для удаления элемента				:: код -2

	<Stack.h>
3. Достигнут максимальный размер стека
4. Попытка сделать "pop" из пустого стека

*/

#include "Doubly_Linked_List.h"
#include "Stack.h"
#include "Vehicle.h"

int main() {
	Vehicle tesla;
	tesla.Input("Tesla", 600, 155.200);

	Vehicle lada("Lada", 100, 23);
	Vehicle ford("Ford", 340, 80.499);

	Stack<Vehicle>s1;

	s1 + tesla;
	s1 + lada;
	s1 + ford;

	s1.Print();




	DLL<char> d1;

	d1.pushBack('a');
	d1.pushFront('b');

	d1.Print();

	


	cout << endl;
	return 0;
}