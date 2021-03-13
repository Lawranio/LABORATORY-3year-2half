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
	float		*data;	// ������ �����

	float		maxValue{ 0 };		 // ������������ ��������
	float		minValue{ 0 };		 // ����������� ��������
	float		minValueEven{ 0 };	 // ���������� �� �������� � ������� ��������
	float		maxValueAbsOdd{ 0 }; // ���������� �� �������� ������� � ��������� ��������

	int			size{ 0 };	// ������ ������� � �������
	int			count{ 0 };	// ���������� ��������� � �������

	char		getCursor(char ch);

	float		getSum() { return maxValue + minValue; };		// ����� ����������� � ����������
	float		getSub() { return data[0] - data[count - 1]; }; // �������� ������� � ���������� ���������
};


#endif // !FILE_HANDLER_H