/* 

Найти столбец и строку с минимальными суммами в матрице А.
Входные данные: целые положительные числа N и K, массив чисел A размерности n * k

*/

#include <iostream>
#include <ctime>

using namespace std;

int main() {
	
	const int n{ 5 };
	const int k{ 4 };
	int A[n][k];

	int min_string{ 100000 };	// минимальная сумма строки
	int min_column{ 100000 };	// минимальная сумма столбца
	int temp{ 0 };


	int index_string{ 0 };	// индекс строки с минимальной суммой
	int index_column{ 0 };	// индекс столбца с минимальной суммой

	srand(time(0));

	// i - строки, j - столбцы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			A[i][j] = 1 + rand() % 10;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	// поиск минимальной суммы в строках
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			temp = temp + A[i][j];
		}

		if (temp < min_string) {
			min_string = temp;
			index_string = i;
		}
		temp = 0;
	}

	// поиск минимальной суммы в столбцах
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			temp = temp + A[j][i];
		}

		if (temp < min_column) {
			min_column = temp;
			index_column = i;
		}
		temp = 0;
	}


	cout << endl << endl << "String: " << min_string << " and " << index_string + 1;
	cout << endl << endl << "Column: " << min_column << " and " << index_column + 1;

	cout << endl;
}