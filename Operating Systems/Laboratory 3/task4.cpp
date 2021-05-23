#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <iostream>
#include <ctime>

#define NUMSTACK 10000	// stack capacity

sem_t sem;		// semaphore for critical section
sem_t sem2;	// semaphore for synchronization

int start = 0;
int stop = 0;

const int n = 11;	// array size
int min;			// minimum element
int A[n];

char stack[2][NUMSTACK];

int func(void* param) {
	int status = *(int*)param;
	std::cout << "\nThread started - ";
	if (status == 0) {
		start = 0;
		stop = n / 2;
		std::cout << " first half" << std::endl;
	}

	if (status == 1) {
		start = n / 2 - 1;
		stop = n;
		std::cout << " second half" << std::endl;
	}

	sem_wait(&sem);
	for (start; start < stop; start++) {
		if (A[start] < min) min = A[start];
	}
	sem_post(&sem);
	sem_post(&sem2);
	return 1;
}


int main() {
	
	srand(time(0));
	for (int i = 0; i < n; i++) {
		A[i] = 1 + rand() % 100;
		std::cout << A[i] << " ";
	}

	min = A[0];

	sem_init(&sem, 1, 1);
	sem_init(&sem2, 1, 0);
	int param[2];

	for (int i = 0; i < 2; i++) {
		param[i] = i;
		char *tostack = stack[i];
		clone(func, (void*)(tostack + NUMSTACK -1), CLONE_VM, (void*)(param));
	}

	for (int i = 0; i < 2; i++) {
		sem_wait(&sem2);
	}
	std::cout << "\nMinimum element = " << min;
}
