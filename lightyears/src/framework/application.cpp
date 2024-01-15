#include "framework/application.h"

namespace LightYear
{
    Application::Application()
        : window{sf::VideoMode(100,100), "Light year"}
    {
    }

    void Application::Run()
    {
        sf::Event windowEvent;
        while (window.isOpen())
        {
            while (window.pollEvent(windowEvent))
            {
                if (windowEvent.type == sf::Event::EventType::Closed)
                {
                    window.close();
                }
            }
        }
    }
}