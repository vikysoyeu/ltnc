#include "Dancer.h"



Dancer::Dancer()
{
	iMaxHP = 14;
	iHP = iMaxHP;
	iStrength = 1;
	iMagic = 0;
	iSkill = 2;
	iSpeed = 7;
	iLuck = 0;
	iDefense = 0;
	iResistance = 1;
	iMovement = 5;

	iHPGrowth = 45;
	iStrengthGrowth = 45;
	iMagicGrowth = 0;
	iSkillGrowth = 30;
	iSpeedGrowth = 60;
	iLuckGrowth = 70;
	iDefenseGrowth = 0;
	iResistanceGrowth = 13;

	CharacterClass = DANCER;
	CharacterAbility = DANCE;

	CharacterImage = "Dancer.jpg";
	CharacterFlippedImage = "Dancer-flipped.jpg";
}


Dancer::~Dancer()
{
}
