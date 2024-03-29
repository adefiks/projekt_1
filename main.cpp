// main project 06.02.2019

#include "include/main.h"

int WinMain(int argc, char *argv[])
{
    const int FPS = 120;
    const int frameDelay = 1000 / FPS;

    uint32_t frameStart;
    int frameTime;

    // Game object
    Game game;

    game.init("first engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

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
