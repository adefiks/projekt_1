
#include "Game_Map.h"

Game_Map::Game_Map()
{
}

Game_Map::~Game_Map()
{
}

void Game_Map::LoadMap(string path, int x, int y)
{
    char tile;
    fstream mapFile;
    mapFile.open(path);

    int test;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            mapFile.get(tile);
            Game::AddTitle(j * 32, i * 32, atoi(&tile));

            test = atoi(&tile);
            mapFile.ignore();
        }
    }

    mapFile.close();
}