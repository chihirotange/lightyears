#include "framework/Core.h"
#include "framework/Object.h"

namespace AiEngine
{
    Object::Object()
        : isPendingDestroy {false}
    {
    }

    Object::~Object()
    {
    }

    void Object::Destroy()
    {
        isPendingDestroy = true;
    }
}