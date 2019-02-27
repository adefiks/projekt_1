#include "common.h"

class Gameobject
{
  private:
    int xpos;
    int ypos;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;

  public:
    Gameobject(const char *textureSheet, SDL_Renderer *ren, int x, int y);
    ~Gameobject();

    void Update();
    void Render();
};
