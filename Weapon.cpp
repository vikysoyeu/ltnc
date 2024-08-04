#include "Weapon.h"



Weapon::Weapon()
{
	TypeOfItem = WEAPON;
}


Weapon::~Weapon()
{
}

WeaponType Weapon::GetWeaponType()
{
	return TypeOfWeapon;
}

char * Weapon::GetItemName()
{
	return WeaponName;
}

int Weapon::GetMight()
{
	return iMight;
}

int Weapon::GetAccuracy()
{
	return iAccuracy;
}

int Weapon::GetCritical()
{
	return iCritical;
}

int Weapon::GetRange()
{
	return iRange;
}

int Weapon::GetWeight()
{
	return iWeight;
}

int Weapon::GetRecoverAmount()
{
	return -1;
}

void Weapon::SetMight(int Might)
{
	iMight = Might;
}

void Weapon::SetAccuracy(int Accuracy)
{
	iAccuracy = Accuracy;
}

void Weapon::SetCritical(int Critical)
{
	iCritical = Critical;
}

void Weapon::SetRange(int Range)
{
	iRange = Range;
}

void Weapon::SetWeight(int Weight)
{
	iWeight = Weight;
}

void Weapon::SetRecoverAmount(int RecoverAmount)
{
}

void Weapon::PrintItemInfo()
{
	char Buffer[30];
	setcolor(YELLOW);
	outtextxy(1000, 80, WeaponName);

	setcolor(WHITE);
	sprintf(Buffer, "Durability:\t %d", iDurability);
	outtextxy(1000, 120, Buffer);

	sprintf(Buffer, "Might:\t %d", iMight);
	outtextxy(1000, 160, Buffer);

	sprintf(Buffer, "Accuracy:\t %d", iAccuracy);
	outtextxy(1000, 200, Buffer);

	sprintf(Buffer, "Critical:\t %d", iCritical);
	outtextxy(1000, 240, Buffer);

	sprintf(Buffer, "Range:\t %d", iRange);
	outtextxy(1000, 280, Buffer);

	sprintf(Buffer, "Weight:\t %d", iWeight);
	outtextxy(1000, 320, Buffer);


}
