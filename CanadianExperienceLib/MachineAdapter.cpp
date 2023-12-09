/**
 * @file MachineAdapter.cpp
 * @author Prajeeth Naliganti
 */

#include "MachineAdapter.h"

MachineAdapter::MachineAdapter(const std::wstring& name, const std::wstring resourcesDir) : Drawable(name)
{
    MachineSystemFactory factory(resourcesDir);
    mMachineSystem = factory.CreateMachineSystem();
}
void MachineAdapter::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachineSystem->SetLocation(mPlacedPosition);
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
    //SetPosition(pos);
    mMachineSystem->SetLocation(pos);
}
