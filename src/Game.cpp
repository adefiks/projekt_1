#include "Game.h"
#include "TextureManager.h"
// #include "Gameobject.h"
#include "Game_Map.h"
#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"

Game_Map *game_map;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

vector<ColliderComponent *> Game::colliders;

bool Game::isRunning = false;

Manager manager;

SDL_Rect Game::camera = {0, 0, 800, 640};

auto &player(manager.addEntity());
auto &stone(manager.addEntity());

const char *tile_1 = "assets/tiles.png";

enum groupLabels : size_t
{
    groupMap,
    groupPlayer,
    groupEnemy,
    groupCollider
};

auto &tiles(manager.getGroup(groupMap));
auto &players(manager.getGroup(groupPlayer));
auto &enemies(manager.getGroup(groupEnemy));
auto &colliders(manager.getGroup(groupCollider));

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

    game_map = new Game_Map();

    Game_Map::LoadMap("assets/map2.map", 16, 16);

    stone.addComponent<TransformComponent>(280, 320, 32, 32, 4);
    stone.addComponent<SpriteComponent>("assets/large_rock.png");
    stone.addComponent<ColliderComponent>("stone");
    stone.addGroup(groupMap);

    player.addComponent<TransformComponent>(400, 320, 64, 64, 2);
    player.addComponent<SpriteComponent>("assets/goblin.png", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayer);
}

void Game::handleEvents()
{
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

    manager.refresh();
    manager.update();

    camera.x = player.getComponent<TransformComponent>().position.x - 400;
    camera.y = player.getComponent<TransformComponent>().position.y - 320;

    if (camera.x < 0)
        camera.x = 0;

    if (camera.y < 0)
        camera.y = 0;
    if (camera.x > camera.w)
        camera.x = camera.w;
    if (camera.y > camera.h)
        camera.y = camera.h;

    for (auto cc : colliders)
    {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    // stuff to render

    for (auto &t : tiles)
    {
        t->draw();
    }

    for (auto &e : enemies)
    {
        e->draw();
    }

    for (auto &p : players)
    {
        p->draw();
    }

    // manager.draw();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "game clened!" << endl;
}

void Game::AddTitle(int src_x, int src_y, int x, int y)
{
    auto &tile(manager.addEntity());
    tile.addComponent<TileComponent>(src_x, src_y, x, y, tile_1);
    tile.addGroup(groupMap);
}
