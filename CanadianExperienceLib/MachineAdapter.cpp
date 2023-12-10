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
    double scale = 0.60f;
    graphics->PushState();
    //graphics->Translate(mLocation.x, mLocation.y);
    graphics->Scale(scale, scale);
    //MachineSystem::SetLocation(wxPoint(0, 0));
    mMachineSystem->DrawMachine(graphics);
    graphics->PopState();
    //mMachineSystem->DrawMachine(graphics);
}

bool MachineAdapter::HitTest(wxPoint pos)
{
    return false;
}

void MachineAdapter::SetPosition(wxPoint pos)
{
    mLocation = pos;
    mMachineSystem->SetLocation(pos);
}
void MachineAdapter::ShowDialogBox(wxWindow* mainFrame)
{
    MachineDialog dlg(mainFrame, mMachineSystem);
    mMachineSystem->SetLocation(mLocation);
    //auto loc = mMachineSystem->GetLocation();
    if (dlg.ShowModal() == wxID_OK)
    {
        auto loc = mMachineSystem->GetLocation();
        // A machine has been selected
//        dlg.SetPosition(mLocation);

    }
}
void MachineAdapter::SetMachineNumber(int machine)
{
    mMachineSystem->SetMachineNumber(machine);
}