// UniversityLibraryStrategy.h: interface for the UniversityLibraryStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNIVERSITYLIBRARYSTRATEGY_H__CDD8B903_6CC0_41EC_B154_E447EDBFAFEA__INCLUDED_)
#define AFX_UNIVERSITYLIBRARYSTRATEGY_H__CDD8B903_6CC0_41EC_B154_E447EDBFAFEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IDeliveryStrategy.h"
#include "Student.h"
#include "Lecturer.h"



class UniversityLibraryStrategy : public IDeliveryStrategy
{
public:
	UniversityLibraryStrategy(int averagePeriod);
	virtual ~UniversityLibraryStrategy();

	int HoldPeriod(const Reader& reader) const;

private:
	int _averagePeriod;


};




UniversityLibraryStrategy::UniversityLibraryStrategy(int averagePeriod)
	: _averagePeriod(averagePeriod)
{

}

UniversityLibraryStrategy::~UniversityLibraryStrategy()
{

}

int UniversityLibraryStrategy::HoldPeriod(const Reader& reader) const
{
	// ��� ���� ���������� ��������� ��������� ����� ������ ������� ��������
	int result = _averagePeriod;

	//
	// ����������, ������ ������ ����������� ��������: ������� ��� 
	// �������������.
	//

	const Student* student = dynamic_cast<const Student*>(&reader);
	const Lecturer* lecturer = dynamic_cast<const Lecturer*>(&reader);

	if (student != NULL)
	{
		if (student->GetClass() < 3)
		{
			// ������� ����
			result = _averagePeriod / 2;
		}
		else
		{
			// ������� ����
			result = _averagePeriod;
		}
	}
	else
	{
		if (_averagePeriod != NULL)
		{
			// ��� �������������
			result = _averagePeriod * 2;
		}
	}

	return result;
}

#endif // !defined(AFX_UNIVERSITYLIBRARYSTRATEGY_H__CDD8B903_6CC0_41EC_B154_E447EDBFAFEA__INCLUDED_)
