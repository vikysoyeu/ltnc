#pragma once
#include "Scene.h"
#include "GameScene.h"
class DeployScreen :
	public Scene
{
private:
	vector <Character*> Side1Characters;
	vector <Character*> Side2Characters;

	Character *pTempCharacter;

	char CharacterName[50];

	Map GameMap;

	Side SelectingSide;

	DeployPhase Phase;

	Class ClassCursor;

	vector <Item*>UsableWeapons;
	int iWeaponCursor;
	int iNumberOfSelectedWeapons;

	Cursor MapCursor;

	Class GetLeftClass();
	Class GetRightClass();

	void InsertSword();
	void InsertLance();
	void InsertAxe();
	void InsertBow();
	void InsertAnima();
	void InsertLight();
	void InsertDark();

	void GetUsableWeapons();

	void PrintClassInfo();
	void PrintWeaponInfo();

	Character *CreateCharacter(char* Name, Class CharacterClass);

	void Draw();

	void ProcessLeftArrow();
	void ProcessRightArrow();
	void ProcessUpArrow();
	void ProcessDownArrow();
	bool ProcessEnter();

	void InitSelectClass();
	void InitSelectWeapon();
	void InitSelectPosition();

public:
	DeployScreen(Map StageMap);
	~DeployScreen();

	void Init();
	void Update();
};

