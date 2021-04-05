#if !defined(AFX_BOOK_H__D4766295_CB7F_473E_AD58_2634A819122E__INCLUDED_)
#define AFX_BOOK_H__D4766295_CB7F_473E_AD58_2634A819122E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IItem.h"

class Book : public IItem
{
public:
	Book(const string& title, double price, const string& author);
	virtual ~Book();

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

	// Добавленный метод, специфический для книги
	string GetAuthor() const
	{
		return _author;
	}

private:
	string _title;
	double _price;
	string _author;

};






Book::Book(const string& title, double price, const string& author)
	: _title(title), _price(price), _author(author)
{
}

Book::~Book()
{

}

#endif // !defined(AFX_BOOK_H__D4766295_CB7F_473E_AD58_2634A819122E__INCLUDED_)
