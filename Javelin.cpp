#include "Javelin.h"


Javelin::Javelin()
{
	WeaponName = strdup("Javelin");

	iDurability = 20;
	iMight = 6;
	iAccuracy = 65;
	iCritical = 0;
	iRange = 2;
	iWeight = 11;
}


Javelin::~Javelin()
{
}
