// main project 06.02.2019

#include "include/main.h"

// Game *game = nullptr;

int WinMain(int argc, char *argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    uint32_t frameStart;
    int frameTime;
    Game game;

    game.init("first engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game.running())
    {
        frameStart = SDL_GetTicks();

        game.handleEvents();
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game.clean();

    int x;
    cin >> x;

    return 0;
}

// old
// if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
// {
//     SDL_Window *window = SDL_CreateWindow("tytu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
//     SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
//     SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//     SDL_RenderClear(renderer);
//     SDL_RenderPresent(renderer);
// }