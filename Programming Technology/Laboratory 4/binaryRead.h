#ifndef BINARY_READ_H
#define BINARY_READ_H

#include "Exception.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class bin_instream : public ifstream {
public:
	bin_instream(const char* file) : ifstream(file, ios::in | ios::binary) {
		try {
			if (!file) {
				string error = "Error: Can't open file for reading";
				throw Exception(FILE_CANNOT_OPEN, error);
			}
		}
		catch (Exception& exp) {
			exp.printError();
		}
	}
	void readData(int* data, int size) {
		try {
			if (!data || size <= 0) {
				string error = "Error: Read data error";
				throw Exception(FILE_ERROR, error);
			}
		}
		catch (Exception& exp) {
			exp.printError();
			return;
		}

		read((char*)data, size);
	}
	bin_instream& operator>>(int& data) {
		readData(&data, sizeof(data));
		return *this;
	}
};
#endif // !BINARY_READ_H