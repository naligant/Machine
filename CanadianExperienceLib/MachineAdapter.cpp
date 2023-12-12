/**
 * @file MachineAdapter.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "MachineAdapter.h"
#include "Timeline.h"

/**
 * constructor
 * @param name
 * @param resourcesDir
 */
MachineAdapter::MachineAdapter(const std::wstring& name, const std::wstring resourcesDir) : Drawable(name)
{
    MachineSystemFactory factory(resourcesDir);
    mMachineSystem = factory.CreateMachineSystem();
}
/**
 * override for draw function. Draws machines
 * @param graphics
 */
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
/**
 * Hit test
 * @param pos
 * @return
 */
bool MachineAdapter::HitTest(wxPoint pos)
{
    return false;
}
/**
 * set position of machine
 * @param pos
 */
void MachineAdapter::SetPosition(wxPoint pos)
{
    mLocation = pos;
    mMachineSystem->SetLocation(pos);
}
/**
 * dialog box for machine
 * @param mainFrame
 */
void MachineAdapter::ShowDialogBox(wxWindow* mainFrame)
{
    MachineDialog dlg(mainFrame, mMachineSystem);
    mMachineSystem->SetLocation(mLocation);
    if (dlg.ShowModal() == wxID_OK)
    {

    }
}
/**
 * sets machine number
 * @param machine
 */
void MachineAdapter::SetMachineNumber(int machine)
{
    mMachineSystem->SetMachineNumber(machine);
}
/**
 * sets the frame for machine
 * @param frame
 */
void MachineAdapter::SetMachineFrame(int frame)
{
    mMachineSystem->SetMachineFrame(frame);
}
/**
 * sets timeline for machine
 * @param timeline
 */
void MachineAdapter::SetTimeline(Timeline* timeline)
{
    Drawable::SetTimeline(timeline);
    mTimeline = timeline;
    mMachineSystem->SetMachineFrame(timeline->GetCurrentFrame());
    mMachineSystem->SetFrameRate(timeline->GetFrameRate());
}