#pragma once
#include "Game.h"

class Gameobject
{
private:
  int xpos;
  int ypos;

  SDL_Texture *objTexture;
  SDL_Rect srcRect, destRect;

public:
  Gameobject(const char *textureSheet, int x, int y);
  ~Gameobject();

  void Update();
  void Render();
};
