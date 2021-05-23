#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <iostream>

#define NUMSTACK 5000	// stack capacity

sem_t sem;     // semaphore for critical section
sem_t sem4;   // semaphore for synchronization

const int n = 3;		// amount of pairs
const int s = n * 2;	// string length
int counter;			// which pair to process
char str[s];

char stack[n][NUMSTACK];

int func(void *param) {
	sem_wait(&sem);
	str[counter] = str[counter + 1];
	counter += 2;
	sem_post(&sem);
	sem_post(&sem4);
	return 1;
}


int main() {

	std::cout << "Fill in string: ";
	for (int i = 0; i < s; i++) {
		std::cin >> str[i];
	}

	sem_init(&sem, 1, 1);
	sem_init(&sem4, 1, 0);

	for (int i = 0; i < n; i++) {
		char *tostack = stack[i];
		clone(func, (void*)(tostack + NUMSTACK -1), CLONE_VM, NULL);
	}

	for (int i = 0; i < n; i++) sem_wait(&sem4);

	std::cout << "\nPrint proccessed string: ";
	for (int i = 0; i < s; i++) {
		std::cout << str[i];
		std::cout << " ";
	}
	return 1;
}
