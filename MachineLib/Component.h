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
     * Determines if an object requires physics or not
     * @return
     */
    virtual bool IsPhysics() {return mPhysics;}
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
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
    /**
     * Sets the angle at which it rotates
     * @param rotation
     */
    virtual void SetRotation(double rotation);
    /**
     * resets entire machine
     */
    virtual void Reset();
//    /**
//     * Sets position of component
//     * @param point
//     */
//    virtual void SetPosition(wxPoint point) {mMachine = point;}
    /**
     * Sets the image of component
     */
    virtual void SetImage(const std::wstring &filename);
    /**
     * Sets the speed of the component
     * @param speed
     */
    virtual void SetSpeed(double speed);

    void SetMachine(Machine *machine);

    virtual void InstallPhysics(std::shared_ptr<b2World> world);

};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
