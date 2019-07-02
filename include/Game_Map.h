#pragma once
#include "common.h"
#include "Game.h"

class Game_Map
{
private:
public:
    Game_Map();
    ~Game_Map();

    static void LoadMap(string path, int x, int y);
};
