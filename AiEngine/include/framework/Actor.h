#include "framework/Object.h"
namespace AiEngine
{
    class Actor : public Object
    {
    public:
        Actor();
        void Tick(float deltaTime);
        void BeginPlay();

    protected:
        virtual void InternalTick(float deltaTime);
        virtual void InternalBeginPlay();

    private:
        bool bIsAlreadyBegin; 
    };
}