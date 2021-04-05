// PublicLibraryStrategy.h: interface for the PublicLibraryStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUBLICLIBRARYSTRATEGY_H__38B59517_9DDE_4CEA_AE86_42CC9272B22C__INCLUDED_)
#define AFX_PUBLICLIBRARYSTRATEGY_H__38B59517_9DDE_4CEA_AE86_42CC9272B22C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IDeliveryStrategy.h"

//
// Реализация стратегии определения времени владения книгой.
// В данном случае (публичная библиотека) период для 
// всех категорий читателей одинаковый. Он задается при
// создании экземпляра стратегии
//
class PublicLibraryStrategy : public IDeliveryStrategy
{
public:
	PublicLibraryStrategy(int nomianlHoldPeriod);
	virtual ~PublicLibraryStrategy();

	// Реализация метода интерфейса стратегии
	int HoldPeriod(const Reader& reader) const;

private:
	int _nomianlHoldPeriod;

};





PublicLibraryStrategy::PublicLibraryStrategy(int nomianlHoldPeriod)
	: _nomianlHoldPeriod(nomianlHoldPeriod)
{

}

PublicLibraryStrategy::~PublicLibraryStrategy()
{

}

int PublicLibraryStrategy::HoldPeriod(const Reader& reader) const
{
	// Не зависимо от категории читателя, период для всех одинаковый
	return _nomianlHoldPeriod;
}

#endif // !defined(AFX_PUBLICLIBRARYSTRATEGY_H__38B59517_9DDE_4CEA_AE86_42CC9272B22C__INCLUDED_)
