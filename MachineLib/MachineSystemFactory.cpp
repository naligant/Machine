/**
 * @file MachineSystemFactory.cpp
 *
 * @author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "pch.h"
#include "MachineSystemFactory.h"
#include "MachineSystemStandin.h"
#include "MachineSystemActual.h"
#include "MachineCFactory.h"

/**
 * Constructor
 * @param resourcesDir Directory to load resources from
 */
MachineSystemFactory::MachineSystemFactory(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{
}


/**
 * Create a machine system object
 *
 * Do not change the return type of this function!
 *
 * @return Object of type IMachineSystem
 */
std::shared_ptr<IMachineSystem> MachineSystemFactory::CreateMachineSystem()
{
    auto machineSystem =  std::make_shared<MachineSystemActual>();
    // Create and add Machine
    MachineCFactory machineCFactory(mResourcesDir);
    auto machine = machineCFactory.Create();

    wxPoint point = wxPoint(0,0);
    machineSystem->SetLocation(point);

    machineSystem->SetMachine(machine);
    return machineSystem;
}


