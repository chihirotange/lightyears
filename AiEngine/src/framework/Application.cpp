#include <iostream>

#include "framework/Application.h"
#include "framework/World.h"
#include "framework/Core.h"

namespace AiEngine
{
    Application::Application()
        : window{sf::VideoMode(640,480), "Light year"},
        targetFrameRate{1.f},
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
                Tick(targetDeltatime);
                Render();
            }
        }
    }

    void Application::Tick(float deltaTime)
    {
        if (currentWorld)
        {
            currentWorld->BeginPlay();
            currentWorld->Tick(deltaTime);
        }
    }

    void Application::Render()
    {
        window.clear();
        currentWorld->Render(window);
        window.display();
    }
}
