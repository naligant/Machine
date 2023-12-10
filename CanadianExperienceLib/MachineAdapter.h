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
class MachineAdapter : public Drawable
{
private:
    std::shared_ptr<IMachineSystem> mMachineSystem;
    wxPoint mLocation = wxPoint(0,0);
    int mStartTime = 0;
public:
    MachineAdapter(const std::wstring& name, const std::wstring resourcesDir);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool HitTest(wxPoint pos) override;
    void SetPosition(wxPoint pos);
    void Load(int machineID);
    void Save(int machineID);
    void ShowDialogBox(wxWindow* mainFrame);
    void SetMachineNumber(int machine);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEADAPTER_H
