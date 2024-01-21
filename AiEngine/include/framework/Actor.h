namespace AiEngine
{
    class Actor
    {
    public:
        Actor();
        void InternalTick(float deltaTime);
        void InternalBeginPlay();

    protected:
        virtual void Tick(float deltaTime);
        virtual void BeginPlay();

    private:
        bool bIsAlreadyBegin; 
    };
}