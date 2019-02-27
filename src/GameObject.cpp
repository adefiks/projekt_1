#include "Gameobject.h"
#include "TextureManager.h"

Gameobject::Gameobject(const char *textureSheet, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(textureSheet, ren);

    xpos = x;
    ypos = y;
}

Gameobject::~Gameobject()
{
}

void Gameobject::Update()
{
    xpos++;

    srcRect.h = 64;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w * 2;
}

void Gameobject::Render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}