#include "framework/Core.h"
#include "framework/Object.h"
#include "framework/Component.h"
namespace AiEngine
{
    class Actor : public Object
    {
    public:
        Actor();
        void Tick(float deltaTime);
        void BeginPlay();
        void Render();

    protected:
        virtual void InternalBeginPlay();
        virtual void InternalTick(float deltaTime);
        virtual void InternalRender();

    private:
        bool bIsAlreadyBegin; 
        List<shared<Component>> pendingComponents;
        List<shared<Component>> allComponents;
    };
}