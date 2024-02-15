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
        InternalBeginPlay();
        bIsAlreadyBegin = true;
    }

    void Actor::Tick(float deltaTime)
    {
        InternalTick(deltaTime);
    }

    void Actor::Render(const sf::RenderWindow &renderWindow)
    {
        InternalRender(renderWindow);
    }

    void Actor::InternalBeginPlay()
    {
        LOG("ACTOR BEGIN PLAY");
        for (auto component : pendingComponents)
        {
            allComponents.push_back(component);
            component->BeginPlay();
        }
        pendingComponents.clear();
    }

    void Actor::InternalTick(float deltaTime)
    {
        LOG("ACTOR TICK");
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

    void Actor::InternalRender(const sf::RenderWindow &renderWindow)
    {
        LOG("ACTOR RENDER");
        for (auto component : allComponents)
        {
            component->Render(renderWindow);
        }
    }
}