/**
 * @file Component.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "Component.h"
#include "Machine.h"

void Component::SetMachine(Machine *machine)
{
    mMachine = machine;
}

//void Component::SetImage(const std::wstring &filename)
//{
//}

void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
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
     * Sets the angle at which it rotates
     * @param rotation
     */
void Component::SetRotation(double rotation)
{

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

void Component::InstallPhysics(std::shared_ptr<b2World> world)
{

}