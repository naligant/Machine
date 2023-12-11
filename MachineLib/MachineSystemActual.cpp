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
    mMachine->GetLocation();
}

/**
* Draw the machine at the currently specified location
* @param graphics Graphics object to render to
*/
void MachineSystemActual::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->Draw(graphics);
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
       Machine1Factory machine(mResourcesDir);
       mMachine = machine.Create();
       mMachine->Reset();
   }
   else if (machine == 2)
   {
//       mMachine = std::make_shared<Machine>(2);
//       mMachine->Reset();
       MachineCFactory machine(mResourcesDir);
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