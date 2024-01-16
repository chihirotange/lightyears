#include <iostream>
#include "framework/application.h"

namespace LightYear
{
    Application::Application()
        : window{sf::VideoMode(100,100), "Light year"},
        targetFrameRate{60.f},
        tickClock{}
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
            if (accumulatedTime > targetDeltatime)
            {
                accumulatedTime = 0;
                Tick(targetDeltatime);
                Render();
            }
        }
    }

    void Application::Tick(float deltaTime)
    {
    }

    void Application::Render()
    {
    }
}