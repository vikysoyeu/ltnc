#include "TitleScreen.h"
#include "DeployScreen.h"
#include "GameScene.h"

#include <Mmsystem.h>
#include <mciapi.h>

#pragma comment(lib, "Winmm.lib")

void main()
{
	initwindow(MAX_SCREEN_WIDTH, MAX_SCREEN_HEIGHT, "Battle World");

	Scene* Game = new TitleScreen;
	Game->Init();
	Game->Update();

	closegraph();
}