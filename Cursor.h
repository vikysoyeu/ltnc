#pragma once

#include "FireEmblemLib.h"

class Cursor
{
private:
	int iMaxX;
	int iMinX;
	int iMaxY;
	int iMinY;

	Coordinate Position;
public:
	Cursor();
	~Cursor();

	void SetPosition(int X, int Y);
	Coordinate GetPostion();

	void SetLimit(int MinX, int MaxX, int MinY, int MaxY);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void Erase();
	void Draw();
};

