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
    };
}
