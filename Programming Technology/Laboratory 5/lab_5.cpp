#include <iostream>
#include "Computer.h"
#include "Сompany.h"

int main()
{
	Manufacturer amd("AMD", "Malaysia", "86-25-1");
	Manufacturer intel("Intel", "USA", "525-15");
	Distributor dns("DNS", "Russia", "904-652");

	amd.CreateComputer();
	amd.CreateComputer();

	intel.CreateComputer();

	dns.GetComputer(amd);
	dns.GetComputer(amd);
	dns.GetComputer(intel);

	dns.SellComputer();
	dns.SellComputer();
	dns.SellComputer();


}