#include "IronBow.h"


IronBow::IronBow()
{
	WeaponName = strdup("IronBow");

	iDurability = 45;
	iMight = 6;
	iAccuracy = 85;
	iCritical = 0;
	iRange = 2;
	iWeight = 5;
}


IronBow::~IronBow()
{
}
