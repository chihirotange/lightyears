#pragma once
#include "framework/Object.h"
#include "framework/Core.h"

namespace AiEngine
{
    class Actor;

    //@TODO make this abstract
    class Component : public Object 
    {
    public:
        Component(Actor* Owner);
        virtual void Tick(float deltaTime);
        virtual void Render();
        virtual void BeginPlay();

        virtual ~Component();

    protected:
        Actor* owner;
    };
} // namespace AiEngine
