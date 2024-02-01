#pragma once
namespace AiEngine
{
    class Object
    {
    public:
        Object();
        ~Object();

        bool IsPendingDestroy();

        void Destroy();

    private:
        bool isPendingDestroy;
    };

    //better style
    inline bool Object::IsPendingDestroy()
    {
        return isPendingDestroy;
    }
}