#include "Character.h"



void Character::Promote()
{
	iMaxHP += 2;
	iStrength += 2;
	iMagic += 2;
	iSkill += 2;
	iSpeed += 2;
	iLuck += 2;
	iDefense += 2;
	iResistance += 2;

	iHP = iMaxHP;
}

void Character::BreakWeapon()
{
	for (int i = 0; i < Inventory.size(); i++)
	{
		if (Inventory[i] == EquippedWeapon)
		{
			delete(EquippedWeapon);

			Inventory.erase(Inventory.begin() + i);
		}
	}

	for (int i = 0; i < Inventory.size(); i++)
	{
		for (int j = 0; j < UsableWeapon.size(); j++)
		{
			if (Inventory[i]->GetWeaponType() == UsableWeapon[j])
			{
				EquippedWeapon = Inventory[i];

				return;
			}
		}
	}
}

int Character::GetAttackPower()
{
	switch (EquippedWeapon->GetWeaponType())
	{
	case AXE:
	case BOW:
	case LANCE:
	case SWORD:
		return EquippedWeapon->GetMight() + this->iStrength;
	case ANIMA:
	case DARK:
	case LIGHT:
		return EquippedWeapon->GetMight() + this->iMagic;
	}
}

int Character::GetAttackSpeed()
{
	if (iStrength >= EquippedWeapon->GetWeight())
	{
		return iSpeed;
	}
	else
	{
		return (iStrength - EquippedWeapon->GetWeight()) + iSpeed;
	}
}

int Character::GetHitRate()
{
	return EquippedWeapon->GetAccuracy() + 2 * iSkill + iLuck / 2;
}

int Character::GetEvade()
{
	return 2 * iSpeed + iLuck;
}

int Character::GetCritical()
{
	int iCritical = EquippedWeapon->GetCritical() + iSkill / 2;

	if (this->CharacterClass == MYRMIDON && this->IsPromoted == true)
	{
		iCritical += 15;
	}

	if (this->CharacterClass == PIRATE && this->IsPromoted == true)
	{
		iCritical += 15;
	}

	return iCritical;
}

int Character::GetCriticalEvade()
{
	return iLuck;
}

bool Character::IsWeaponTriangleWon(Character *Enemy)
{
	if (this->EquippedWeapon == NULL || Enemy->EquippedWeapon == NULL)
	{
		return false;
	}

	switch (this->EquippedWeapon->GetWeaponType())
	{
	case SWORD:
		if (Enemy->EquippedWeapon->GetWeaponType() == AXE)
		{
			return true;
		}

		break;

	case AXE:
		if (Enemy->EquippedWeapon->GetWeaponType() == LANCE)
		{
			return true;
		}

		break;

	case LANCE:
		if (Enemy->EquippedWeapon->GetWeaponType() == SWORD)
		{
			return true;
		}

		break;

	case ANIMA:
		if (Enemy->EquippedWeapon->GetWeaponType() == LIGHT)
		{
			return true;
		}

		break;

	case LIGHT:
		if (Enemy->EquippedWeapon->GetWeaponType() == DARK)
		{
			return true;
		}

		break;

	case DARK:
		if (Enemy->EquippedWeapon->GetWeaponType() == ANIMA)
		{
			return true;
		}

		break;
	}

	return false;
}

bool Character::IsWeaponTriangleLost(Character *Enemy)
{
	if (this->EquippedWeapon == NULL || Enemy->EquippedWeapon == NULL)
	{
		return false;
	}

	switch (this->EquippedWeapon->GetWeaponType())
	{
	case SWORD:
		if (Enemy->EquippedWeapon->GetWeaponType() == LANCE)
		{
			return true;
		}

		break;
	case AXE:
		if (Enemy->EquippedWeapon->GetWeaponType() == SWORD)
		{
			return true;
		}

		break;
	case LANCE:
		if (Enemy->EquippedWeapon->GetWeaponType() == AXE)
		{
			return true;
		}

		break;
	case ANIMA:
		if (Enemy->EquippedWeapon->GetWeaponType() == DARK)
		{
			return true;
		}

	case LIGHT:
		if (Enemy->EquippedWeapon->GetWeaponType() == ANIMA)
		{
			return true;
		}

		break;
	case DARK:
		if (Enemy->EquippedWeapon->GetWeaponType() == LIGHT)
		{
			return true;
		}

		break;
	}

	return false;
}

bool Character::IsSelfDoubleStrikePossible(Character * Enemy)
{
	if (this->iSpeed > Enemy->iSpeed + 4)
	{
		return true;
	}

	return false;
}

bool Character::IsEnemyDoubleStrikePossible(Character * Enemy)
{
	if (Enemy->iSpeed > this->iSpeed + 4)
	{
		return true;
	}

	return false;
}

int Character::GetFinalAttackPower(Character * Enemy)
{
	int iFinalAttackPower = this->GetAttackPower();

	if (IsWeaponTriangleWon(Enemy))
	{
		iFinalAttackPower += 1;
	}

	if (IsWeaponTriangleLost(Enemy))
	{
		iFinalAttackPower -= 1;
	}

	switch (this->EquippedWeapon->GetWeaponType())
	{
	case AXE:
	case BOW:
	case LANCE:
	case SWORD:
		iFinalAttackPower -= Enemy->iDefense;
		break;

	case ANIMA:
	case LIGHT:
	case DARK:
		iFinalAttackPower -= Enemy->iResistance;
		break;
	}

	return iFinalAttackPower;
}

int Character::GetFinalHitRate(Character * Enemy)
{
	int iFinalHitRate = this->GetHitRate() - Enemy->GetEvade();

	if (IsWeaponTriangleWon(Enemy) == true)
	{
		iFinalHitRate += 15;
	}

	if (IsWeaponTriangleLost(Enemy) == true)
	{
		iFinalHitRate -= 15;
	}

	return iFinalHitRate;
}

int Character::GetFinalCritical(Character * Enemy)
{
	return this->GetCritical() - Enemy->GetCriticalEvade();
}

void Character::Strike(Character * Enemy)
{
	bool IsHit = RandomNumberGenerator::IsSucceeded(GetFinalHitRate(Enemy));
	bool IsCritical = RandomNumberGenerator::IsSucceeded(GetFinalCritical(Enemy));
	int iDamage = this->GetFinalAttackPower(Enemy);

	if (IsHit == false)
	{
		cout << sName << " misses" << endl;

		IncreaseExp(1);
		return;
	}

	if (IsCritical == true)
	{
		cout << sName << " deals a critical hit" << endl;

		iDamage *= 3;
	}

	Enemy->iHP -= iDamage;

	cout << this->sName << " deals " << iDamage << " damage to " << Enemy->sName << endl;

	if (Enemy->iHP < 0)
	{
		Enemy->iHP = 0;
	}

	IncreaseExp(10);
}

void Character::CheckRight(vector<Coordinate>& MovableCoordinates, int MoveCount, int X, int Y, vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap)
{
	Coordinate Check(X + 1, Y);

	if (Check.iX > MAP_WIDTH || Check.iY > MAP_HEIGHT || Check.iX < 1 || Check.iY < 1)
	{
		return;
	}

	if (StageMap.GetTerrain(X + 1, Y)->GetMovementCost() > MoveCount || (CharacterAbility == FLYING && MoveCount > 1))
	{
		return;
	}

	for (int i = 0; i < EnemyList.size(); i++)
	{
		if (EnemyList[i]->Position.iX == Check.iX && EnemyList[i]->Position.iY == Check.iY)
		{
			return;
		}
	}

	for (int i = 0; i < AllyList.size(); i++)
	{
		if (AllyList[i]->Position.iX == Check.iX && AllyList[i]->Position.iY == Check.iY)
		{
			if (CharacterAbility == FLYING)
			{
				CheckRight(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckUp(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckDown(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
			}
			else
			{
				CheckRight(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X + 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckUp(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X + 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckDown(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X + 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
			}

			return;
		}
	}

	MovableCoordinates.push_back(Check);

	if (CharacterAbility == FLYING)
	{
		CheckRight(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckUp(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckDown(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
	}
	else
	{
		CheckRight(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X + 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckUp(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X + 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckDown(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X + 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
	}
}

void Character::CheckLeft(vector<Coordinate>& MovableCoordinates, int MoveCount, int X, int Y, vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap)
{
	Coordinate Check(X - 1, Y);

	if (Check.iX > MAP_WIDTH || Check.iY > MAP_HEIGHT || Check.iX < 1 || Check.iY < 1)
	{
		return;
	}

	if (StageMap.GetTerrain(X - 1, Y)->GetMovementCost() > MoveCount || (CharacterAbility == FLYING && MoveCount > 1))
	{
		return;
	}

	for (int i = 0; i < EnemyList.size(); i++)
	{
		if (EnemyList[i]->Position.iX == Check.iX && EnemyList[i]->Position.iY == Check.iY)
		{
			return;
		}
	}

	for (int i = 0; i < AllyList.size(); i++)
	{
		if (AllyList[i]->Position.iX == Check.iX && AllyList[i]->Position.iY == Check.iY)
		{
			if (CharacterAbility == FLYING)
			{
				CheckLeft(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckUp(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckDown(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
			}
			else
			{
				CheckLeft(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X - 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckUp(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X - 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckDown(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X - 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
			}

			return;
		}
	}

	MovableCoordinates.push_back(Check);

	if (CharacterAbility == FLYING)
	{
		CheckLeft(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckUp(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckDown(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
	}
	else
	{
		CheckLeft(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X - 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckUp(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X - 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckDown(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X - 1, Y)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
	}
}

void Character::CheckUp(vector<Coordinate>& MovableCoordinates, int MoveCount, int X, int Y, vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap)
{
	Coordinate Check(X, Y - 1);

	if (Check.iX > MAP_WIDTH || Check.iY > MAP_HEIGHT || Check.iX < 1 || Check.iY < 1)
	{
		return;
	}

	if (StageMap.GetTerrain(X, Y - 1)->GetMovementCost() > MoveCount || (CharacterAbility == FLYING && MoveCount > 1))
	{
		return;
	}

	for (int i = 0; i < EnemyList.size(); i++)
	{
		if (EnemyList[i]->Position.iX == Check.iX && EnemyList[i]->Position.iY == Check.iY)
		{
			return;
		}
	}

	for (int i = 0; i < AllyList.size(); i++)
	{
		if (AllyList[i]->Position.iX == Check.iX && AllyList[i]->Position.iY == Check.iY)
		{
			if (CharacterAbility == FLYING)
			{
				CheckLeft(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckRight(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckUp(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
			}
			else
			{
				CheckLeft(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y - 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckRight(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y - 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckUp(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y - 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
			}

			return;
		}
	}

	MovableCoordinates.push_back(Check);

	if (CharacterAbility == FLYING)
	{
		CheckLeft(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckRight(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckUp(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
	}
	else
	{
		CheckLeft(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y - 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckRight(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y - 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckUp(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y - 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
	}
}

void Character::CheckDown(vector<Coordinate>& MovableCoordinates, int MoveCount, int X, int Y, vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap)
{
	Coordinate Check(X, Y + 1);

	if (Check.iX > MAP_WIDTH || Check.iY > MAP_HEIGHT || Check.iX < 1 || Check.iY < 1)
	{
		return;
	}

	if (StageMap.GetTerrain(X, Y + 1)->GetMovementCost() > MoveCount || (CharacterAbility == FLYING && MoveCount > 1))
	{
		return;
	}

	for (int i = 0; i < EnemyList.size(); i++)
	{
		if (EnemyList[i]->Position.iX == Check.iX && EnemyList[i]->Position.iY == Check.iY)
		{
			return;
		}
	}

	for (int i = 0; i < AllyList.size(); i++)
	{
		if (AllyList[i]->Position.iX == Check.iX && AllyList[i]->Position.iY == Check.iY)
		{
			if (CharacterAbility == FLYING)
			{
				CheckLeft(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckRight(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckDown(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
			}
			else
			{
				CheckLeft(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y + 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckRight(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y + 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
				CheckDown(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y + 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
			}

			return;
		}
	}

	MovableCoordinates.push_back(Check);

	if (CharacterAbility == FLYING)
	{
		CheckLeft(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckRight(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckDown(MovableCoordinates, MoveCount - 1, Check.iX, Check.iY, EnemyList, AllyList, StageMap);
	}
	else
	{
		CheckLeft(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y + 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckRight(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y + 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
		CheckDown(MovableCoordinates, MoveCount - (StageMap.GetTerrain(X, Y + 1)->GetMovementCost()), Check.iX, Check.iY, EnemyList, AllyList, StageMap);
	}
}

void Character::LevelUp()
{
	iLevel++;

	if (RandomNumberGenerator::IsSucceeded(iHPGrowth) == true)
	{
		iMaxHP++;
	}

	if (RandomNumberGenerator::IsSucceeded(iStrengthGrowth) == true)
	{
		iStrength++;
	}

	if (RandomNumberGenerator::IsSucceeded(iMagicGrowth) == true)
	{
		iMagic++;
	}

	if (RandomNumberGenerator::IsSucceeded(iSkillGrowth) == true)
	{
		iSkill++;
	}

	if (RandomNumberGenerator::IsSucceeded(iSpeedGrowth) == true)
	{
		iSpeed++;
	}

	if (RandomNumberGenerator::IsSucceeded(iLuckGrowth) == true)
	{
		iLuck++;
	}

	if (RandomNumberGenerator::IsSucceeded(iDefenseGrowth) == true)
	{
		iDefense++;
	}

	if (RandomNumberGenerator::IsSucceeded(iResistanceGrowth) == true)
	{
		iResistance++;
	}

	if (iLevel == 20 && IsPromoted == false)
	{
		Promote();
	}

	iHP = iMaxHP;
}

int Character::GetDistance(Coordinate Position1, Coordinate Position2)
{
	int iDistance = 0;

	if (Position1.iX > Position2.iX)
	{
		iDistance += Position1.iX - Position2.iX;
	}
	else
	{
		iDistance += Position2.iX - Position1.iX;
	}

	if (Position1.iY > Position2.iY)
	{
		iDistance += Position1.iY - Position2.iY;
	}
	else
	{
		iDistance += Position2.iY - Position1.iY;
	}

	return iDistance;
}


Character::Character()
{
	IsPromoted = false;

	iExp = 0;
	iLevel = 1;

	CharacterAbility = NONE;

	EquippedWeapon = NULL;

	CharacterStatus = ACTIVE;
}


Character::~Character()
{
}

void Character::SetName(char * Name)
{
	sName = strdup(Name);
}

bool Character::ObtainItem(Item *ObtainedItem)
{
	if (Inventory.size() == 4)
	{
		return false;
	}
	else
	{
		Inventory.push_back(ObtainedItem);

		return true;
	}
}

void Character::DiscardItem(int InventorySlot)
{
	Inventory.erase(Inventory.begin() + InventorySlot - 1);
}

bool Character::EquipWeapon(int InventorySlot)
{
	if (Inventory[InventorySlot]->GetItemType() == WEAPON)
	{
		for (int i = 0; i < UsableWeapon.size(); i++)
		{
			if (Inventory[InventorySlot]->GetWeaponType() == UsableWeapon[i])
			{
				EquippedWeapon = Inventory[InventorySlot];
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

int Character::GetInventorySlots()
{
	return Inventory.size();
}

Class Character::GetCharacterClass()
{
	return CharacterClass;
}

Item * Character::GetEquippedWeapon()
{
	return EquippedWeapon;
}

void Character::Attack(Character * Enemy)
{
	system("CLS");

	cout << this->sName << " is attacking " << Enemy->sName << endl;

	bool IsCounterPossible = Enemy->IsAttackable(this);

	int iSelfDurability = this->EquippedWeapon->GetDurability();
	int iEnemyDurability = this->EquippedWeapon->GetDurability();

	this->Strike(Enemy);

	iSelfDurability--;
	
	if (Enemy->iHP == 0)
	{
		this->IncreaseExp(30);

		if (this->EquippedWeapon != NULL)
		{
			this->EquippedWeapon->SetDurability(iSelfDurability);
		}

		if (Enemy->EquippedWeapon != NULL)
		{
			Enemy->EquippedWeapon->SetDurability(iEnemyDurability);
		}

		Enemy->CharacterStatus = DEAD;

		return;
	}

	if (IsCounterPossible == true)
	{
		Enemy->Strike(this);

		iEnemyDurability--;

		if (this->iHP == 0)
		{
			Enemy->IncreaseExp(30);

			if (this->EquippedWeapon != NULL)
			{
				this->EquippedWeapon->SetDurability(iSelfDurability);
			}

			if (Enemy->EquippedWeapon != NULL)
			{
				Enemy->EquippedWeapon->SetDurability(iEnemyDurability);
			}

			this->CharacterStatus = DEAD;

			return;
		}

		if (IsEnemyDoubleStrikePossible(Enemy) == true && iEnemyDurability > 0)
		{
			Enemy->Strike(this);

			iEnemyDurability--;

			if (this->iHP == 0)
			{
				Enemy->IncreaseExp(30);

				if (this->EquippedWeapon != NULL)
				{
					this->EquippedWeapon->SetDurability(iSelfDurability);
				}

				if (Enemy->EquippedWeapon != NULL)
				{
					Enemy->EquippedWeapon->SetDurability(iEnemyDurability);
				}

				this->CharacterStatus = DEAD;

				return;
			}
		}
	}

	if (IsSelfDoubleStrikePossible(Enemy) == true && iSelfDurability > 0)
	{
		this->Strike(Enemy);

		iSelfDurability--;

		if (Enemy->iHP == 0)
		{
			this->IncreaseExp(30);

			if (this->EquippedWeapon != NULL)
			{
				this->EquippedWeapon->SetDurability(iSelfDurability);
			}

			if (Enemy->EquippedWeapon != NULL)
			{
				Enemy->EquippedWeapon->SetDurability(iEnemyDurability);
			}

			Enemy->CharacterStatus = DEAD;

			return;
		}
	}

	if (this->EquippedWeapon != NULL)
	{
		this->EquippedWeapon->SetDurability(iSelfDurability);
	}

	if (Enemy->EquippedWeapon != NULL)
	{
		Enemy->EquippedWeapon->SetDurability(iEnemyDurability);
	}

	if (iSelfDurability <= 0 && this->EquippedWeapon != NULL)
	{
		this->BreakWeapon();
	}

	if (iEnemyDurability <= 0 && Enemy->EquippedWeapon != NULL)
	{
		Enemy->BreakWeapon();
	}
}

void Character::Dance(Character * Ally)
{
	if (CharacterAbility == DANCE)
	{
		Ally->CharacterStatus = ACTIVE;

		Ally->Draw();
	}
}

void Character::Heal(Character * Ally)
{
	Ally->iHP += this->iMagic;
	if (Ally->iHP > Ally->iMaxHP)
	{
		Ally->iHP = Ally->iMaxHP;
	}
}

void Character::UseVulnerary()
{
	for (int i = 0; i < Inventory.size();i++)
	{
		if (Inventory[i]->GetRecoverAmount() == 10)
		{
			UseItem(i);
		}
	}
}

void Character::UseElixir()
{
	for (int i = 0; i < Inventory.size(); i++)
	{
		if (Inventory[i]->GetRecoverAmount() == 20)
		{
			UseItem(i);
		}
	}
}

bool Character::UseItem(int InventorySlot)
{
	if (Inventory[InventorySlot]->GetItemType() == POTION)
	{
		this->iHP += Inventory[InventorySlot]->GetRecoverAmount();

		if (iHP > iMaxHP)
		{
			iHP = iMaxHP;
		}

		Inventory[InventorySlot]->SetDurability(Inventory[InventorySlot]->GetDurability() - 1);

		if (Inventory[InventorySlot]->GetDurability() == 0)
		{
			delete(Inventory[InventorySlot]);

			Inventory.erase(Inventory.begin() + InventorySlot);
		}

		return true;
	}

	return false;
}

bool Character::IsAttackable(Character *Enemy)
{
	if (EquippedWeapon == NULL)
	{
		return false;
	}

	if (EquippedWeapon->GetWeaponType() == BOW)
	{
		if (GetDistance(this->Position, Enemy->Position) >= 2 && GetDistance(this->Position, Enemy->Position) <= EquippedWeapon->GetRange())
		{
			return true;
		}
	}
	else
	{
		if (GetDistance(this->Position, Enemy->Position) <= EquippedWeapon->GetRange())
		{
			return true;
		}
	}

	return false;
}

bool Character::IsHealable(Character *Ally)
{
	if (GetDistance(this->Position, Ally->Position) == 1)
	{
		return true;
	}

	return false;
}

bool Character::IsDancable(Character *Ally)
{
	if (GetDistance(this->Position, Ally->Position) == 1 && Ally->CharacterStatus==MOVED)
	{
		return true;
	}

	return false;
}

vector<Coordinate> Character::GetMovableCoordinates(vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap)
{
	vector <Coordinate> MovableCoordinates;

	MovableCoordinates.push_back(Position);

	CheckRight(MovableCoordinates, iMovement, Position.iX, Position.iY, EnemyList, AllyList, StageMap);
	CheckLeft(MovableCoordinates, iMovement, Position.iX, Position.iY, EnemyList, AllyList, StageMap);
	CheckUp(MovableCoordinates, iMovement, Position.iX, Position.iY, EnemyList, AllyList, StageMap);
	CheckDown(MovableCoordinates, iMovement, Position.iX, Position.iY, EnemyList, AllyList, StageMap);

	for (int i = 0; i < MovableCoordinates.size(); i++)
	{
		for (int j = i + 1; j < MovableCoordinates.size(); j++)
		{
			if (MovableCoordinates[i].iX == MovableCoordinates[j].iX && MovableCoordinates[i].iY == MovableCoordinates[j].iY)
			{
				MovableCoordinates.erase(MovableCoordinates.begin() + j);
				j--;
			}
		}
	}

	return MovableCoordinates;
}

vector<Character*> Character::GetAttackableEnemies(vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap, vector <Coordinate> MovableCoordinates)
{
	vector <Character*> AttackableEnemies;

	if (this->EquippedWeapon == NULL)
	{
		return AttackableEnemies;
	}

	for (int i = 0; i < MovableCoordinates.size(); i++)
	{
		for (int j = 0; j < EnemyList.size(); j++)
		{
			if (EquippedWeapon->GetWeaponType() == BOW)
			{
				if (GetDistance(MovableCoordinates[i], EnemyList[j]->Position) >= 2 && GetDistance(MovableCoordinates[i], EnemyList[j]->Position) <= EquippedWeapon->GetRange())
				{
					AttackableEnemies.push_back(EnemyList[j]);
				}
			}
			else
			{
				if (GetDistance(MovableCoordinates[i], EnemyList[j]->Position) <= EquippedWeapon->GetRange())
				{
					AttackableEnemies.push_back(EnemyList[j]);
				}
			}
		}
	}

	for (int i = 0; i < AttackableEnemies.size(); i++)
	{
		for (int j = i + 1; j < AttackableEnemies.size(); j++)
		{
			if (AttackableEnemies[i] == AttackableEnemies[j])
			{
				AttackableEnemies.erase(AttackableEnemies.begin() + j);
				j--;
			}
		}
	}

	return AttackableEnemies;
}

vector<Character*> Character::GetHealableAllies(vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap, vector <Coordinate> MovableCoordinates)
{
	vector <Character*> HealableAllies;

	if(this->CharacterAbility!=HEAL)
	{
		return HealableAllies;
	}

	for (int i = 0; i < MovableCoordinates.size(); i++)
	{
		for (int j = 0; j < AllyList.size(); j++)
		{
			if (GetDistance(MovableCoordinates[i], AllyList[j]->Position) == 1 && AllyList[j] != this)
			{
				HealableAllies.push_back(AllyList[j]);
			}
		}
	}

	for (int i = 0; i < HealableAllies.size(); i++)
	{
		for (int j = i + 1; j < HealableAllies.size(); j++)
		{
			if (HealableAllies[i] == HealableAllies[j])
			{
				HealableAllies.erase(HealableAllies.begin() + j);
				j--;
			}
		}
	}

	return HealableAllies;
}

vector<Character*> Character::GetDancableAllies(vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap, vector <Coordinate> MovableCoordinates)
{
	vector <Character*> DancableAllies;

	if (this->CharacterAbility != DANCE)
	{
		return DancableAllies;
	}

	for (int i = 0; i < MovableCoordinates.size(); i++)
	{
		for (int j = 0; j < AllyList.size(); j++)
		{
			if (GetDistance(MovableCoordinates[i], AllyList[j]->Position) == 1 && AllyList[j]->CharacterStatus==MOVED && AllyList[j]!= this)
			{
				DancableAllies.push_back(AllyList[j]);
			}
		}
	}

	for (int i = 0; i < DancableAllies.size(); i++)
	{
		for (int j = i + 1; j < DancableAllies.size(); j++)
		{
			if (DancableAllies[i] == DancableAllies[j])
			{
				DancableAllies.erase(DancableAllies.begin() + j);
				j--;
			}
		}
	}

	return DancableAllies;
}

vector<WeaponType> Character::GetUsableWeapons()
{
	return UsableWeapon;
}

void Character::NewTurn(Side CharacterSide)
{
	CharacterStatus = ACTIVE;

	this->Draw(CharacterSide);
}

void Character::EndTurn()
{
	CharacterStatus = MOVED;

	setcolor(BLACK);

	line(Position.iX * 35 - 35, Position.iY * 35 - 35, Position.iX * 35, Position.iY * 35);
	line(Position.iX * 35 - 35, Position.iY * 35, Position.iX * 35, Position.iY * 35 - 35);

	setcolor(WHITE);
}

void Character::Die(Map StageMap)
{
	CharacterStatus = DEAD;

	Terrain *pTempTerrain = StageMap.GetTerrain(Position.iX, Position.iY);

	pTempTerrain->Draw();
}

Coordinate Character::GetPosition()
{
	return Position;
}

void Character::MoveTo(Coordinate Destination, Map StageMap, Side CharacterSide)
{
	Terrain *pTempTerrain = StageMap.GetTerrain(Position.iX, Position.iY);

	pTempTerrain->Draw();

	int iMinX = (Position.iX - 1) * 35;
	int iMinY = (Position.iY - 1) * 35;
	int iMaxX = (Position.iX) * 35;
	int iMaxY = (Position.iY) * 35;

	setcolor(WHITE);

	setlinestyle(SOLID_LINE, 0xFFFF, 3);

	line(iMinX, iMinY, iMaxX, iMinY);
	line(iMinX, iMaxY, iMaxX, iMaxY);
	line(iMinX, iMinY, iMinX, iMaxY);
	line(iMaxX, iMinY, iMaxX, iMaxY);

	Position = Destination;

	this->Draw(CharacterSide);
}

void Character::SetPosition(int X, int Y)
{
	Position.iX = X;
	Position.iY = Y;
}

void Character::PrintInfo(Side CharacterSide)
{
	if (CharacterSide == SIDE1)
	{
		readimagefile(CharacterImage, 1000 - 35 / 2, 20 - 35 / 2, 1000 + 35 / 2, 20 + 35 / 2);
	}
	else
	{
		readimagefile(CharacterFlippedImage, 1000 - 35 / 2, 20 - 35 / 2, 1000 + 35 / 2, 20 + 35 / 2);
	}

	char Buffer[60];
	
	setcolor(YELLOW);

	switch (CharacterClass)
	{
	case LORD:
		outtextxy(1000, 100, "LORD");
		break;
	case MERCENARY:
		outtextxy(1000, 100, "MERCENARY");
		break;
	case MYRMIDON:
		outtextxy(1000, 100, "MYRMIDON");
		break;
	case THIEF:
		outtextxy(1000, 100, "THIEF");
		break;
	case KNIGHT:
		outtextxy(1000, 100, "KNIGHT");
		break;
	case FIGHTER:
		outtextxy(1000, 100, "FIGHTER");
		break;
	case PIRATE:
		outtextxy(1000, 100, "PIRATE");
		break;
	case ARCHER:
		outtextxy(1000, 100, "ARCHER");
		break;
	case NOMAD:
		outtextxy(1000, 100, "NOMAD");
		break;
	case CAVALIER:
		outtextxy(1000, 100, "CAVALIER");
		break;
	case PEGASUSKNIGHT:
		outtextxy(1000, 100, "PEGASUSKNIGHT");
		break;
	case WYVERNRIDER:
		outtextxy(1000, 100, "WYVERNRIDER");
		break;
	case MONK:
		outtextxy(1000, 100, "MONK");
		break;
	case CLERIC:
		outtextxy(1000, 100, "CLERIC");
		break;
	case MAGE:
		outtextxy(1000, 100, "MAGE");
		break;
	case SHAMAN:
		outtextxy(1000, 100, "SHAMAN");
		break;
	case DANCER:
		outtextxy(1000, 100, "DANCER");
		break;
	}

	setcolor(WHITE);

	sprintf(Buffer, "Name:\t %s", sName);
	outtextxy(1000, 120, Buffer);

	sprintf(Buffer, "Level:\t %d", iLevel);
	outtextxy(1000, 140, Buffer);

	sprintf(Buffer, "Exp: %d/%d", iExp, 100);
	outtextxy(1000, 160, Buffer);

	sprintf(Buffer, "HP:\t %d/%d", iHP, iMaxHP);
	outtextxy(1000, 180, Buffer);

	sprintf(Buffer, "Strength:\t %d", iStrength);
	outtextxy(1000, 220, Buffer);

	sprintf(Buffer, "Magic:\t %d", iMagic);
	outtextxy(1000, 260, Buffer);

	sprintf(Buffer, "Skill:\t %d", iSkill);
	outtextxy(1000, 300, Buffer);

	sprintf(Buffer, "Speed:\t %d", iSpeed);
	outtextxy(1000, 340, Buffer);

	sprintf(Buffer, "Luck:\t %d", iLuck);
	outtextxy(1000, 380, Buffer);

	sprintf(Buffer, "Defense:\t %d", iDefense);
	outtextxy(1000, 420, Buffer);

	sprintf(Buffer, "Resistance:\t %d", iResistance);
	outtextxy(1000, 460, Buffer);

	sprintf(Buffer, "Movement:\t %d", iMovement);
	outtextxy(1000, 500, Buffer);

	for (int i = 0; i < Inventory.size(); i++)
	{
		sprintf(Buffer, "%s:\t %d", Inventory[i]->GetItemName(), Inventory[i]->GetDurability());

		outtextxy(1000, 540 + i * 40, Buffer);
	}
}

void Character::Draw(Side CharacterSide)
{
	if (CharacterSide == SIDE1)
	{
		readimagefile(CharacterImage, (Position.iX*35 - 17.5) - 36 / 2.0, (Position.iY*35 - 17.5) - 36 / 2.0, (Position.iX * 35 - 17.5) + 36 / 2.0, (Position.iY * 35 - 17.5) + 36 / 2.0);
	}
	else
	{
		readimagefile(CharacterFlippedImage, (Position.iX * 35 - 17.5) - 36 / 2.0, (Position.iY * 35 - 17.5) - 36 / 2.0, (Position.iX * 35 - 17.5) + 36 / 2.0, (Position.iY * 35 - 17.5) + 36 / 2.0);
	}

	if (IsMoved() == true)
	{
		setcolor(BLACK);
		line(Position.iX * 35 - 35, Position.iY * 35 - 35, Position.iX * 35, Position.iY * 35);
		line(Position.iX * 35 - 35, Position.iY * 35, Position.iX * 35, Position.iY * 35 - 35);
		setcolor(WHITE);
	}
}

bool Character::IsDead()
{
	if (CharacterStatus == DEAD)
	{
		return true;
	}

	return false;
}

bool Character::IsMoved()
{
	if (CharacterStatus == MOVED)
	{
		return true;
	}

	return false;
}

bool Character::IsActive()
{
	if (CharacterStatus == ACTIVE)
	{
		return true;
	}

	return false;
}

bool Character::IsUseVulneraryPossible()
{
	for (int i = 0; i < Inventory.size(); i++)
	{
		if (Inventory[i]->GetRecoverAmount() == 10)
		{
			return true;
		}
	}

	return false;
}

bool Character::IsUseElixirPossible()
{
	for (int i = 0; i < Inventory.size(); i++)
	{
		if (Inventory[i]->GetRecoverAmount() == 20)
		{
			return true;
		}
	}

	return false;
}

void Character::IncreaseExp(int ExpGained)
{
	iExp += ExpGained;

	while (iExp >= 100)
	{
		iExp -= 100;
		LevelUp();
	}
}