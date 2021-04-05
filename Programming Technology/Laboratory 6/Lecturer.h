// Lecturer.h: interface for the Lecturer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LECTURER_H__206173A0_0656_43C2_ABE7_A1A87AE65AF0__INCLUDED_)
#define AFX_LECTURER_H__206173A0_0656_43C2_ABE7_A1A87AE65AF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Reader.h"

class Lecturer : public Reader
{
public:
	Lecturer(const string& name, const string& position);
	virtual ~Lecturer();

	string GetPosition()
	{
		return _position;
	}

private:

	// Занимаемая должность
	string _position;
};





Lecturer::Lecturer(const string& name, const string& position)
	: Reader(name), _position(position)
{

}

Lecturer::~Lecturer()
{

}

#endif // !defined(AFX_LECTURER_H__206173A0_0656_43C2_ABE7_A1A87AE65AF0__INCLUDED_)
