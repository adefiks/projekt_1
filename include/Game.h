#include "common.h"

class Game
{
  private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

  public:
    Game(/* args */);
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; };
};

Game::Game(/* args */)
{
}

Game::~Game()
{
}
