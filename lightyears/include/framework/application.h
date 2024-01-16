#include <SFML/Graphics.hpp>

namespace LightYear
{
    class Application
    {
    public:
        Application();

        void Run();

        virtual void Tick(float deltaTime);
        virtual void Render();
    private:
        sf::RenderWindow window;
        float targetFrameRate;
        sf::Clock tickClock;

        void InternalTick(float deltaTime);
        void InternalRender();
    };
}