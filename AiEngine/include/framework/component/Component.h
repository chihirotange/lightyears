#pragma once
#include "SFML/Graphics.hpp"
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
        virtual void Render(const sf::RenderWindow &renderWindow);
        virtual void BeginPlay();

        virtual ~Component();

    protected:
        Actor* owner;
    };
} // namespace AiEngine
