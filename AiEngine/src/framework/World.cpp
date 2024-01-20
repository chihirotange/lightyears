#include "framework/World.h"

namespace AiEngine
{
    World::World()
        : bIsAlreadyBegin {false}
    {
    }
    World::~World()
    {
    }
    void World::TickInternal(float deltaTime)
    {
        Tick(deltaTime);
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
    }
    void World::BeginPlay()
    {
    }
}