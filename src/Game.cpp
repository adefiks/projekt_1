#include "Game.h"
#include "TextureManager.h"
#include "Gameobject.h"
#include "Game_Map.h"

Gameobject *player;
Gameobject *enemy;
Game_Map *map;

SDL_Renderer *Game::renderer = nullptr;

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
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "renderer created!" << endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    player = new Gameobject("assets/player.png", 70, 70);
    enemy = new Gameobject("assets/enemy.png", 0, 0);

    map = new Game_Map();
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
    player->Update();
    enemy->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    // stuff to render
    map->DrawMap();
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "game clened!" << endl;
}
