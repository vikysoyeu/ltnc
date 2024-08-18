#pragma once

#include <iostream>
#include <vector>
#include "graphics.h"
#include <Windows.h>
#include <Mmsystem.h>

#pragma comment(lib, "graphics.lib")
#pragma comment(lib, "winmm.lib")


using namespace std;

enum Action
{
	USE_VULNERARY, USE_ELIXIR, USE_HEAL, USE_DANCE, ATTACK, WAIT
};

enum GamePhase
{
	SELECTCHARACTER, MOVE, ACT, SELECTTARGET
};

enum DeployPhase
{
	SELECTCLASS, SELECTWEAPON, SELECTPOSITION
};

enum Side
{
	SIDE1, SIDE2
};

enum State
{
	ACTIVE, MOVED, DEAD
};

enum Class
{
	LORD, MERCENARY, MYRMIDON, THIEF, KNIGHT, FIGHTER, PIRATE, ARCHER, NOMAD, CAVALIER,
	PEGASUSKNIGHT, WYVERNRIDER, MONK, CLERIC, MAGE, SHAMAN, DANCER
};

enum ItemType
{
	POTION, WEAPON
};

enum WeaponType
{
	SWORD, LANCE, AXE, BOW, ANIMA, LIGHT, DARK, NOTWEAPON
};

enum SpecialAbility
{
	FLYING, DANCE, HEAL, NONE
};

typedef struct Coordinate
{
	int iX;
	int iY;

	Coordinate(int X = 0, int Y = 0)
	{
		iX = X;
		iY = Y;
	}
};

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

#define MAX_SCREEN_WIDTH 1366
#define MAX_SCREEN_HEIGHT 700

#define MAX_CHARACTERS 10


