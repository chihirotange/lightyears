#pragma once
#include "framework/Object.h"
#include "framework/Core.h"

namespace AiEngine
{
    class Actor;
    class Component : public Object 
    {
    public:
        Component(Actor* Owner);
        void Tick(float deltaTime);
        void Render();
        void BeginPlay();

        ~Component();

    private:
        Actor* owner;
    };
} // namespace AiEngine
