#include "Fire.h"


Fire::Fire()
{
	WeaponName = strdup("Fire");

	iDurability = 40;
	iMight = 5;
	iAccuracy = 90;
	iCritical = 0;
	iRange = 2;
	iWeight = 4;
}


Fire::~Fire()
{
}
