/**
 * @file Component.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#define CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
class Machine;
class Component
{
private:
    bool mPhysics;
    wxPoint mPosition;
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
    /**
     * Sets position of component
     * @param point
     */
    virtual void SetPosition(wxPoint point) {mPosition = point;}
    /**
     * Sets the image of component
     */
    virtual void SetImage();
    /**
     * Sets the speed of the component
     * @param speed
     */
    virtual void SetSpeed(double speed);
};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
