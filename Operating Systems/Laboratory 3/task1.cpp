#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

int shmid;	// memory descriptor
int semid;	// semafore descriptor

sembuf Plus1 = {0, 1, 0};		// semaphore +1
sembuf Minus1 = {0, -1, 0};	// semaphore -1

const int n = 3;		// amount of pairs
const int s = n * 2;	// string length

struct mymem{
	char str[s];		// our string
	int counter;			// which pair to process
};
mymem *mem;


void ProcessString(){
	// Process string

	semop(semid, &Minus1, 1);
	mem->str[mem->counter] = mem->str[mem->counter + 1];
	mem->counter += 2;
	semop(semid, &Plus1, 1);
}



int main() {

	// Memory
	shmid = shmget(IPC_PRIVATE, 100, IPC_CREAT | 0666);
	if (shmid < 0) {
		cout << "Error" << endl;
		return 0;
	}

	//Semaphore
	semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);	
	if (semid < 0) {
		cout << "Error" << endl;
		return 0;
	}
	semop(semid, &Plus1, 1);
	mem = (mymem*) shmat(shmid, NULL, 0);

	cout << "Fill in string: ";
	for (int i = 0; i < s; i++) {
		cin >> mem->str[i];
	}

	
	for (int i = 0; i < n; i++) {
		if (fork() == 0) {
			ProcessString();
			return 1;
		}
	}

	
	for (int i = 0; i < n; i++) {
		wait(NULL);
	}

	cout << "\nPrint proccessed string: ";
	for (int i = 0; i < s; i++) {
		cout << mem->str[i];
		cout << " ";
	}
	cout << "Counter - " << mem->counter << endl;

	return 1;
}