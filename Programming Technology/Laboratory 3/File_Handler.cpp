#include "File_Handler.h"

fileHandler::fileHandler(const char* path, int _size) {
	try {
		file.open(path, ios::in);

		if (!file.is_open()) {
			string error = "Error: Can't open file";
			throw Exception(FILE_CANNOT_OPEN, error);
		}
	}
	catch (Exception& exp) {
		exp.printError();
		return;
	}

	string number;	// хранит число
	char ch = -1;	// хранит символ

	size = _size;
	data = new float[size];
	
	while (!file.eof()) {
		while (ch == -1 || ch == ' ' || ch == '\r' || ch == '\n' || ch == '\t') {
			file.get(ch);
			if (file.eof()) return;
		}

		if (ch == '-') {
			number += ch;
			file.get(ch);
		}

		while (getCursor(ch) != ' ') {
			if (isdigit(static_cast<unsigned char>(ch)) || ch == '.') {
				number += ch;
				file.get(ch);
			}

			if (file.eof() || ch == '\n') break;
		}

		data[count] = stof(number);

		/* Подготовка */
		if (count == 0) {
			maxValue = data[0];
			minValue = data[0];
			minValueEven = data[0];
		}
		if (count == 1) maxValueAbsOdd = abs(data[1]);


		/* Ищем максимальный и минимальный элементы */
		if (data[count] > maxValue) maxValue = data[count];
		if (data[count] < minValue) minValue = data[count];


		/* Ищем минимальный из чётных элементов */
		if (count % 2 == 0 && count != 0) {
			if (data[count] < minValueEven) minValueEven = data[count];
		}


		/* Ищем максимальный модуль с нечётными номерами */
		if (count % 2 != 0 && count != 1) {
			if (abs(data[count]) > maxValueAbsOdd) maxValueAbsOdd = abs(data[count]);
		}

		count++;
		number = "";
		file.get(ch);
	}
	file.close();
}


void fileHandler::printResult()
{
	try {
		if (data == nullptr) {
			string error = "Error: File open error, but you try to print results";
			throw Exception(PRINT_ERROR, error);
		}
	}
	catch (Exception& exp) {
		exp.printError();
		return;
	}

	cout << "Result:" << endl;
	cout << " Maximum value -> " << maxValue << endl;
	cout << " Minimum value from even elements -> " << minValueEven << endl;
	cout << " Absolute maximum value from odd elements -> " << maxValueAbsOdd << endl;
	cout << " Sum of maximum and minimum values -> " << getSum() << endl;
	cout << " Subtraction of first and last elements -> " << getSub() << endl;
}


char fileHandler::getCursor(char ch)
{
	file.seekg(-1, ios::cur);
	file.get(ch);
	return ch;
}