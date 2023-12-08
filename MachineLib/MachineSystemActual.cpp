/**
 * @file MachineSystemActual.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "MachineSystemActual.h"
#include "Machine.h"
#include "MachineCFactory.h"
#include "Machine1Factory.h"
#include "HamsterAndConveyorFactory.h"
#include "MachineSystemFactory.h"


MachineSystemActual::MachineSystemActual(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{
    SetMachineNumber(1);
//    mResourcesDir = resourcesDir;
}

/**
* Set the position for the root of the machine
* @param location The x,y location to place the machine
*/
void MachineSystemActual::SetLocation(wxPoint location)
{
    mMachine->SetLocation(location);
}

/**
 * Get the location of hte machine
 * @return Location x,y in pixels as a point
 */
wxPoint MachineSystemActual::GetLocation()
{
    return mMachine->GetLocation();
}

/**
* Draw the machine at the currently specified location
* @param graphics Graphics object to render to
*/
void MachineSystemActual::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
/// How many pixels there are for each CM
    double mPixelsPerCentimeter = 1.5;

    graphics->PushState();
    graphics->Translate(mMachine->GetLocation().x, mMachine->GetLocation().y);
    graphics->Scale(mPixelsPerCentimeter, -mPixelsPerCentimeter);

    // Draw your machine assuming an origin of 0,0
    mMachine->Draw(graphics);

//    graphics->SetPen(*wxRED_PEN);
//    graphics->StrokeLine(-300, 0, 300, 0);
//    graphics->StrokeLine(0, 0, 0, 25);
//    graphics->StrokeLine(-300, 0, -300, 300);
//    graphics->StrokeLine(300, 0, 300, 300);


    graphics->PopState();

}

/**
* Set the current machine animation frame
* @param frame Frame number
*/
void MachineSystemActual::SetMachineFrame(int frame)
{
    if(frame < mFrame)
    {
        mFrame = 0;
        mMachine->Reset();
    }

    for( ; mFrame < frame;  mFrame++)
    {
        mMachine->Update(1.0 / mFrameRate);
    }
    mMachine->SetMachineFrame(frame);
}

/**
* Set the machine number
* @param machine An integer number. Each number makes a different machine
*/
void MachineSystemActual::SetMachineNumber(int machine)
{
   if (machine == 1)
   {
       MachineCFactory machine(mResourcesDir);
       mMachine = machine.Create();
       mMachine->Reset();
   }
   else if (machine == 2)
   {
       Machine1Factory machine(mResourcesDir);
       mMachine = machine.Create();
       mMachine->Reset();
   }

}

/**
 * Get the current machine number
 * @return Machine number integer
 */
int MachineSystemActual::GetMachineNumber()
{
    return mMachine->GetMachine();
}

/**
 * Get the current machine time.
 * @return Machine time in seconds
 */
double MachineSystemActual::GetMachineTime()
{
    return 0;
}