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
// ���������� ��������� ����������� ������� �������� ������.
// � ������ ������ (��������� ����������) ������ ��� 
// ���� ��������� ��������� ����������. �� �������� ���
// �������� ���������� ���������
//
class PublicLibraryStrategy : public IDeliveryStrategy
{
public:
	PublicLibraryStrategy(int nomianlHoldPeriod);
	virtual ~PublicLibraryStrategy();

	// ���������� ������ ���������� ���������
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
	// �� �������� �� ��������� ��������, ������ ��� ���� ����������
	return _nomianlHoldPeriod;
}

#endif // !defined(AFX_PUBLICLIBRARYSTRATEGY_H__38B59517_9DDE_4CEA_AE86_42CC9272B22C__INCLUDED_)
