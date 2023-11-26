/**
 * @file Machine.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
class MachineSystemActual;
class Component;
class Machine
{
private:
     int mMachine;

public:
    /**
     * Adds component to machine
     * @param component
     */
    void AddComponent(Component* component);
    /**
     * Draws machine
     * @param graphics
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    /**
     * Updates machine
     * @param elapsed
     */
    void Update(double elapsed);
    /**
     * resets machine
     */
    void Reset();

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
