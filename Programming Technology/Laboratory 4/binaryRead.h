#ifndef BINARY_READ_H
#define BINARY_READ_H

#include "Exception.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class bin_instream : public ifstream {
public:
	explicit bin_instream(const char* path) : ifstream(path, ios::in | ios::binary) {}


	void readData(int* data, int length) {
		if (!data) return;
		if (length <= 0) return;
		read((char*)data, length);
	}


	bin_instream& operator>>(int& data) {
		readData(&data, sizeof(data));
		return *this;
	}

private:
	ifstream file;
};
#endif // !BINARY_READ_H