#include "framework/Application.h"
#include "gameFramework/GameApplication.h"

AiEngine::Application* GetApplication()
{
    return new LightYear::GameApplication{};
}

namespace LightYear
{
    GameApplication::GameApplication()
    {

    }
}