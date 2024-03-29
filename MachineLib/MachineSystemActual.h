/**
 * @file MachineSystemActual.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEMACTUAL_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEMACTUAL_H
#include "IMachineSystem.h"
#include "Machine.h"
/**
 * Machine System that derives information from interface
 */
class MachineSystemActual : public IMachineSystem
{
private:
    ///shared pointer to machine
    std::shared_ptr<Machine> mMachine;
    ///resources directory
    std::wstring mResourcesDir;
    ///frame
    int mFrame = 0;
    ///framerate
    int mFrameRate = 30;


public:
    /// Constructor
    MachineSystemActual(std::wstring resourcesDir);

    /// Copy constructor (disabled)
    MachineSystemActual(const MachineSystemActual &) = delete;

    /// Assignment operator
    void operator=(const MachineSystemActual &) = delete;

    /**
     * sets location of machine
     * @param point
     */
    virtual void SetLocation(wxPoint point);

    /**
     * Gets location of machine
     * @return location
     */
    virtual wxPoint GetLocation();

    /**
     * Draws the actual machine
     * @param graphics
     */
    virtual void DrawMachine (std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Sets the frame rate
     * @param rate
     */
    virtual void SetFrameRate(double rate) {mFrameRate = rate;};

    /**
     * Gets the time of the machine
     * @return
     */
    virtual double GetMachineTime();

    /**
     * Sets the flag for machine
     * @param flag
     */
    virtual void SetFlag(int flag) {}

    /**
     * Sets the machine frame
     * @param frame
     */
    virtual void SetMachineFrame(int frame);

    /**
     * Sets the machine number
     * @param machine
     */
    virtual void SetMachineNumber(int machine);

    /**
     * Gets the machine number
     * @return machine number
     */
     virtual int GetMachineNumber();







};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEMACTUAL_H
