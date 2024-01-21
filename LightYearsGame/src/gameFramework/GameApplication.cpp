#include "framework/Application.h"
#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

AiEngine::Application* GetApplication()
{
    return new LightYear::GameApplication{};
}

namespace LightYear
{
    GameApplication::GameApplication()
    {
        weak<AiEngine::World> newWorld = LoadWorld<AiEngine::World>();
        newWorld.lock()->SpawnActor<AiEngine::Actor>();
    }
}