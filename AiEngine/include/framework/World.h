#include "framework/Core.h"
namespace AiEngine
{
    class Actor;
    class World 
    {
    public:
        World();
        void TickInternal(float deltaTime);
        void BeginPlayInternal();
        virtual ~World();

        template <class Actor>
        weak<Actor> SpawnActor();        

        void Tick(float deltaTime);
        void BeginPlay();

    private:
        bool bIsAlreadyBegin;

        List<shared<Actor>> allActors;
        List<shared<Actor>> pendingActors;
    };

    template <class Actor>
    weak<Actor> World::SpawnActor()        
    {
        shared<Actor> newActor {new Actor{}};
        pendingActors.push_back(newActor);
        return newActor;
    }
}