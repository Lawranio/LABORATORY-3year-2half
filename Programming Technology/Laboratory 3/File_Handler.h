#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "Exception.h"
#include <math.h>
#include <fstream>
#include <iostream>

using namespace std;


class fileHandler {
public:
	explicit fileHandler(const char* path, int _size);
	~fileHandler() { delete[] data; data = NULL; };
	void printResult();

private:
	ifstream	file;
	float		*data;	// хранит числа

	float		maxValue{ 0 };		 // максимальное значение
	float		minValue{ 0 };		 // минимальное значение
	float		minValueEven{ 0 };	 // наименьшее из значений с чётными номерами
	float		maxValueAbsOdd{ 0 }; // наибольшее из значений модулей с нечётными номерами

	int			size{ 0 };	// размер массива с числами
	int			count{ 0 };	// количество элементов в массиве

	char		getCursor(char ch);

	float		getSum() { return maxValue + minValue; };		// сумма наибольшего и наменьшего
	float		getSub() { return data[0] - data[count - 1]; }; // разность первого и последнего элементов
};


#endif // !FILE_HANDLER_H