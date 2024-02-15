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

    void SpriteRendererComponent::Render(sf::RenderWindow& renderWindow)
    {
        renderWindow.draw(sprite);
    }

    bool SpriteRendererComponent::SetTexture(const std::string &texturePath)
    {
        texture.loadFromFile(texturePath);
        int textureWidth = texture.getSize().x;
        int textureHeight = texture.getSize().y;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect{sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight}});
        return true;
    }
} // namespace AiEngine