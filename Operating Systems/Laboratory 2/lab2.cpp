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

pid_t pid, wpid;
int status = 0;

const int n = 5;

int A[n][n];		// start array
int B[n][n];		// result array
int str[n];		// for sending
int par_str[n];	// for receiving

int main() {

	int fd[2];
	int result;
	
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


	for (int i = 0; i < n; i++) {
		if (pipe(fd) < 0) cout << "Error: Can't create pipe" << endl << endl;

		pid = fork();

		if (pid < 0) {
			cout << "Error: Can't fork" << endl;
			exit(1);
		}

		if (pid == 0) {

			//cout << "Parent received - " << endl;
			read(fd[0], &par_str, sizeof(par_str));
			//printArray(par_str, n);
			//cout << endl;

			for (int i = 0; i < n; i++) {
				B[temp][i] = par_str[i];
			}
			temp++;

			waitpid(pid, NULL, 0);
		}
		else {
			
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

			//cout << "Child send - ";
			//printArray(str, n);

			write(fd[1], &str, sizeof(str));
			exit(0);

		}
	}

	cout << "\nDone" << endl;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
}
