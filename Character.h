#pragma once

#include "FireEmblemLib.h"
#include "Item.h"
#include "RandomNumberGenerator.h"
#include "Map.h"

class Character
{
protected:
	char* sName;
	Coordinate Position;

	State CharacterStatus;

	Class CharacterClass;
	bool IsPromoted;

	int iExp;
	int iLevel;

	int iMaxHP;
	int iHP;
	int iStrength;
	int iMagic;
	int iSkill;
	int iSpeed;
	int iLuck;
	int iDefense;
	int iResistance;
	int iMovement;

	int iHPGrowth;
	int iStrengthGrowth;
	int iMagicGrowth;
	int iSkillGrowth;
	int iSpeedGrowth;
	int iLuckGrowth;
	int iDefenseGrowth;
	int iResistanceGrowth;

	char *CharacterImage;
	char *CharacterFlippedImage;

	vector <WeaponType> UsableWeapon;
	vector <Item*> Inventory;
	SpecialAbility CharacterAbility;
	Item* EquippedWeapon;

	void BreakWeapon();

	int GetAttackPower();
	int GetAttackSpeed();
	int GetHitRate();
	int GetEvade();
	int GetCritical();
	int GetCriticalEvade();

	bool IsWeaponTriangleWon(Character *Enemy);
	bool IsWeaponTriangleLost(Character *Enemy);

	bool IsSelfDoubleStrikePossible(Character *Enemy);
	bool IsEnemyDoubleStrikePossible(Character *Enemy);

	void Strike(Character *Enemy);

	void CheckRight(vector <Coordinate> &MovableCoordinates, int MoveCount, int X, int Y, vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap);
	void CheckLeft(vector <Coordinate> &MovableCoordinates, int MoveCount, int X, int Y, vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap);
	void CheckUp(vector <Coordinate> &MovableCoordinates, int MoveCount, int X, int Y, vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap);
	void CheckDown(vector <Coordinate> &MovableCoordinates, int MoveCount, int X, int Y, vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap);

	void IncreaseExp(int ExpGained);
	void LevelUp();
	void Promote();

	int GetDistance(Coordinate Position1, Coordinate Position2);
public:
	Character();
	~Character();

	void SetName(char* Name);

	bool ObtainItem(Item*);
	void DiscardItem(int InventorySlot);
	bool EquipWeapon(int InventorySlot);
	int GetInventorySlots();

	Class GetCharacterClass();

	Item* GetEquippedWeapon();
	
	void Attack(Character *Enemy);
	void Dance(Character *Ally);
	void Heal(Character *Ally);
	void UseVulnerary();
	void UseElixir();
	bool UseItem(int InventorySlot);

	bool IsAttackable(Character*);
	bool IsHealable(Character*);
	bool IsDancable(Character*);

	vector <Coordinate> GetMovableCoordinates(vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap);
	vector <Character*> GetAttackableEnemies(vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap, vector <Coordinate> MovableCoordinates);
	vector <Character*> GetHealableAllies(vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap, vector <Coordinate> MovableCoordinates);
	vector <Character*> GetDancableAllies(vector<Character*> EnemyList, vector<Character*> AllyList, Map StageMap, vector <Coordinate> MovableCoordinates);

	vector <WeaponType> GetUsableWeapons();

	void NewTurn(Side CharacterSide);
	void EndTurn();
	void Die(Map StageMap);

	Coordinate GetPosition();

	void MoveTo(Coordinate Destination,Map StageMap, Side CharacterSide);
	void SetPosition(int X, int Y);

	void PrintInfo(Side CharacterSide = SIDE1);

	void Draw(Side CharacterSide = SIDE1);

	bool IsDead();
	bool IsMoved();
	bool IsActive();
	
	bool IsUseVulneraryPossible();
	bool IsUseElixirPossible();

	int GetFinalAttackPower(Character *Enemy);
	int GetFinalHitRate(Character *Enemy);
	int GetFinalCritical(Character *Enemy);
};

