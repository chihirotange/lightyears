#include "framework/Actor.h"
#include "framework/Core.h"

namespace AiEngine
{
    Actor::Actor()
        : bIsAlreadyBegin {false}
    {
    }

    void Actor::BeginPlay()
    {
        if (bIsAlreadyBegin)
        {
            return;
        }
        InternalBeginPlay();
        bIsAlreadyBegin = true;
    }

    void Actor::Tick(float deltaTime)
    {
        InternalTick(deltaTime);
    }

    void Actor::Render()
    {
        InternalRender();
    }

    void Actor::InternalBeginPlay()
    {
        for (auto component : pendingComponents)
        {
            allComponents.push_back(component);
            component->BeginPlay();
        }
        LOG("ACTOR BEGIN PLAY");
    }

    void Actor::InternalTick(float deltaTime)
    {
        LOG("ACTOR TICK");
        for (auto component : allComponents)
        {
            component->Tick(deltaTime);
        }
    }

    void Actor::InternalRender()
    {
        for (auto component : allComponents)
        {
            component->Render();
        }
    }
}