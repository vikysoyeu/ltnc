#include "Potion.h"



Potion::Potion()
{
	TypeOfItem = POTION;
}


Potion::~Potion()
{
}

char * Potion::GetItemName()
{
	return PotionName;
}

WeaponType Potion::GetWeaponType()
{
	return NOTWEAPON;
}

void Potion::SetMight(int Might)
{
}

void Potion::SetAccuracy(int Accuracy)
{
}

void Potion::SetCritical(int Critical)
{
}

void Potion::SetRange(int Range)
{
}

void Potion::SetWeight(int Weight)
{
}

void Potion::SetRecoverAmount(int RecoverAmount)
{
	iRecoverAmount = RecoverAmount;
}

int Potion::GetMight()
{
	return -1;
}

int Potion::GetAccuracy()
{
	return -1;
}

int Potion::GetCritical()
{
	return -1;
}

int Potion::GetRange()
{
	return -1;
}

int Potion::GetWeight()
{
	return -1;
}

int Potion::GetRecoverAmount()
{
	return iRecoverAmount;
}

void Potion::PrintItemInfo()
{
	char Buffer[30];

	sprintf(Buffer, "Durability:\t %d", iDurability);
	outtextxy(710, 50, Buffer);

	sprintf(Buffer, "Recover Amount:\t %d", iRecoverAmount);
	outtextxy(710, 70, Buffer);
}
