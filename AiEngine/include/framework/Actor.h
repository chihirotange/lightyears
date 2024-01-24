namespace AiEngine
{
    class Actor
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