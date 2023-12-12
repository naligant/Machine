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

/**
 * constructor
 * @param resourcesDir
 */
MachineSystemActual::MachineSystemActual(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{
    SetMachineNumber(1);
}

void MachineSystemActual::SetLocation(wxPoint location)
{
    mMachine->SetLocation(location);
}

wxPoint MachineSystemActual::GetLocation()
{
    mMachine->GetLocation();
}

void MachineSystemActual::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->Draw(graphics);
}

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
       MachineCFactory machine(mResourcesDir);
       mMachine = machine.Create();
       mMachine->Reset();
   }

}

int MachineSystemActual::GetMachineNumber()
{
    return mMachine->GetMachine();
}

double MachineSystemActual::GetMachineTime()
{
    return 0;
}