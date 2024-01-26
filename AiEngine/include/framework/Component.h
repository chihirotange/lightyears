#include "framework/Object.h"

namespace AiEngine
{
    class Component : Object 
    {
    public:
        Component();
        void Tick(float deltaTime);
        void Render();
        void BeginPlay();
        ~Component();

    private:
        
    };
} // namespace AiEngine
