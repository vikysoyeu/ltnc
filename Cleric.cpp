#include "Cleric.h"



Cleric::Cleric()
{
	iMaxHP = 16;
	iHP = iMaxHP;
	iStrength = 0;
	iMagic = 1;
	iSkill = 2;
	iSpeed = 2;
	iLuck = 0;
	iDefense = 0;
	iResistance = 6;
	iMovement = 5;

	iHPGrowth = 50;
	iStrengthGrowth = 0;
	iMagicGrowth = 30;
	iSkillGrowth = 35;
	iSpeedGrowth = 32;
	iLuckGrowth = 45;
	iDefenseGrowth = 8;
	iResistanceGrowth = 50;

	CharacterClass = CLERIC;
	CharacterAbility = HEAL;

	CharacterImage = "Cleric.jpg";
	CharacterFlippedImage = "Cleric-flipped.jpg";
}


Cleric::~Cleric()
{
}
