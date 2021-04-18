/* 

Найти столбец и строку с минимальными суммами в матрице А.
Входные данные: целые положительные числа N и K, массив чисел A размерности n * k

*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	
	int fd[2], result;
	size_t size;
	int msg_num{ 1 };
	int msg_num_child{ 1 };

	const int n{ 5 };
	const int k{ 4 };
	int A[n][k];
	int B[n][k];

	int min_string{ 100000 };	// минимальная сумма строки
	int min_column{ 100000 };	// минимальная сумма столбца
	int temp{ 0 };

	int index_string{ 0 };	// индекс строки с минимальной суммой
	int index_column{ 0 };	// индекс столбца с минимальной суммой

	srand(time(0));

	/* Pipe create */
	if (pipe(fd) < 0) {
		cout << "Error: Can't create pipe" << endl << endl;
	}

	/* New process */
	result = fork();

	if (result > 0) {
		close(fd[0]);
		for (int i = 0; i < 3; i++) {
			// i - строки, j - столбцы
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < k; j++) {
					A[i][j] = 1 + rand() % 10;
					cout << A[i][j] << " ";
				}
				cout << endl;
			}
			cout << "Parent sent a message #" << msg_num << endl;
			msg_num++;
			write(fd[1], *A, sizeof(A));
			cout << endl;
		}
		
		close (fd[1]);
		cout << "Parent exit" << endl << endl;
	}
	else {
		close(fd[1]);
		for (int i = 0; i < 3; i++) {
			read(fd[0], *B, sizeof(B));
			cout << "\nChild received a message #" << msg_num_child << endl;
			msg_num_child++;

			// поиск минимальной суммы в строках
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < k; j++) {
					temp = temp + B[i][j];
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
					temp = temp + B[j][i];
				}

				if (temp < min_column) {
					min_column = temp;
					index_column = i;
				}
				temp = 0;
			}


			cout << endl << "String: " << min_string << " and " << index_string + 1;
			cout << endl << "Column: " << min_column << " and " << index_column + 1;

			cout << endl;
		}
		
		cout << "\nChild exit";
		close(fd[0]);
	}

	
	cout << endl;
}