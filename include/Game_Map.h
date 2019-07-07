#pragma once
#include "common.h"
#include "Game.h"
#include "ECS.h"
#include "Components.h"

extern Manager manager;

class Game_Map
{
private:
    const char *map_file;
    int map_scale;
    int tile_size;

public:
    Game_Map(const char *imap_file, int imap_scale, int itile_size);
    ~Game_Map();

    void LoadMap(string path, int x, int y);
    void AddTitle(int src_x, int src_y, int x, int y);
};
