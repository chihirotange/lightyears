#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace AiEngine
{
    World::World()
        : bIsAlreadyBegin {false},
        allActors{},
        pendingActors{}
    {
    }
    World::~World()
    {
        LOG("World destroyed");
    }
    void World::TickInternal(float deltaTime)
    {
        for (shared<Actor> actor : pendingActors)
        {
            allActors.push_back(actor);
            actor->BeginPlay();
        }
        pendingActors.clear();

        Tick(deltaTime);
        for (auto iter = allActors.begin(); iter != allActors.end(); )
        {
            Actor* actor = iter->get(); 
            if (actor->IsPendingDestroy())
            {
                iter = allActors.erase(iter);
            }
            else
            {
                actor->Tick(deltaTime);
                ++iter;
            }
        }
    }

    void World::BeginPlayInternal()
    {
        if (!bIsAlreadyBegin)
        {
            BeginPlay();
            bIsAlreadyBegin = true;
        }
    }
    void World::Tick(float deltaTime)
    {
        LOG("World ticking");
    }

    void World::Render(sf::RenderWindow &renderWindow)
    {
        for (auto actor : allActors)
        {
            actor->Render(renderWindow);
        }
    }
    void World::BeginPlay()
    {
        LOG("World begin play");
    }
}