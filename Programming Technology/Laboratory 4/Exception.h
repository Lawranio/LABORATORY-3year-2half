#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;


enum errors {
	FILE_CANNOT_OPEN,		// ���� �� �����������
	FILE_ERROR,				// ������ ��� ������ � ������
};


class Exception{
public:
	Exception(errors reason, string message) : errorReason(reason), errorMessage(message) {};
	~Exception() {};
	void printError() {
		switch (errorReason) {
		case FILE_ERROR:
		case FILE_CANNOT_OPEN: {
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