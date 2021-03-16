#include "Institute_Worker.h"

instituteWorker::instituteWorker(const char* _surname, const char* _department, const char* _position, 
	int _birthYear, int _workExp, float _salary) {

	strcpy_s(surname, _surname);
	strcpy_s(department, _department);
	strcpy_s(position, _position);
	birthYear = _birthYear;
	workExp = _workExp;
	salary = _salary;
}



void writeData(const char* path, vector<instituteWorker>& q) {
	ofstream fout;
	fout.open(path, ofstream::app);

	for (int i = 0; i < q.size(); i++) {
		fout.write((char*)&q[i], sizeof(instituteWorker));
	}

	fout.close();
}

void readData(const char* path, vector<instituteWorker>& q) {
	ifstream fin;
	fin.open(path);
	int i{ 0 };
	instituteWorker temp;

	while (fin.read((char*)&temp, sizeof(instituteWorker))) {
		q.push_back(temp);
		i++;
	}

	fin.close();
}


istream& operator>>(istream& in, instituteWorker& item)
{
	cout << "Fulfil the information:" << endl;
	cout << " Surname: ";
	in >> item.surname;

	cout << " Department: ";
	in >> item.department;

	cout << " Position: ";
	in >> item.position;

	cout << " Birth year: ";
	in >> item.birthYear;

	cout << " Work experience: ";
	in >> item.workExp;

	cout << " Salary: ";
	in >> item.salary;

	return in;
}


ostream& operator<<(ostream& out, instituteWorker& item)
{
	out << endl << "Information about '" << item.surname << "': " << endl;
	out << " Department: " << item.department << endl;
	out << " Position: " << item.position << endl;
	out << " Birth year: " << item.birthYear << endl;
	out << " Work experience: " << item.workExp << endl;
	out << " Salary: " << item.salary << endl;

	return out;
}


void listRetirmentAge(vector<instituteWorker> q) {
	for (int i = 0; i < q.size(); i++) {
		if (2021 - q[i].birthYear >= 65) cout << q[i];
	}
}


float averageWorkExp(vector<instituteWorker> q, string _department) {
	float average = 0;
	float count = 0;

	for (int i = 0; i < q.size(); i++) {
		if (q[i].department == _department) {
			average += q[i].workExp;
			count++;
		}
	}

	cout << endl;
	return average / count;
}
