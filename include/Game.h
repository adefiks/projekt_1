/*
!!! Game.h !!!
    * main class for all object in game
*/
#ifndef GAME_H
#define GAME_H

#include "common.h"

// Forward declaration
class ColliderComponent;

//  main class for all object in game
class Game
{
private:
  SDL_Window *window;

  int cnt = 0;

public:
  Game();
  ~Game();
  void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() { return isRunning; };

  // static void AddTitle(int src_x, int src_y, int x, int y);
  static SDL_Renderer *renderer;
  static SDL_Event event;
  // static vector<ColliderComponent *> colliders;

  static bool isRunning;
  static SDL_Rect camera;

  enum groupLabels : size_t
  {
    groupMap,
    groupPlayer,
    groupEnemy,
    groupCollider
  };
};

#endif /* GAME_H */