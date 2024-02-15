#pragma once
#include "framework/component/Component.h"
namespace AiEngine
{
    class SpriteRendererComponent : public Component
    {
    public:
        SpriteRendererComponent(Actor* Owner);
        ~SpriteRendererComponent();
        void BeginPlay() override;
        void Render(sf::RenderWindow &renderWindows) override;

        bool SetTexture(const std::string &texturePath);

    private:
        sf::Sprite sprite;
        sf::Texture texture;
    };
}
