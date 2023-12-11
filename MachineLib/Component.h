/**
 * @file Component.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#define CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#include <b2_world.h>
#include "PhysicsPolygon.h"
#include "Machine.h"
/**
 * Abstract class for components in machine
 */
class Component
{
private:
    ///pointer to machine
    Machine* mMachine = nullptr;
public:
    /**
     * Updates the machines
     * @param elapsed
     */
    virtual void Update(double elapsed);
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    /**
     * resets entire machine
     */
    virtual void Reset();
    /**
     * Sets the speed of the component
     * @param speed
     */
    virtual void SetSpeed(double speed);
    void SetMachine(Machine *machine);
    virtual void InstallPhysics(std::shared_ptr<b2World> world);
    /**
     * Gets contact listener from machine
     * @return contactlistener
     */
    std::shared_ptr<ContactListener> GetContactListener() {return mMachine->GetContactListener();};


};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
