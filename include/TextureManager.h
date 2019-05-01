#pragma once
#include "game.h"

class TextureManager
{
private:
  /* data */
public:
  static SDL_Texture *LoadTexture(const char *fileName);
};
