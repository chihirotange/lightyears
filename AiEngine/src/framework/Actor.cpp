#include "SFML/Graphics.hpp"
#include "framework/Actor.h"
#include "framework/component/Component.h"
#include <iostream>
#include "framework/Core.h"

namespace AiEngine
{
    Actor::Actor()
        : bIsAlreadyBegin {false}
    {
    }

    Actor::~Actor()
    {
        LOG("Actor destroyed");
    }

    void Actor::BeginPlay()
    {
        if (bIsAlreadyBegin)
        {
            return;
        }
        bIsAlreadyBegin = true;
    }

    void Actor::Tick(float deltaTime)
    {
        LOG("ACTOR TICK");
        for (auto component : pendingComponents)
        {
            allComponents.push_back(component);
            component->BeginPlay();
        }
        pendingComponents.clear();
        for (auto iter = allComponents.begin(); iter != allComponents.end();)
        {
            Component* component = iter->get();
            if (component->IsPendingDestroy())
            {
                iter = allComponents.erase(iter);
            }
            else
            {
                component->Tick(deltaTime);
                ++iter;
            }
        }
    }

    void Actor::Render(sf::RenderWindow &renderWindow)
    {
        for (auto component : allComponents)
        {
            component->Render(renderWindow);
        }
    }
}