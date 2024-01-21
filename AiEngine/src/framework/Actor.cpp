#include "framework/Actor.h"
#include "framework/Core.h"

namespace AiEngine
{
    Actor::Actor()
        : bIsAlreadyBegin {false}
    {
    }

    void Actor::InternalTick(float deltaTime)
    {
        Tick(deltaTime);
    }

    void Actor::InternalBeginPlay()
    {
        BeginPlay();
    }

    void Actor::BeginPlay()
    {
        LOG("ACTOR BEGIN PLAY");
    }

    void Actor::Tick(float deltaTime)
    {
        LOG("ACTOR TICK");
    }
}