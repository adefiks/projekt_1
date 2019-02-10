#ifndef GAME_H
#define GAME_H

#include "common.h"

class Game
{
private:
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
  int cnt = 0;

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

#endif /* GAME_H */