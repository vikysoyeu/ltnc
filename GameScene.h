#pragma once
#include "Scene.h"
#include "GameOverScene.h"

class GameScene :
	public Scene
{
private:
	vector <Character*> Side1Characters;
	vector <Character*> Side2Characters;

	bool IsGameOver;
	Side Winner;

	vector <Coordinate> MovablePositions;

	vector <Character*> AttackableEnemies;
	vector <Character*> HealableAllies;
	vector <Character*> DancableAllies;

	vector <Action>PossibleActions;

	Action SelectedAction;

	Character* SelectedCharacter;

	Side Turn;

	GamePhase Phase;

	Cursor GameCursor;

	int iActOption;

	void Draw();

	Map GameMap;

	void Attack(Character*);

	void GameOver(Side WinningSide);

	void ProcessLeftArrow();
	void ProcessRightArrow();
	void ProcessUpArrow();
	void ProcessDownArrow();
	void ProcessEnter();

	void InitSelectCharacter();
	void InitMove();
	void InitAct();
	void InitSelectTarget();
public:
	GameScene(vector <Character*> vSide1Characters, vector <Character*> vSide2Characters, Map StageMap);
	~GameScene();

	void Init();
	void Update();
};

