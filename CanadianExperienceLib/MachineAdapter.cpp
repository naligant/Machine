/**
 * @file MachineAdapter.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "MachineAdapter.h"
#include "Timeline.h"

MachineAdapter::MachineAdapter(const std::wstring& name, const std::wstring resourcesDir) : Drawable(name)
{
    MachineSystemFactory factory(resourcesDir);
    mMachineSystem = factory.CreateMachineSystem();
}
void MachineAdapter::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    int machineFrame = 0;
    if (mTimeline->GetCurrentFrame() >= mStartFrame && mTimeline->GetCurrentFrame() <= mEndFrame)
    {
        mMachineSystem->SetMachineFrame(mTimeline->GetCurrentFrame()-mStartFrame);
        double scale = 0.60f;
        graphics->PushState();
        graphics->Scale(scale, scale);
        mMachineSystem->DrawMachine(graphics);
        graphics->PopState();
        machineFrame += 1;

    }
    double scale = 0.60f;
    graphics->PushState();
    graphics->Scale(scale, scale);
    mMachineSystem->DrawMachine(graphics);
    graphics->PopState();
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

void MachineAdapter::SetMachineFrame(int frame)
{
    mMachineSystem->SetMachineFrame(frame);
}

void MachineAdapter::SetTimeline(Timeline* timeline)
{
    Drawable::SetTimeline(timeline);
    mTimeline = timeline;
    mMachineSystem->SetMachineFrame(timeline->GetCurrentFrame());
    mMachineSystem->SetFrameRate(timeline->GetFrameRate());
//    mMachineSystem->GetMachineTime() = timeline->GetCurrentTime();
}

//double MachineAdapter::GetMachineTime()
//{
//    mMachineSystem->GetMachineTime();
//}
//void MachineAdapter::SetKeyframe()
//{
//    Drawable::SetKeyframe();
//    mMachineSystem->SetMachineFrame(1);
//    mMachineSystem->GetMachineTime();
//}
//void MachineAdapter::GetKeyframe()
//{
//    Drawable::GetKeyframe();
//}