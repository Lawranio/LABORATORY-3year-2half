/* First application */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctime>

using namespace std;

int main() {
	
	int fd[2];
	int B[5][5];
	int prediction[2];	// 0 - string, 1 - column;
	int received[2];	// 0 - string, 1 - column;
	bool gameOver = false;

	srand(time(0));

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			B[i][j] = 0 + rand() % 2;
			cout << B[i][j] << " ";
	}
		cout << endl;
}

	if (fd[1] = open("mypipe", O_RDONLY) == -1) cout << "Open error #1";
	if (fd[0] = open("mypipe", O_WRONLY) == -1) cout << "Open error #2";

	while (true) {
		fd[0] = open("mypipe", O_RDONLY);
		read(fd[0], received, sizeof(received));
		close(fd[0]);
		
		if (B[received[0] - 1] [received[1] - 1] == 1) {
			cout << "You lose" << endl;
			break;
		}

		cout << "\nEnter string index: ";
		cin >> prediction[0];

		cout <<"\nEnter column index: ";
		cin >> prediction[1];
		
		fd[1] = open("mypipe2", O_WRONLY);
		write(fd[1], prediction, sizeof(prediction));
		close(fd[1]);
	}
	
}
