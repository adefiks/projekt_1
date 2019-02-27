#include "include/Game.h"

SDL_Texture *playertxt;
SDL_Rect scrR, destR;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsystem Initialised!" << endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            cout << "window created!" << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
            cout << "renderer created!" << endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    SDL_Surface *tmpSurface = IMG_Load("assets/player.png");
    playertxt = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }
}

void Game::update()
{
    cnt++;
    destR.h = 64;
    destR.w = 64;

    destR.x = cnt;
    cout << cnt << endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    // stuff to render
    SDL_RenderCopy(renderer, playertxt, NULL, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "game clened!" << endl;
}
