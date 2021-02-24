#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
class Stack {
public:
	Stack();
	~Stack();
	void Print();
	void Push(T data);
	void Pop();
	bool isEmpty() { return size == 0; };

	void operator+(T data) { this->Push(data); };
	void operator--() { this->Pop(); };

private:
	T*  data;				// поле данных
	int sizeMax{ 2 };		// максимальный размер массива
	int size{ 0 };			// текущий размер массива
};






template <class T> Stack<T>::Stack() {
	size = 0;
	data = new T[size];
}


template <class T> Stack<T>::~Stack() {
	delete[] data;
	data = NULL;
}


template <class T> void Stack<T>::Push(T data) {
	try {
		/* ƒостигнут максимальный размер стека */
		if ((size == sizeMax) ) throw ("Error: Maximum stack size reached. Unable to push.");
	}
	catch (const char* error) {
		cerr << error << endl << endl;
		return;
	}


	auto* newData = new T[size + 1];
	for (int i = 0; i < size; i++) {
		newData[i] = this->data[i];
	}
	newData[size] = data;
	size++;
	delete[] this->data;
	this->data = newData;
}


template <class T> void Stack<T>::Print() {
	for (int i = 0; i < size; i++) {
		cout << data[i];
	}
	cout << endl;
}


template <class T> void Stack<T>::Pop() {
	try {
		/* —тек пустой. Ќельз€ сделать pop */
		if (isEmpty() == 1) throw ("Error: Stack is empty. Unable to pop.");
	}
	catch (const char* error) {
		cerr << error << endl;
		return;
	}

	T popData = data[size - 1];
	cout << "Data to pop: " << popData << endl;

	size--;
	auto* newData = new T[size];
	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}


#endif // !STACK_H
