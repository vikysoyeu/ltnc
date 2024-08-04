#include "DeployScreen.h"



Class DeployScreen::GetLeftClass()
{
	switch (ClassCursor)
	{
	case MERCENARY:
		return DANCER;
	case MYRMIDON:
		return MERCENARY;
	case THIEF:
		return MYRMIDON;
	case KNIGHT:
		return THIEF;
	case FIGHTER:
		return KNIGHT;
	case PIRATE:
		return FIGHTER;
	case ARCHER:
		return PIRATE;
	case NOMAD:
		return ARCHER;
	case CAVALIER:
		return NOMAD;
	case PEGASUSKNIGHT:
		return CAVALIER;
	case WYVERNRIDER:
		return PEGASUSKNIGHT;
	case MONK:
		return WYVERNRIDER;
	case CLERIC:
		return MONK;
	case MAGE:
		return CLERIC;
	case SHAMAN:
		return MAGE;
	case DANCER:
		return SHAMAN;
	}
}

Class DeployScreen::GetRightClass()
{
	switch (ClassCursor)
	{
	case MERCENARY:
		return MYRMIDON;
	case MYRMIDON:
		return THIEF;
	case THIEF:
		return KNIGHT;
	case KNIGHT:
		return FIGHTER;
	case FIGHTER:
		return PIRATE;
	case PIRATE:
		return ARCHER;
	case ARCHER:
		return NOMAD;
	case NOMAD:
		return CAVALIER;
	case CAVALIER:
		return PEGASUSKNIGHT;
	case PEGASUSKNIGHT:
		return WYVERNRIDER;
	case WYVERNRIDER:
		return MONK;
	case MONK:
		return CLERIC;
	case CLERIC:
		return MAGE;
	case MAGE:
		return SHAMAN;
	case SHAMAN:
		return DANCER;
	case DANCER:
		return MERCENARY;
	}
}

void DeployScreen::InsertSword()
{
	Item* pTempWeapon;

	pTempWeapon = new IronSword;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new IronBlade;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SlimSword;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SteelSword;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SteelBlade;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SilverSword;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SilverBlade;
	UsableWeapons.push_back(pTempWeapon);

}

void DeployScreen::InsertLance()
{
	Item* pTempWeapon;

	pTempWeapon = new IronLance;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SlimLance;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Javelin;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SteelLance;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SilverLance;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new ShortSpear;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Spear;
	UsableWeapons.push_back(pTempWeapon);
}

void DeployScreen::InsertAxe()
{
	Weapon* pTempWeapon;

	pTempWeapon = new IronAxe;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SteelAxe;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new HandAxe;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SilverAxe;
	UsableWeapons.push_back(pTempWeapon);
}

void DeployScreen::InsertBow()
{
	Weapon* pTempWeapon;

	pTempWeapon = new IronBow;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SteelBow;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new ShortBow;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new LongBow;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new SilverBow;
	UsableWeapons.push_back(pTempWeapon);
}

void DeployScreen::InsertAnima()
{
	Weapon* pTempWeapon;

	pTempWeapon = new Fire;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Thunder;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Elfire;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Fimbulvetr;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Excalibur;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Forblaze;
	UsableWeapons.push_back(pTempWeapon);
}

void DeployScreen::InsertLight()
{
	Weapon* pTempWeapon;

	pTempWeapon = new Lightning;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Shine;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Divine;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Aura;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Luce;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Aureola;
	UsableWeapons.push_back(pTempWeapon);
}

void DeployScreen::InsertDark()
{
	Weapon* pTempWeapon;

	pTempWeapon = new Flux;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Nosferatu;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Fennrir;
	UsableWeapons.push_back(pTempWeapon);

	pTempWeapon = new Gespenst;
	UsableWeapons.push_back(pTempWeapon);
}

void DeployScreen::GetUsableWeapons()
{
	Character *pTempCharacter = CreateCharacter("", ClassCursor);

	vector <WeaponType> UsableTypes = pTempCharacter->GetUsableWeapons();

	for (int i = 0; i < UsableTypes.size(); i++)
	{
		switch (UsableTypes[i])
		{
		case SWORD:
			InsertSword();

			break;
		case LANCE:
			InsertLance();

			break;
		case AXE:
			InsertAxe();

			break;
		case BOW:
			InsertBow();

			break;
		case ANIMA:
			InsertAnima();

			break;
		case LIGHT:
			InsertLight();

			break;
		case DARK:
			InsertDark();

			break;
		}
	}
}

void DeployScreen::PrintClassInfo()
{
	Character *pClassInfo = CreateCharacter("", ClassCursor);

	pClassInfo->PrintInfo();

	delete pClassInfo;
}

void DeployScreen::PrintWeaponInfo()
{
	UsableWeapons[iWeaponCursor]->PrintItemInfo();
}

Character * DeployScreen::CreateCharacter(char* Name, Class CharacterClass)
{
	Character* pTempCharacter;

	switch (CharacterClass)
	{
	case LORD:
		pTempCharacter = new Lord;
		break;
	case MERCENARY:
		pTempCharacter = new Mercenary;
		break;
	case MYRMIDON:
		pTempCharacter = new Myrmidon;
		break;
	case THIEF:
		pTempCharacter = new Thief;
		break;
	case KNIGHT:
		pTempCharacter = new Knight;
		break;
	case FIGHTER:
		pTempCharacter = new Fighter;
		break;
	case PIRATE:
		pTempCharacter = new Pirate;
		break;
	case ARCHER:
		pTempCharacter = new Archer;
		break;
	case NOMAD:
		pTempCharacter = new Nomad;
		break;
	case CAVALIER:
		pTempCharacter = new Cavalier;
		break;
	case PEGASUSKNIGHT:
		pTempCharacter = new PegasusKnight;
		break;
	case WYVERNRIDER:
		pTempCharacter = new WyvernRider;
		break;
	case MONK:
		pTempCharacter = new Monk;
		break;
	case CLERIC:
		pTempCharacter = new Cleric;
		break;
	case MAGE:
		pTempCharacter = new Mage;
		break;
	case SHAMAN:
		pTempCharacter = new Shaman;
		break;
	case DANCER:
		pTempCharacter = new Dancer;
		break;
	}

	pTempCharacter->SetName(Name);

	return pTempCharacter;
}

void DeployScreen::Draw()
{
	switch (Phase)
	{
	case SELECTCLASS:
		char ClassBuffer[100];

		switch (SelectingSide)
		{
		case SIDE1:
			sprintf(ClassBuffer, "Select %d character(s) for SIDE 1", MAX_CHARACTERS - Side1Characters.size());
			break;

		case SIDE2:
			sprintf(ClassBuffer, "Select %d character(s) for SIDE 2", MAX_CHARACTERS - Side2Characters.size());
			break;
		}

		outtextxy(1000, 60, ClassBuffer);

		PrintClassInfo();

		break;

	case SELECTWEAPON:
		char WeaponBuffer[30];

		sprintf(WeaponBuffer, "Select %d weapon(s)", 2 - iNumberOfSelectedWeapons);
		outtextxy(1000, 40, WeaponBuffer);

		PrintWeaponInfo();

		break;
	case SELECTPOSITION:
		MapCursor.Draw();

		setviewport(702, 0, 1366, 700, 1);
		clearviewport();

		setviewport(0, 0, 1366, 700, 1);

		switch (SelectingSide)
		{
		case SIDE1:
			for (int i = 0; i < Side1Characters.size(); i++)
			{
				if (Side1Characters[i]->GetPosition().iX == MapCursor.GetPostion().iX &&
					Side1Characters[i]->GetPosition().iY == MapCursor.GetPostion().iY)
				{
					Side1Characters[i]->PrintInfo();;
				}
			}

			break;
		case SIDE2:
			for (int i = 0; i < Side2Characters.size(); i++)
			{
				if (Side2Characters[i]->GetPosition().iX == MapCursor.GetPostion().iX &&
					Side2Characters[i]->GetPosition().iY == MapCursor.GetPostion().iY)
				{
					Side2Characters[i]->PrintInfo();
				}
			}

			break;
		}

		outtextxy(1000, 40, "Select initial position");

		break;
	}
}

void DeployScreen::ProcessLeftArrow()
{
	switch (Phase)
	{
	case SELECTCLASS:
		ClassCursor = GetLeftClass();

		setviewport(702, 0, 1366, 700, 1);
		clearviewport();

		setviewport(0, 0, 1366, 700, 1);

		readimagefile("RightArrow.jpg", 1200, 80, 1250, 110);
		readimagefile("LeftArrow.jpg", 750, 80, 800, 110);

		Draw();

		Sleep(100);

		break;
	case SELECTWEAPON:
		if (iWeaponCursor == 0)
		{
			iWeaponCursor = UsableWeapons.size() - 1;
		}
		else
		{
			iWeaponCursor--;
		}

		setviewport(702, 0, 1366, 700, 1);
		clearviewport();

		setviewport(0, 0, 1366, 700, 1);

		readimagefile("RightArrow.jpg", 1200, 80, 1250, 110);
		readimagefile("LeftArrow.jpg", 750, 80, 800, 110);

		Draw();

		Sleep(100);

		break;

	case SELECTPOSITION:
		MapCursor.Erase();

		MapCursor.MoveLeft();

		Draw();

		Sleep(100);

		break;
	}
}

void DeployScreen::ProcessRightArrow()
{
	switch (Phase)
	{
	case SELECTCLASS:
		ClassCursor = GetRightClass();

		setviewport(702, 0, 1366, 700, 1);
		clearviewport();

		setviewport(0, 0, 1366, 700, 1);

		readimagefile("RightArrow.jpg", 1200, 80, 1250, 110);
		readimagefile("LeftArrow.jpg", 750, 80, 800, 110);

		Draw();

		Sleep(100);
		
		break;
	case SELECTWEAPON:
		if (iWeaponCursor == UsableWeapons.size() - 1)
		{
			iWeaponCursor = 0;
		}
		else
		{
			iWeaponCursor++;
		}

		setviewport(702, 0, 1366, 700, 1);
		clearviewport();

		setviewport(0, 0, 1366, 700, 1);

		readimagefile("RightArrow.jpg", 1200, 80, 1250, 110);
		readimagefile("LeftArrow.jpg", 750, 80, 800, 110);

		Draw();

		Sleep(100);

		break;

	case SELECTPOSITION:
		MapCursor.Erase();

		MapCursor.MoveRight();

		Draw();

		Sleep(100);

		break;
	}

}

void DeployScreen::ProcessUpArrow()
{
	if (Phase == SELECTPOSITION)
	{
		MapCursor.Erase();

		MapCursor.MoveUp();

		Draw();

		Sleep(100);
	}
}

void DeployScreen::ProcessDownArrow()
{
	if (Phase == SELECTPOSITION)
	{
		MapCursor.Erase();

		MapCursor.MoveDown();

		Draw();

		Sleep(100);
	}
}

bool DeployScreen::ProcessEnter()
{
	switch (Phase)
	{
	case SELECTCLASS:
	{
		switch (SelectingSide)
		{
		case SIDE1:
			sprintf(CharacterName, "Side 1 - Unit %d", Side1Characters.size());
			break;
		case SIDE2:
			sprintf(CharacterName, "Side 2 - Unit %d", Side2Characters.size());
			break;
		}

		pTempCharacter = CreateCharacter(CharacterName, ClassCursor);

		Item* pTempItem;
		pTempItem = new Vulnerary();
		pTempCharacter->ObtainItem(pTempItem);

		pTempItem = new Elixir();
		pTempCharacter->ObtainItem(pTempItem);

		if (ClassCursor == DANCER || ClassCursor == CLERIC)
		{
			InitSelectPosition();
		}
		else
		{
			InitSelectWeapon();
		}

		break;
	}

	case SELECTWEAPON:
	{
		Item *pTempWeapon = UsableWeapons[iWeaponCursor];
		pTempCharacter->ObtainItem(pTempWeapon);
		UsableWeapons.erase(UsableWeapons.begin() + iWeaponCursor);

		if (iNumberOfSelectedWeapons == 0)
		{
			iNumberOfSelectedWeapons++;

			pTempCharacter->EquipWeapon(2);
			iWeaponCursor = 0;

			setviewport(702, 0, 1366, 700, 1);
			clearviewport();

			setviewport(0, 0, 1366, 700, 1);

			Draw();
		}
		else
		{
			for (int i = 0; i < UsableWeapons.size(); i++)
			{
				delete (UsableWeapons[i]);
			}

			UsableWeapons.clear();

			InitSelectPosition();
		}

		break;
	}

	case SELECTPOSITION:
	{
		switch (SelectingSide)
		{
		case SIDE1:
			for (int i = 0; i < Side1Characters.size(); i++)
			{
				if (MapCursor.GetPostion().iX == Side1Characters[i]->GetPosition().iX &&
					MapCursor.GetPostion().iY == Side1Characters[i]->GetPosition().iY)
				{
					return false;
				}
			}

			pTempCharacter->SetPosition(MapCursor.GetPostion().iX, MapCursor.GetPostion().iY);

			Side1Characters.push_back(pTempCharacter);

			InitSelectPosition();

			break;
		case SIDE2:
			for (int i = 0; i < Side2Characters.size(); i++)
			{
				if (MapCursor.GetPostion().iX == Side2Characters[i]->GetPosition().iX &&
					MapCursor.GetPostion().iY == Side2Characters[i]->GetPosition().iY)
				{
					return false;
				}
			}

			pTempCharacter->SetPosition(MapCursor.GetPostion().iX, MapCursor.GetPostion().iY);

			Side2Characters.push_back(pTempCharacter);

			if (Side2Characters.size() == MAX_CHARACTERS)
			{
				Sleep(500);

				cleardevice();

				Scene* Game = new GameScene(Side1Characters, Side2Characters, GameMap);

				Game->Init();
				Game->Update();

				return true;
			}

			break;
		}

		MapCursor.Erase();

		InitSelectClass();

		break;
	}
	}

	Sleep(100);

	return false;
}

void DeployScreen::InitSelectClass()
{
	Phase = SELECTCLASS;

	ClassCursor = MERCENARY;

	MapCursor.Erase();

	setviewport(702, 0, 1366, 700, 1);
	clearviewport();

	setviewport(0, 0, 1366, 700, 1);

	readimagefile("RightArrow.jpg", 1200, 80, 1250, 110);
	readimagefile("LeftArrow.jpg", 750, 80, 800, 110);

	switch (SelectingSide)
	{
	case SIDE1:
		pTempCharacter->Draw(SIDE1);

		break;
	case SIDE2:
		pTempCharacter->Draw(SIDE2);

		break;
	}
	
	if (Side1Characters.size() == MAX_CHARACTERS)
	{
		SelectingSide = SIDE2;
	}

	Draw();
}

void DeployScreen::InitSelectWeapon()
{
	Phase = SELECTWEAPON;

	GetUsableWeapons();
	iWeaponCursor = 0;
	iNumberOfSelectedWeapons = 0;

	setviewport(702, 0, 1366, 700, 1);
	clearviewport();

	setviewport(0, 0, 1366, 700, 1);

	readimagefile("RightArrow.jpg", 1200, 80, 1250, 110);
	readimagefile("LeftArrow.jpg", 750, 80, 800, 110);

	Draw();
}

void DeployScreen::InitSelectPosition()
{
	Phase = SELECTPOSITION;

	switch (SelectingSide)
	{
	case SIDE1:
		MapCursor.SetLimit(18, 20, 1, 20);

		MapCursor.SetPosition(20, 10);
		break;
	case SIDE2:
		MapCursor.SetLimit(1, 3, 1, 20);

		MapCursor.SetPosition(1, 11);
		break;
	}

	setviewport(702, 0, 1366, 700, 1);
	clearviewport();

	setviewport(0, 0, 1366, 700, 1);

	Draw();
}

DeployScreen::DeployScreen(Map StageMap)
{
	GameMap = StageMap;
}

DeployScreen::~DeployScreen()
{
}

void DeployScreen::Init()
{
	Phase = SELECTCLASS;
	
	ClassCursor = MERCENARY;

	Item* pTempItem;

	Character *Side1Lord = CreateCharacter("Enzan", LORD);
	pTempItem = new SilverSword;
	Side1Lord->ObtainItem(pTempItem);
	Side1Lord->EquipWeapon(0);

	pTempItem = new SilverSword;
	Side1Lord->ObtainItem(pTempItem);

	pTempItem = new Vulnerary;
	Side1Lord->ObtainItem(pTempItem);

	pTempItem = new Elixir;
	Side1Lord->ObtainItem(pTempItem);
	
	Character *Side2Lord = CreateCharacter("MiKiNo", LORD);
	pTempItem = new SilverSword;
	Side2Lord->ObtainItem(pTempItem);
	Side2Lord->EquipWeapon(0);

	pTempItem = new SilverSword;
	Side2Lord->ObtainItem(pTempItem);

	pTempItem = new Vulnerary;
	Side2Lord->ObtainItem(pTempItem);

	pTempItem = new Elixir;
	Side2Lord->ObtainItem(pTempItem);

	Side1Lord->SetPosition(20, 10);
	Side2Lord->SetPosition(1, 11);

	Side1Characters.push_back(Side1Lord);
	Side2Characters.push_back(Side2Lord);

	SelectingSide = SIDE1;

	GameMap.Draw();

	Side1Lord->Draw(SIDE1);
	Side2Lord->Draw(SIDE2);

	readimagefile("RightArrow.jpg", 1200, 80, 1250, 110);
	readimagefile("LeftArrow.jpg", 750, 80, 800, 110);

	Draw();

	PlaySound(TEXT("DeployScreen.wav"), NULL, SND_LOOP | SND_ASYNC);
}

void DeployScreen::Update()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			ProcessLeftArrow();
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			ProcessRightArrow();
		}

		if (GetAsyncKeyState(VK_UP))
		{
			ProcessUpArrow();
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			ProcessDownArrow();
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			if (ProcessEnter() == true)
			{
				return;
			}
		}
	}
}
