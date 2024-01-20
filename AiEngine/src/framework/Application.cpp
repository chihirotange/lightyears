#include <iostream>

#include "framework/Application.h"
#include "framework/World.h"
#include "framework/Core.h"

namespace AiEngine
{
    Application::Application()
        : window{sf::VideoMode(640,480), "Light year"},
        targetFrameRate{60.f},
        tickClock{},
        currentWorld{nullptr}
    {
    }

    void Application::Run()
    {
        sf::Event windowEvent;
        float accumulatedTime = 0.f;
        float targetDeltatime = 1/targetFrameRate;
        while (window.isOpen())
        {
            while (window.pollEvent(windowEvent))
            {
                if (windowEvent.type == sf::Event::EventType::Closed)
                {
                    window.close();
                }
            }
            float frameDeltaTime = tickClock.restart().asSeconds();
            accumulatedTime += frameDeltaTime;
            while (accumulatedTime > targetDeltatime)
            {
                accumulatedTime -= targetDeltatime;
                InternalTick(targetDeltatime);
                InternalRender();
            }
        }
    }

    void Application::InternalTick(float deltaTime)
    {
        Tick(deltaTime);
        if (currentWorld)
        {
            currentWorld->BeginPlayInternal();
            currentWorld->TickInternal(deltaTime);
        }
    }

    void Application::InternalRender()
    {
        window.clear();
        Render();
        window.display();
    }

    void Application::Tick(float deltaTime)
    {
    }

    void Application::Render()
    {
    }
}
