#include "framework/Core.h"
#include "framework/Actor.h"
#include "framework/component/SpriteRendererComponent.h"

namespace AiEngine
{
    SpriteRendererComponent::SpriteRendererComponent(Actor* Owner) : Component(Owner)
    {
    }
    SpriteRendererComponent::~SpriteRendererComponent()
    {
        LOG("SPRITE RENDERER DESTROYED");
    }
    void SpriteRendererComponent::BeginPlay()
    {
        LOG("sprite renderer beginplay");
    }

    void SpriteRendererComponent::Render(const sf::RenderWindow &renderWindow)
    {
    }
} // namespace AiEngine