#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <iostream>
#include <ctime>


int shmid;	// memory descriptor
int semid;	// semafore descriptor

sembuf Plus1 = {0, 1, 0};		// semaphore +1
sembuf Minus1 = {0, -1, 0};	// semaphore -1

const int n = 5;	// array size

int A[n][n];		// start array
int buffer[n];		// buffer
int temp;

int max;			// max element
int ind;		// index of max element

struct mymem{
	int B[n][n];	// result array
	int counter = 0;	// which string to process
};
mymem *mem;


int main() {

	srand(time(0));

	// Memory
	shmid = shmget(IPC_PRIVATE, 5000, IPC_CREAT | 0666);
	if (shmid < 0) {
		std::cout << "Error" << std::endl;
		return 0;
	}

	//Semaphore
	semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);	
	if (semid < 0) {
		std::cout << "Error" << std::endl;
		return 0;
	}
	semop(semid, &Plus1, 1);
	mem = (mymem*) shmat(shmid, NULL, 0);


	// Fill in array
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 1 + rand() % 10;
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++) {
		if (fork() == 0) {

			semop(semid, &Minus1, 1);
			for (int j = 0; j < n; j++) {
				buffer[j] = A[mem->counter][j];
			}

			max = buffer[0];

			for (int j = 1; j < n; j++) {
				if (buffer[j] > max) {
					max = buffer[j];
					ind = j;
				}
			}

			temp = buffer[mem->counter];
			buffer[mem->counter] = max;
			buffer[ind] = temp;

			for (int j = 0; j < n; j++) {
				mem->B[mem->counter][j] = buffer[j];
			}
			semop(semid, &Plus1, 1);
			mem->counter += 1;
			return 1;
		}
	}

	for (int i = 0; i < n; i++) wait(NULL);

	std::cout << std::endl << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << mem->B[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return 1;
}
