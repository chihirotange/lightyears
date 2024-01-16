#include <SFML/Graphics.hpp>

namespace LightYear
{
    class Application
    {
    public:
        Application();

        void Run();
    private:
        sf::RenderWindow window;
        float targetFrameRate;
        sf::Clock tickClock;

        void Tick(float deltaTime);
        void Render();
    };
}