//#include <sys/types.h.>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

void printArray(int *array, int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}


int temp;	// for changing
int temp2;	// for B array
int pid;

int main() {

	int fd[2];
	int result;

	const int n = 5;
	int A[n][n];	// start array
	int B[n][n];	// result array
	int str[n];	// for sending
	int par_str[n];	// for receiving
	
	int max;		// max element
	int index;	// index of max element


	srand(time(0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 1 + rand() % 10;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}


	if (pipe(fd) < 0) cout << "Error: Can't create pipe" << endl << endl;

	for (int i = 0; i < n; i++) {

		if (fork() == 0) {
			close(fd[0]);
			cout << "Opened child - " << getpid() << endl;
			waitpid(getpid(), NULL, 0);
			read(fd[0], par_str, sizeof(par_str));
			

			for (int i = 0; i < n; i++) {
				B[temp][i] = str[i];
			}
			temp++;
		}

		else {
			close(fd[1]);
			for (int i = 0; i < n; i++) {
				str[i] = A[temp][i];
			}

			max = str[0];
			for (int i = 1; i < n; i++) {
				if (str[i] > max) {
					max = str[i];
					index = i;
				}
			}

			result = str[temp];
			str[temp] = max;
			str[index] = result;

			cout << "Child send - ";
			printArray(str, n);

			write(fd[1], str, sizeof(str));
			exit(0);
			return 1;
		}
	}
}
