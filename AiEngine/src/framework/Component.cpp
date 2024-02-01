#include "framework/Component.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace AiEngine
{
    Component::Component(Actor* Owner)
    : owner {Owner}
    {
    }

    void Component::BeginPlay()
    {
        LOG("Component begin play");
    }

    void Component::Tick(float deltaTime)
    {
        LOG("component tick");
    }

    void Component::Render()
    {
        LOG("component render");
    }
}