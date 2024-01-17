#include <iostream>
#include "framework/application.h"

namespace LightYear
{
    Application::Application()
        : window{sf::VideoMode(640,480), "Light year"},
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
                InternalTick(targetDeltatime);
                InternalRender();
            }
        }
    }

    void Application::InternalTick(float deltaTime)
    {
        Tick(deltaTime);
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