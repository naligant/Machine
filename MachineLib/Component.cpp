/**
 * @file Component.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "Component.h"
#include "Machine.h"

/**
 * Sets the machine
 * @param machine
 */
void Component::SetMachine(Machine *machine)
{
    mMachine = machine;
}

/**
 * Virtual draw function
 * @param graphics
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
}
/**
 * Updates the machines
 * @param elapsed
 */
void Component::Update(double elapsed)
{
    mMachine->Update(elapsed);
}

/**
 * Sets the speed of the component
 * @param speed
 */
void Component::SetSpeed(double speed)
{

}

/**
 * resets entire machine
 */
void Component::Reset()
{
}

/**
 * Virtual function to install physics
 * @param world
 */
void Component::InstallPhysics(std::shared_ptr<b2World> world)
{

}