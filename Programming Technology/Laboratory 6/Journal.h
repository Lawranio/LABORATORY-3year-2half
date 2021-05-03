// Journal.h: interface for the Journal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JOURNAL_H__9285DEEB_084E_4602_8FB0_765200D44FDF__INCLUDED_)
#define AFX_JOURNAL_H__9285DEEB_084E_4602_8FB0_765200D44FDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IItem.h"

class Journal : public IItem
{
public:
	Journal(const string& title, double price, const string& volume, const string& type);
	virtual ~Journal();

	// Реализация интерфейса печатного издания
	string GetTitle() const
	{
		return _title;
	}

	// Реализация интерфейса печатного издания
	double GetPrice() const
	{
		return _price;
	}

	string GetType() const { return _type; };

	// Получть название тома (номера) журнала. 
	// Добавленный метод, специфический для журнала
	string GetVolume() const
	{
		return _volume;
	}

private:
	string _title;
	double _price;
	string _volume;
	string _type;

};





Journal::Journal(const string& title, double price, const string& volume, const string& type)
	: _title(title), _price(price), _volume(volume), _type(type)
{

}

Journal::~Journal()
{

}

#endif // !defined(AFX_JOURNAL_H__9285DEEB_084E_4602_8FB0_765200D44FDF__INCLUDED_)
