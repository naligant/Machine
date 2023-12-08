/**
 * @file MachineAdapter.cpp
 * @author Prajeeth Naliganti
 */

#include "MachineAdapter.h"

void MachineAdapter::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachineSystem->DrawMachine(graphics);
}

bool MachineAdapter::HitTest(wxPoint pos)
{
//    int machineX = pos.x - mPlacedPosition.x;
//    int machineY = pos.y - mPlacedPosition.y;
//    wxPoint point = wxPoint()
//
//    return mMachineSystem->SetLocation(machineX, machineY);
    //return true;
}

void MachineAdapter::SetPosition(wxPoint pos)
{
    mMachineSystem->SetLocation(GetPosition());
}