// Student.h: interface for the Student class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__551614A6_17DA_44F9_894F_6C68CA5A9F35__INCLUDED_)
#define AFX_STUDENT_H__551614A6_17DA_44F9_894F_6C68CA5A9F35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Reader.h"

class Student : public Reader
{
public:
	Student(const string& name, int clazz);
	virtual ~Student();

	int GetClass() const
	{
		return _class;
	}

private:
	int _class;

};




Student::Student(const string& name, int clazz)
	: Reader(name), _class(clazz)
{

}

Student::~Student()
{

}

#endif // !defined(AFX_STUDENT_H__551614A6_17DA_44F9_894F_6C68CA5A9F35__INCLUDED_)
