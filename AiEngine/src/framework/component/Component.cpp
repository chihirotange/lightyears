#include "SFML/Graphics.hpp"
#include "framework/component/Component.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace AiEngine
{
    Component::Component(Actor* Owner)
    : owner {Owner}
    {
    }

    Component::~Component()
    {
    }

    void Component::BeginPlay()
    {
    }

    void Component::Tick(float deltaTime)
    {
    }

    void Component::Render(const sf::RenderWindow &renderWindow)
    {
    }
}