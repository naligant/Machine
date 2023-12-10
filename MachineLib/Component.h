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
class Component
{
private:
    cse335::PhysicsPolygon* mPolygon;
    bool mPhysics;
    Machine* mMachine = nullptr;
public:
    /**
     * Updates the machines
     * @param elapsed
     */
    virtual void Update(double elapsed);
    /**
     * Draws the components
     * @param graphics
     * @param x
     * @param y
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    /**
     * Sets the angle at which it rotates
     * @param rotation
     */
    virtual void SetRotation(double rotation);
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

//    wxPoint GetMachinePosition() {return mMachine->GetLocation();}

    std::shared_ptr<ContactListener> GetContactListener() {return mMachine->GetContactListener();};


};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
