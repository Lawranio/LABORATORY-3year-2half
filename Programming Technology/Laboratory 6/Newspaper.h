#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "IItem.h"

class Newspaper : public IItem {

public:
	Newspaper(const string& title, double price, const string& genre, const string& type)
		: _title(title), _price(price), _genre(genre), _type(type) {};
	virtual ~Newspaper() {};

	// Реализация интерфейса печатного издания
	string GetTitle() const { return _title; };

	// Реализация интерфейса печатного издания
	double GetPrice() const { return _price; };

	string GetType() const { return _type; };

	// Получить жанр газеты
	string GetGenre() const { return _genre; };


private:
	string _title;
	double _price;
	string _genre;
	string _type;
};

#endif // !NEWSPAPER_H
