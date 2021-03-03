#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Exception.h"
#include <iostream>

using namespace std;

template <class T>
class DLL {
public:
	DLL() = default;
	~DLL() {};
	void pushBack(T data);
	void pushFront(T data);
	void erase(int index);
	void Print();

private:
	class Element {
	public:
		T data;					// поле данных
		Element* nextptr{ nullptr };	// указатель на следующий элемент
		Element* prevptr{ nullptr };	// указатель на предыдущий элемент
		Element(T data, Element* nextptr = nullptr, Element* prevptr = nullptr) {
			this->data = data;
			this->nextptr = nextptr;
			this->prevptr = prevptr;
		}
	};
	int size{ 0 };						// размер даннных
	Element* head{ nullptr };			// указатель на начало списка
	Element* tail{ nullptr };			// указатель на конец списка
};



template <class T> void DLL<T>::erase(int index) {
	try {
		if ((index < 0) || (index >= size)) {
			/* Неверный индекс для удаления */
			string error = "Error: Index is out of range";
			throw Exception(ERASE_WRONG_INDEX, error);
		}
	}
	catch (Exception &ex) {
		ex.printError();
		return;
	}

	Element* temp;

	/* Если нужно стереть первый элемент */
	if (index == 0) {
		temp = head;
		head = temp->nextptr;

		delete temp;
		size--;
		return;
	}

	/* Если нужно стереть последний элемент */
	if (index == size - 1) {
		Element* tempDelete = tail;
		temp = tail;
		temp = temp->prevptr;
		temp->nextptr = nullptr;
		tail = temp;

		delete tempDelete;
		size--;
		return;
	}

	temp = head;
	for (int i = 0; i < size; i++) {
		if (i == index) {
			cout << temp->data << endl;
			Element* prev, * next;

			prev = temp->prevptr;
			next = temp->nextptr;

			prev->nextptr = temp->nextptr;
			next->prevptr = temp->prevptr;

			delete temp;
			size--;
			return;
		}
		temp = temp->nextptr;
	}
	
}


template <class T> void DLL<T>::pushFront(T data) {
	if (head == nullptr) {
		head = new Element(data);
		tail = head;
	}
	else {
		Element* temp = head;
		head = new Element(data, temp);
		temp->prevptr = head;
	}
	size++;
}


template <class T> void DLL<T>::pushBack(T data) {
	if (head == nullptr) {
		head = new Element(data, head, tail);
		tail = head;
	}
	else {
		Element* temp = tail;
		tail = new Element(data, nullptr, temp);
		temp->nextptr = tail;
	}
	size++;
}


template <class T> void DLL<T>::Print() {
	try {
		/* Попытка вывести в консоль пустой двусвязный список */
		if (head == nullptr) {
			string error = "Error: Doubly linked list is empty. Unable to print.";
			throw Exception(PRINT_EMPTY_DLL, error);
		}
	}
	catch (Exception &ex) {
		ex.printError();
		return;
	}

	Element* temp = head;
	while (temp->nextptr != nullptr) {
		cout << temp->data << " ";
		temp = temp->nextptr;
	}
	cout << temp->data << endl;
}
#endif // !DOUBLY_LINKED_LIST_H