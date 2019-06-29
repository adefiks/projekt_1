/*
!!! Entity Component System !!!
    * Manager which holds entities, which are anything drawn in your game (all stuff to draw in game (player, enemy, trees etc)).
    * Each entity has components, which give it functionality (like position, move options, physics etc ). 
    * Each component has it's own class, so templates are required in order to get and add components.
 */

#pragma once

#include <common.h>

class Component;
class Entity;

using ComponentID = size_t; // uint

// For geting component ID (first use -> we get 1, sec -> we get 2)
inline ComponentID getComponentTypeID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

// get component Type ID (graphics -> 1, physics -> 2, etc)
template <typename T>
inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr size_t maxComponents = 32;

// bit arrey (bitset) 32 elements <- to compare if it have components
using ComponentBitSet = bitset<maxComponents>;

// arrey of components (32)
using ComponentArray = array<Component *, maxComponents>;

// class for all components (functionality, like position, move options, physics etc )
class Component
{
public:
    Entity *entity; // <- owner

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual ~Component() {}
};

// entity (all stuff to draw in game (player, enemy, trees etc)) holding components which give it functionality
class Entity
{
private:
    bool active = true; // if false <- remove
    vector<unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;

public:
    void update() // updating all components (update then draw)
    {
        for (auto &c : components) // updating all components in entity
        {
            c->update();
        }

        for (auto &c : components) // draw all components
        {
            c->draw();
        }
    }

    void draw() {}
    bool isActive() { return active; }
    void destroy() { active = false; }

    // check for component (ex if it have position component)
    template <typename T>
    bool hasComponent() const
    {
        return componentBitSet[getComponentTypeID<T>];
    }

    template <typename T, typename... TArgs>
    T &addComponent(TArgs &&... mArgs)
    {
        T *c(new T(forward<TArgs>(mArgs)...));
        c->entity = this;
        unique_ptr<Component> uPtr{c};       // for temp component
        components.emplace_back(move(uPtr)); // put component back

        componentArray[getComponentTypeID<T>()] = c;     // if we put position component it will be in the same spot
        componentBitSet[getComponentTypeID<T>()] = true; // set bitset to true (it have this component)

        c->init();
        return *c;
    }

    template <typename T>
    T &getComponent() const
    {
        auto ptr(componentArray[getComponentTypeID<T>()]); // geting the component from component array
        return *static_cast<T *>(ptr);
    }
};

// manager holds entitys (all stuff in game (player, enemy etc))
class Manager
{
private:
    vector<unique_ptr<Entity>> entities; // vector for all entities

public:
    void update() // update all entities
    {
        for (auto &e : entities)
        {
            e->update();
        }
    }

    void draw() // draw all entites
    {
        for (auto &e : entities)
        {
            e->draw();
        }
    }

    void refresh() // is deleting not active entities
    {
        // remove_if <- algorithm lib
        entities.erase(remove_if(begin(entities), end(entities), [](const unique_ptr<Entity> &mEntity) { return !mEntity->isActive(); }), end(entities));
    }

    Entity &addEntity()
    {
        Entity *e = new Entity();
        unique_ptr<Entity> uPtr{e};
        entities.emplace_back(move(uPtr));
        return *e;
    }
};
