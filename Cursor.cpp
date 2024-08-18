#include "Cursor.h"



Cursor::Cursor()
{
}


Cursor::~Cursor()
{
}

void Cursor::SetPosition(int X, int Y)
{
	Position.iX = X;
	Position.iY = Y;
}

Coordinate Cursor::GetPostion()
{
	return Position;
}

void Cursor::SetLimit(int MinX, int MaxX, int MinY, int MaxY)
{
	iMinX = MinX;
	iMaxX = MaxX;
	iMinY = MinY;
	iMaxY = MaxY;
}

void Cursor::MoveLeft()
{
	if (Position.iX != iMinX)
	{
		Position.iX--;
	}
}

void Cursor::MoveRight()
{
	if (Position.iX != iMaxX)
	{
		Position.iX++;
	}
}

void Cursor::MoveUp()
{
	if (Position.iY != iMinY)
	{
		Position.iY--;
	}
}

void Cursor::MoveDown()
{
	if (Position.iY != iMaxY)
	{
		Position.iY++;
	}
}

void Cursor::Erase()
{
	setcolor(WHITE);

	int MinX = (Position.iX - 1) * 35;
	int MaxX = (Position.iX) * 35;
	int MinY = (Position.iY - 1) * 35;
	int MaxY = (Position.iY) * 35;

	line(MinX, MinY, MinX + 10, MinY);
	line(MaxX, MinY, MaxX - 10, MinY);

	line(MinX, MaxY, MinX + 10, MaxY);
	line(MaxX, MaxY, MaxX - 10, MaxY);

	line(MinX, MinY, MinX, MinY + 10);
	line(MinX, MaxY, MinX, MaxY - 10);

	line(MaxX, MinY, MaxX, MinY + 10);
	line(MaxX, MaxY, MaxX, MaxY - 10);
}

void Cursor::Draw()
{
	setcolor(BLACK);

	setlinestyle(SOLID_LINE, 0xFFFF, 3);

	int MinX = (Position.iX - 1) * 35;
	int MaxX = (Position.iX) * 35;
	int MinY = (Position.iY - 1) * 35;
	int MaxY = (Position.iY) * 35;

	line(MinX, MinY, MinX + 10, MinY);
	line(MaxX, MinY, MaxX - 10, MinY);

	line(MinX, MaxY, MinX + 10, MaxY);
	line(MaxX, MaxY, MaxX - 10, MaxY);

	line(MinX, MinY, MinX, MinY + 10);
	line(MinX, MaxY, MinX, MaxY - 10);

	line(MaxX, MinY, MaxX, MinY + 10);
	line(MaxX, MaxY, MaxX, MaxY - 10);

	setcolor(WHITE);
}
