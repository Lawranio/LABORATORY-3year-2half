// IItem.h: interface for the IItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IITEM_H__E4EFABA4_D391_42E1_8C3B_C1338A8B35DE__INCLUDED_)
#define AFX_IITEM_H__E4EFABA4_D391_42E1_8C3B_C1338A8B35DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

using namespace std;

//
// Печатное издание
//
class IItem
{
public:

	// Название
	virtual string GetTitle() const = 0;

	// Стоимость
	virtual double GetPrice() const = 0;

	// Тип издания
	virtual string GetType() const = 0;

};

#endif // !defined(AFX_IITEM_H__E4EFABA4_D391_42E1_8C3B_C1338A8B35DE__INCLUDED_)
