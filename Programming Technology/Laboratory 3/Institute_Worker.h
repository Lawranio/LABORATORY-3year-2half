#ifndef INSTITUTE_WORKER_H
#define INSTITUTE_WORKER_H

#include "Exception.h"
#include <iostream>
#include <vector>

using namespace std;

class instituteWorker {
public:
	instituteWorker() = default;
	instituteWorker(string _surname, string _department, string _position,
		int _birthYear, int _workExp, float _salary);
	~instituteWorker() = default;

	friend istream& operator>> (istream& in, instituteWorker& item);
	friend ostream& operator<< (ostream& out, instituteWorker& item);

	friend void listRetirmentAge(vector<instituteWorker> q);
	friend float averageWorkExp(vector<instituteWorker> q, string _department);

private:
	string	 surname{ "" };		// �������
	string	 department{ "" };	// ���������
	string	 position{ "" };	// ���������
	int		 birthYear{ 0 };	// ��� ��������
	int		 workExp{ 0 };		// ���� ������
	float	 salary{ 0 };		// ��������
};
#endif // !INSTITUTE_WORKER_H
