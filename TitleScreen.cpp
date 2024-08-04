#include "TitleScreen.h"

TitleScreen::TitleScreen()
{
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::Draw()
{
	setviewport(1366 / 2 - 150, 200, 1366 / 2 - 70, 500, 1);
	clearviewport();

	setviewport(0, 0, 1366, 700, 1);

	setcolor(YELLOW);
	settextstyle(DEFAULT_FONT, 0, 50);
	outtextxy(1366 / 2 - 100, iCursor, ">");
	setcolor(WHITE);
}

void TitleScreen::Init()
{
	iCursor = 300;

	readimagefile("TitleScreen.jpg", 0, 0, 1366, 700);
	settextstyle(DEFAULT_FONT, 0, 50);
	settextjustify(CENTER_TEXT, CENTER_LINE);
	outtextxy(1366 / 2, 300, "PLAY");
	outtextxy(1366 / 2, 400, "EXIT");
	setcolor(YELLOW);
	outtextxy(1366 / 2 - 100, iCursor, ">");

	settextstyle(1, 0, 2);
	outtextxy(1366 / 2, 600, "---> Made by Enzan-sama and MiKiNo <---");
	setcolor(5);
	outtextxy(1366 / 2 + 10, 625, "Khoa CNPM - UIT K10");
	setcolor(WHITE);

	PlaySound(TEXT("TitleScreen.wav"), NULL, SND_LOOP | SND_ASYNC);

	Draw();
}

void TitleScreen::Update()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			iCursor += 100;
			if (iCursor > 400)
			{
				iCursor = 300;

			}
			Draw();
			Sleep(100);
		}

		if (GetAsyncKeyState(VK_DOWN))
		{

			iCursor -= 100;
			if (iCursor < 300)
			{
				iCursor = 400;
			}
			Draw();
			Sleep(100);
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			PlaySound(TEXT("ButtonPressed.wav"), NULL, SND_ASYNC);

			switch (iCursor)
			{
			case 300:
			{
				Map StageMap;
				for (int i = 1; i <= MAP_WIDTH; i++)
				{
					for (int j = 1; j <= MAP_HEIGHT; j++)
					{
						StageMap.SetTerrain(PLAIN, i, j);
					}
				}

				cleardevice();

				Scene *Deploy = new DeployScreen(StageMap);

				Sleep(500);

				settextstyle(1, 0, 2);

				Deploy->Init();
				Deploy->Update();
			}

			case 400:
				return;
			}

			break;
		}
	}
}
