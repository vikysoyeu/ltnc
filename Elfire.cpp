#include "Elfire.h"


Elfire::Elfire()
{
	WeaponName = strdup("Elfire");

	iDurability = 30;
	iMight = 10;
	iAccuracy = 85;
	iCritical = 0;
	iRange = 2;
	iWeight = 10;
}


Elfire::~Elfire()
{
}
