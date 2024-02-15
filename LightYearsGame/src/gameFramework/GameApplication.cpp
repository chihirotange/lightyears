#include "framework/Application.h"
#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

#include "framework/component/SpriteRendererComponent.h"

AiEngine::Application* GetApplication()
{
    return new LightYear::GameApplication{};
}

namespace LightYear
{
    GameApplication::GameApplication()
    {
        weak<AiEngine::World> newWorld = LoadWorld<AiEngine::World>();
        weak<AiEngine::Actor> actor = newWorld.lock()->SpawnActor<AiEngine::Actor>();
        weak<AiEngine::SpriteRendererComponent> component = actor.lock()->CreateComponent<AiEngine::SpriteRendererComponent>();
        component.lock()->SetTexture("D:/Downloads/assets/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
    }
}