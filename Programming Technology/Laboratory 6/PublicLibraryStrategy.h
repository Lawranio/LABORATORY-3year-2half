// PublicLibraryStrategy.h: interface for the PublicLibraryStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUBLICLIBRARYSTRATEGY_H__38B59517_9DDE_4CEA_AE86_42CC9272B22C__INCLUDED_)
#define AFX_PUBLICLIBRARYSTRATEGY_H__38B59517_9DDE_4CEA_AE86_42CC9272B22C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IDeliveryStrategy.h"
#include "Student.h"
#include "Lecturer.h"
#include "Engineer.h"

//
// Реализация стратегии определения времени владения книгой.
// В данном случае (публичная библиотека) период для 
// всех категорий читателей одинаковый. Он задается при
// создании экземпляра стратегии
//
class PublicLibraryStrategy : public IDeliveryStrategy
{
public:
	PublicLibraryStrategy(int studentHoldPeriod, int lecturerHoldPeriod, int engineerHoldPeriod);
	virtual ~PublicLibraryStrategy();

	// Реализация метода интерфейса стратегии
	int HoldPeriod(const Reader& reader) const;

private:
	int _studentHoldPeriod;
	int _lecturerHoldPeriod;
	int _engineerHolPeriod;

};





PublicLibraryStrategy::PublicLibraryStrategy(int studentHoldPeriod, int lecturerHoldPeriod, int engineerHoldPeriod)
	: _studentHoldPeriod(studentHoldPeriod), _lecturerHoldPeriod(lecturerHoldPeriod), _engineerHolPeriod(engineerHoldPeriod)
{

}

PublicLibraryStrategy::~PublicLibraryStrategy()
{

}

int PublicLibraryStrategy::HoldPeriod(const Reader& reader) const
{
	const Student* student = dynamic_cast<const Student*>(&reader);
	const Lecturer* lecturer = dynamic_cast<const Lecturer*>(&reader);
	const Engineer* engineer = dynamic_cast<const Engineer*>(&reader);

	if (student != NULL) return _studentHoldPeriod;
	if (lecturer != NULL) return _lecturerHoldPeriod;
	if (engineer != NULL) return _engineerHolPeriod;
}

#endif // !defined(AFX_PUBLICLIBRARYSTRATEGY_H__38B59517_9DDE_4CEA_AE86_42CC9272B22C__INCLUDED_)
