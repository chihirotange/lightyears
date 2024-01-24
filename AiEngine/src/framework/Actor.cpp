#include "framework/Actor.h"
#include "framework/Core.h"

namespace AiEngine
{
    Actor::Actor()
        : bIsAlreadyBegin {false}
    {
    }

    void Actor::Tick(float deltaTime)
    {
        InternalTick(deltaTime);
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

    void Actor::InternalBeginPlay()
    {
        LOG("ACTOR BEGIN PLAY");
    }

    void Actor::InternalTick(float deltaTime)
    {
        LOG("ACTOR TICK");
    }
}