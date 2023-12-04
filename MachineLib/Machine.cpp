/**
 * @file Machine.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "Machine.h"
#include "Component.h"
#include "ContactListener.h"

/// Gravity in meters per second per second
const float Gravity = -9.8f;

/// Number of velocity update iterations per step
const int VelocityIterations = 6;

/// Number of position update iterations per step
const int PositionIterations = 2;

/**
 * Constructor
 */
Machine::Machine()
{

}
/**
 * Constructor
 */
Machine::Machine(int machine)
{
    mMachine = machine;
    mWorld = std::make_shared<b2World>(b2Vec2(0.0f, Gravity));
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

/**
    * Set the current machine animation frame
    * @param frame Frame number
    */
void Machine::SetMachineFrame(int frame)
{
   mFrame = frame;
}

/**
 * Updates machine
 * @param elapsed
 */
void Machine::Update(double elapsed)
{
    // Call Update on all of our components so they can advance in time
    for (auto component : mComponents)
    {
        component->Update(elapsed);
    }
    // Advance the physics system one frame in time
    mWorld->Step(elapsed, VelocityIterations, PositionIterations);
}

/**
 * resets machine
 */
void Machine::Reset()
{
    mWorld = std::make_shared<b2World>(b2Vec2(0.0f, Gravity));
    // Create and install the contact filter
    mContactListener = std::make_shared<ContactListener>();
    mWorld->SetContactListener(mContactListener.get());
    for (auto component : mComponents)
    {
        component->InstallPhysics(mWorld);
    }



}