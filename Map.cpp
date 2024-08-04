#include "Map.h"



Map::Map()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			pTerrainList[i][j] = NULL;
		}
	}
}


Map::~Map()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (pTerrainList[i][j] == NULL)
			{
				delete(pTerrainList[i][j]);
			}
		}
	}
}

void Map::SetImage(char * StageMap)
{
	MapImage = strdup(StageMap);
}

Terrain * Map::GetTerrain(int X, int Y)
{
	return pTerrainList[X - 1][Y - 1];
}

void Map::SetTerrain(TerrainType Type, int X, int Y)
{
	Terrain *pNewTerrain;

	switch (Type)
	{
	case PLAIN:
		pNewTerrain = new Plain;
		break;
	case FOREST:
		pNewTerrain = new Forest;
	}

	pTerrainList[X - 1][Y - 1] = pNewTerrain;

	pNewTerrain->SetX(X - 1);
	pNewTerrain->SetY(Y - 1);
}

void Map::Draw()
{
	//readimagefile("Stage1.jpg", 350 - 700 / 2, 350 - 700 / 2, 350 + 700/2, 350 + 700/2);

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			pTerrainList[i][j]->Draw();
		}
	}

	setcolor(WHITE);

	setlinestyle(SOLID_LINE, 0xFFFF, 3);

	for (int i = 0; i <= 700; i += 35)
	{
		line(i, 0, i, 700);
	}
	for (int i = 0; i <= 700; i += 35)
	{
		line(0, i, 700, i);
	}
}
