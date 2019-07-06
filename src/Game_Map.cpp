
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

    int src_x, src_y;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            mapFile.get(tile);
            src_y = atoi(&tile) * 32;
            mapFile.get(tile);
            src_x = (atoi(&tile) - 1) * 32;

            Game::AddTitle(src_x, src_y, j * 64, i * 64);

            mapFile.ignore();
        }
    }

    mapFile.close();
}