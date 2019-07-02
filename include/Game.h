#ifndef GAME_H
#define GAME_H

#include "common.h"

// Forward declaration
class ColliderComponent;

using namespace std;

class Game
{
private:
  bool isRunning;
  SDL_Window *window;

  int cnt = 0;

  // Gameobject *player;
  // Gameobject *enemy;

public:
  Game();
  ~Game();
  void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() { return isRunning; };

  static SDL_Renderer *renderer;
  static SDL_Event event;
  static vector<ColliderComponent *> colliders;
};

#endif /* GAME_H */