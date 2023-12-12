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
    ///pointer to machine system
    std::shared_ptr<IMachineSystem> mMachineSystem;
    ///location of machine
    wxPoint mLocation = wxPoint(0,0);
    ///pointer to timeline
    Timeline* mTimeline;
    ///start frame
    int mStartFrame = 0;
    ///end frame
    int mEndFrame = 0;

public:
    MachineAdapter(const std::wstring& name, const std::wstring resourcesDir);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool HitTest(wxPoint pos) override;
    void SetPosition(wxPoint pos);
    /**
     * Loads xml
     * @param filename
     */
    void Load(const wxString& filename);
    /**
     * save xml
     * @param filename
     */
    void Save(const wxString& filename);
    void ShowDialogBox(wxWindow* mainFrame);
    void SetMachineNumber(int machine);
    void SetTimeline(Timeline* timeline) override;
    void SetMachineFrame(int frame);
    /**
     * Set start frame
     * @param frame
     */
    void StartFrame(int frame) {mStartFrame = frame;}
    /**
     * Set end frame
     * @param frame
     */
    void EndFrame(int frame) {mEndFrame = frame;}
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEADAPTER_H
