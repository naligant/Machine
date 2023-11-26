/**
 * @file MachineSystemActual.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEMACTUAL_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEMACTUAL_H
#include "IMachineSystem.h"
class MachineSystemActual : public IMachineSystem
{
private:
    wxPoint mLocation;
    double mFrameRate;
    double mTime;
    int mFlag;
    int mFrame;
    int mMachine;

public:
    /**
     * sets location of machine
     * @param point
     */
    void SetLocation(wxPoint point) override {mLocation = point;}

    /**
     * Gets location of machine
     * @return location
     */
    wxPoint GetLocation() override {return mLocation;}

    /**
     * Draws the actual machine
     * @param graphics
     */
    void DrawMachine (std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Sets the frame rate
     * @param rate
     */
    void SetFrameRate(double rate) override {mFrameRate = rate;}

    /**
     * Gets the time of the machine
     * @return
     */
    double GetMachineTime() override {return mTime;}

    /**
     * Sets the flag for machine
     * @param flag
     */
    void SetFlag(int flag) override {mFlag = flag;}

    /**
     * Sets the machine frame
     * @param frame
     */
    void SetMachineFrame(int frame) override {mFrame = frame;}

    /**
     * Sets the machine number
     * @param machine
     */
    void SetMachineNumber(int machine) override {mMachine = machine;}







};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEMACTUAL_H
