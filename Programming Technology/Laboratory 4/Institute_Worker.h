#ifndef INSTITUTE_WORKER_H
#define INSTITUTE_WORKER_H

#include "Exception.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class instituteWorker {
public:
	instituteWorker() = default;
	instituteWorker(const char* _surname, const char* _department, const char* _position,
		int _birthYear, int _workExp, float _salary);
	~instituteWorker() = default;

	friend void writeData(const char* path, vector<instituteWorker> &q);
	friend void readData(const char* path, vector<instituteWorker> &q);

	friend istream& operator>> (istream& in, instituteWorker& item);
	friend ostream& operator<< (ostream& out, instituteWorker& item);

	friend void listRetirmentAge(vector<instituteWorker> q);
	friend float averageWorkExp(vector<instituteWorker> q, string _department);

private:
	char	 surname[20];		// фамилия
	char	 department[50];	// отделение
	char	 position[20];	// должность
	int		 birthYear{ 0 };	// год рождения
	int		 workExp{ 0 };		// стаж работы
	float	 salary{ 0 };		// зарплата
};
#endif // !INSTITUTE_WORKER_H
