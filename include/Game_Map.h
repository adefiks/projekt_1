#pragma once
#include "Game.h"

class Game_Map
{
private:
    SDL_Rect src, dest;

    SDL_Texture *water;
    SDL_Texture *dirt;
    SDL_Texture *grass;

    int map[20][25];

public:
    Game_Map();
    ~Game_Map();

    void LoadMap(int arr[20][25]);
    void DrawMap();
};
