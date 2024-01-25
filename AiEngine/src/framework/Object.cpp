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
        LOG("called object destructor");
    }

    void Object::Destroy()
    {
        isPendingDestroy = true;
    }
}