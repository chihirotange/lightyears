#pragma once
#include "SFML/Graphics.hpp"
#include "framework/Core.h"
#include "framework/Object.h"
#include "framework/component/Component.h"
namespace AiEngine
{
    // class Component;
    class Actor : public Object
    {
    public:
        Actor();
        void Tick(float deltaTime);
        void BeginPlay();
        void Render(sf::RenderWindow &renderWindow);
        virtual ~Actor();

        template<class Component>
        weak<Component> CreateComponent();

    private:
        bool bIsAlreadyBegin; 
        List<shared<Component>> pendingComponents;
        List<shared<Component>> allComponents;
    };

    template<class Component>
    weak<Component> Actor::CreateComponent()
    {
        shared<Component> newComponent{new Component{this}};
        pendingComponents.push_back(newComponent);
        return newComponent;
    }
}