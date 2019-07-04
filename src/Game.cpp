#include "Game.h"
#include "TextureManager.h"
// #include "Gameobject.h"
#include "Game_Map.h"
#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"

Game_Map *map;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

vector<ColliderComponent *> Game::colliders;

Manager manager;

auto &player(manager.addEntity());
auto &stone(manager.addEntity());

enum groupLabels : size_t
{
    groupMap,
    groupPlayer,
    groupEnemy,
    groupCollider
};

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

    map = new Game_Map();

    Game_Map::LoadMap("assets/map2.map", 16, 16);

    stone.addComponent<TransformComponent>(120, 120, 32, 32, 2);
    stone.addComponent<SpriteComponent>("assets/large_rock.png");
    stone.addComponent<ColliderComponent>("stone");
    stone.addGroup(groupMap);

    player.addComponent<TransformComponent>(70, 70);
    player.addComponent<SpriteComponent>("assets/frame-1.png");
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
    // player->Update();
    // enemy->Update();
    manager.refresh();
    manager.update();

    for (auto cc : colliders)
    {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
}

auto &tiles(manager.getGroup(groupMap));
auto &players(manager.getGroup(groupPlayer));
auto &enemies(manager.getGroup(groupEnemy));
auto &colliders(manager.getGroup(groupCollider));

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

void Game::AddTitle(int x, int y, int ID)
{
    auto &tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, ID);
    tile.addGroup(groupMap);
}
