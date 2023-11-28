/**
 * @file Machine.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "Machine.h"
#include "Component.h"

/**
 * Constructor
 */
Machine::Machine(int machine)
{
    mMachine = machine;
}

/**
* Draw the machine at the currently specified location
* @param graphics Graphics object to render to
*/
void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for (auto component : mComponents)
    {
        component->Draw(graphics,0,0);
    }
}

void Machine::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetMachine(this);
}
