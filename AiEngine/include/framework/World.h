namespace AiEngine
{
    class World 
    {
    public:
        World();
        void TickInternal(float deltaTime);
        void BeginPlayInternal();
        virtual ~World();

    protected:
        void Tick(float deltaTime);
        void BeginPlay();

    private:
        bool bIsAlreadyBegin;
    };
}