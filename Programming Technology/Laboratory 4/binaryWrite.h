#ifndef BINARY_WRITE_H
#define BINARY_WRITE_H

#include "Exception.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class bin_outstream : public ofstream {
public:
	explicit bin_outstream(const char* path, int mode){
		try {
			if (mode != 0 && mode != 1) {
				string error = "Error: Incorrect mode to open file. '0' to open and '1' open with a possibility to add";
				throw Exception(INCORRECT_MODE, error);
			}
		}
		catch (Exception& exp) {
			exp.printError();
			return;
		}

		switch (mode) {
		case 0: {
			ofstream file(path, ios::out | ios::binary);
			break;
		}
		case 1:
			ofstream file(path, ios::app | ios::binary);
			break;
		}


		try {
			if (!file) {
				string error = "Error: Can't open binary file to write data";
				throw Exception(FILE_CANNOT_OPEN, error);
			}
		}
		catch (Exception& exp) {
			exp.printError();
			return;
		}
	}

	//explicit bin_outstream(const char* fn) : ofstream(fn, ios::out | ios::binary) {}

	//explicit bin_outstream(const char* fn) : ofstream(fn, ios::app | ios::binary) {}


	void writeData(const int* data, int length) {
		if (!data) return;
		if (length <= 0) return;
		write((char*)data, length);
	}
	

	ofstream& operator<<(int data) {
		writeData(&data, sizeof(data));
		return *this;
	}

	//ofstream file;
private:
	
};
#endif // !BINARY_WRITE_H