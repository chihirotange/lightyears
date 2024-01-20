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
        template<typename WorldType>        
        weak<WorldType> LoadWorld();

    private:
        sf::RenderWindow window;
        float targetFrameRate;
        sf::Clock tickClock;
        void InternalTick(float deltaTime);
        void InternalRender();
        shared<World> currentWorld;
    };

    template<typename WorldType>
    weak<WorldType> Application::LoadWorld()
    {
        shared<WorldType> newWorld{new WorldType{}};
        currentWorld = newWorld;
        return newWorld;
    }
}
