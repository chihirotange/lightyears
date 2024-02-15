#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"


namespace AiEngine
{
    class World;
    class Application
    {
    public:
        Application();
        void Run();
        virtual void Tick(float deltaTime);
        virtual void Render();
        template<class World>        
        weak<World> LoadWorld();

    private:
        sf::RenderWindow window;
        float targetFrameRate;
        sf::Clock tickClock;
        shared<World> currentWorld;
    };

    template<class World>
    weak<World> Application::LoadWorld()
    {
        shared<World> newWorld{new World{}};
        currentWorld = newWorld;
        return newWorld;
    }
}
