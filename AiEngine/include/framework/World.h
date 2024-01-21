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

        template <typename ActorType>
        weak<ActorType> SpawnActor();        

        void Tick(float deltaTime);
        void BeginPlay();

    private:
        bool bIsAlreadyBegin;

        List<shared<Actor>> allActors;
        List<shared<Actor>> pendingActors;
    };

    template <typename ActorType>
    weak<ActorType> World::SpawnActor()        
    {
        shared<ActorType> newActor {new ActorType{}};
        pendingActors.push_back(newActor);
        return newActor;
    }
}