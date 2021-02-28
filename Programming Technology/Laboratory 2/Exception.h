#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

using namespace std;

enum errors {
	PRINT_EMPTY_DLL,		// Попытка вывести в консоль пустой двусвязный список
	ERASE_WRONG_INDEX,		// Неверный индекс для удаления элемента
	STACK_MAX_SIZE,			// Достигнут максимальный размер стека
	STACK_EMPTY_POP,		// Попытка сделать "pop" из пустого стека
};



class Exception {
public:
	Exception() = default;
	~Exception() {};
	void printError(errors error, const char* message) {
		switch (error) {
		case PRINT_EMPTY_DLL: {
			cerr << message << endl;
			exit(-1);
			break;
		}
		case ERASE_WRONG_INDEX: {
			cerr << message << endl;
			exit(-2);
			break;
		}
		case STACK_MAX_SIZE: {
			cerr << message << endl;
			break;
		}
		case STACK_EMPTY_POP: {
			cerr << message << endl;
			break;
		}
		}
	}
};

#endif // !EXCEPTION_H