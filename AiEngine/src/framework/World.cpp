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
        for (shared<Actor> actor : allActors)
        {
            actor->Tick(deltaTime);
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
    void World::BeginPlay()
    {
        LOG("World begin play");
    }
}