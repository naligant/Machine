/**
 * @file MachineAdapter.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEADAPTER_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEADAPTER_H
#include "Drawable.h"
#include "../MachineLib/IMachineSystem.h"
class MachineAdapter : public Drawable
{
private:
    std::shared_ptr<IMachineSystem> mMachineSystem;
    int mStartTime = 0;
public:
    MachineAdapter(const std::wstring name);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool HitTest(wxPoint pos) override;
    void SetPosition(wxPoint pos);
    void Load(int machineID);
    void Save(int machineID);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEADAPTER_H
