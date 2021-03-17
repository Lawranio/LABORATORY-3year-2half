#ifndef BINARY_WRITE_H
#define BINARY_WRITE_H

#include "Exception.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class bin_outstream : public ofstream {
public:
	bin_outstream(const char* file) : ofstream(file, ios::app | ios::binary) {
		try {
			if (!file) {
				string error = "Error: Can't open file for writing";
				throw Exception(FILE_CANNOT_OPEN, error);
			}
		}
		catch (Exception& exp) {
			exp.printError();
		}
	}
	void writeData(int* data, int size) {
		try {
			if (!data || size <= 0) {
				string error = "Error: Write data error";
				throw Exception(FILE_ERROR, error);
			}
		}
		catch (Exception &exp) {
			exp.printError();
			return;
		}

		write((char*)data, size);
	}
	ofstream& operator<<(int data) {
		writeData(&data, sizeof(data));
		return *this;
	}
};
#endif // !BINARY_WRITE_H