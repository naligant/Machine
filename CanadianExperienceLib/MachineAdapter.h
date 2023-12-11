/**
 * @file MachineAdapter.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEADAPTER_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEADAPTER_H
#include "Drawable.h"
#include <machine-api.h>
/**
 * Adapter from machinelib to canadianlib
 */
class MachineAdapter : public Drawable
{
private:
    std::shared_ptr<IMachineSystem> mMachineSystem;
    wxPoint mLocation = wxPoint(0,0);
    Timeline* mTimeline;
    int mStartFrame = 0;
    int mEndFrame = 0;

public:
    MachineAdapter(const std::wstring& name, const std::wstring resourcesDir);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool HitTest(wxPoint pos) override;
    void SetPosition(wxPoint pos);
    void Load(const wxString& filename);
    void Save(const wxString& filename);
    void ShowDialogBox(wxWindow* mainFrame);
    void SetMachineNumber(int machine);
    void SetTimeline(Timeline* timeline) override;
    void SetMachineFrame(int frame);
    void StartFrame(int frame) {mStartFrame = frame;}
    void EndFrame(int frame) {mEndFrame = frame;}
//    void SetKeyframe() override;
//    void GetKeyframe() override;
//    double GetMachineTime();

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEADAPTER_H
