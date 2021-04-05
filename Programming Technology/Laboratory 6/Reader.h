// Reader.h: interface for the Reader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_READER_H__ED9F6DCD_D659_48E3_BB22_931EAA24C39B__INCLUDED_)
#define AFX_READER_H__ED9F6DCD_D659_48E3_BB22_931EAA24C39B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

using namespace std;

class Reader
{
public:
	string GetName();

	virtual ~Reader();

protected:

	// Защищенный конструктор не позволит создавать объекты данного класса, 
	// но будет использоваться в классах-потомках
	Reader(const string& name);

private:
	string _name;

};





Reader::Reader(const string& name) : _name(name)
{

}

Reader::~Reader()
{

}

string Reader::GetName()
{
	return _name;
}

#endif // !defined(AFX_READER_H__ED9F6DCD_D659_48E3_BB22_931EAA24C39B__INCLUDED_)
