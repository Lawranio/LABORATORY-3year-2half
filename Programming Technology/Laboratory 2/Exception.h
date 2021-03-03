#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;


enum errors {
	PRINT_EMPTY_DLL,		// ������� ������� � ������� ������ ���������� ������
	ERASE_WRONG_INDEX,		// �������� ������ ��� �������� ��������
	STACK_MAX_SIZE,			// ��������� ������������ ������ �����
	STACK_EMPTY_POP,		// ������� ������� "pop" �� ������� �����
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