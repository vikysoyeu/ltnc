#include "Terrain.h"



Terrain::Terrain()
{
}


Terrain::~Terrain()
{
}

int Terrain::GetMovementCost()
{
	return iMovementCost;
}

void Terrain::SetX(int X)
{
	TerrainCoordinate.iX = X;
}

void Terrain::SetY(int Y)
{
	TerrainCoordinate.iY = Y;
}

void Terrain::SetCoordinate(int X, int Y)
{
	TerrainCoordinate.iX = X;
	TerrainCoordinate.iY = Y;
}

int Terrain::GetX()
{
	return TerrainCoordinate.iX;
}

int Terrain::GetY()
{
	return TerrainCoordinate.iY;
}

Coordinate Terrain::GetCoordinate()
{
	return TerrainCoordinate;
}

TerrainType Terrain::GetTerrainType()
{
	return Type;
}

void Terrain::Draw()
{
	readimagefile(TerrainImage, (TerrainCoordinate.iX * 35 + 17.5) - 37 / 2.0, (TerrainCoordinate.iY * 35 + 17.5) - 37 / 2.0, (TerrainCoordinate.iX * 35 + 17.5) + 37 / 2.0, (TerrainCoordinate.iY * 35 + 17.5) + 37 / 2.0);

	int iMinX = (TerrainCoordinate.iX) * 35;
	int iMinY = (TerrainCoordinate.iY) * 35;
	int iMaxX = (TerrainCoordinate.iX + 1) * 35;
	int iMaxY = (TerrainCoordinate.iY + 1) * 35;

	setcolor(WHITE);

	setlinestyle(SOLID_LINE, 0xFFFF, 3);

	line(iMinX, iMinY, iMaxX, iMinY);
	line(iMinX, iMaxY, iMaxX, iMaxY);
	line(iMinX, iMinY, iMinX, iMaxY);
	line(iMaxX, iMinY, iMaxX, iMaxY);

	line(iMinX, iMinY, iMaxX, iMinY);
	line(iMinX, iMaxY, iMaxX, iMaxY);
	line(iMinX, iMinY, iMinX, iMaxY);
	line(iMaxX, iMinY, iMaxX, iMaxY);
}
