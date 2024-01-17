#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{
    AiEngine::Application* app = GetApplication();
    app->Run();

    delete app;
}