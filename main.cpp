// main project 06.02.2019

#include "include/main.h"

Game *game = nullptr;

int WinMain(int argc, char *argv[])
{
    game = new Game();
    game->init("first engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}