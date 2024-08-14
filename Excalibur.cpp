#include "Excalibur.h"


Excalibur::Excalibur()
{
	WeaponName = strdup("Excalibur");

	iDurability = 25;
	iMight = 18;
	iAccuracy = 90;
	iCritical = 10;
	iRange = 2;
	iWeight = 13;
}


Excalibur::~Excalibur()
{
}
