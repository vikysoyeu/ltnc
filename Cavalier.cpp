#include "Cavalier.h"



Cavalier::Cavalier()
{
	iMaxHP = 18;
	iHP = iMaxHP;
	iStrength = 4;
	iMagic = 0;
	iSkill = 3;
	iSpeed = 3;
	iLuck = 0;
	iDefense = 3;
	iResistance = 0;
	iMovement = 5;

	iHPGrowth = 70;
	iStrengthGrowth = 35;
	iMagicGrowth = 0;
	iSkillGrowth = 40;
	iSpeedGrowth = 32;
	iLuckGrowth = 35;
	iDefenseGrowth = 15;
	iResistanceGrowth = 10;

	CharacterClass = CAVALIER;
	CharacterAbility = NONE;

	UsableWeapon.push_back(SWORD);
	UsableWeapon.push_back(LANCE);

	CharacterImage = "Cavalier.jpg";
	CharacterFlippedImage = "Cavalier-flipped.jpg";
}


Cavalier::~Cavalier()
{
}
