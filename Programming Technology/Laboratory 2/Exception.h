#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;


enum errors {
	PRINT_EMPTY_DLL,		// Попытка вывести в консоль пустой двусвязный список
	ERASE_WRONG_INDEX,		// Неверный индекс для удаления элемента
	STACK_MAX_SIZE,			// Достигнут максимальный размер стека
	STACK_EMPTY_POP,		// Попытка сделать "pop" из пустого стека
};


class Exception{
public:
	Exception(errors reason, string message) : errorReason(reason), errorMessage(message) {};
	~Exception() {};
	void printError() {
		switch (errorReason) {
		case PRINT_EMPTY_DLL: {
			cerr << errorMessage << endl;
			break;
		}
		case ERASE_WRONG_INDEX: {
			cerr << errorMessage << endl;
			break;
		}
		case STACK_MAX_SIZE: {
			cerr << errorMessage << endl << endl;
			break;
		}
		case STACK_EMPTY_POP: {
			cerr << errorMessage << endl;
			break;
		}
		}
	}

private:
	errors errorReason;
	string errorMessage;
};

#endif // !EXCEPTION_H