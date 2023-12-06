/**
 * @file RotationSink.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H
#include "Component.h"
#include "IRotationSink.h"
class RotationSource;
class RotationSink
{
private:
    IRotationSink* mComponent = nullptr;


public:
    RotationSink(IRotationSink* component);
    void Rotate(double rotation, double speed);
};

#endif //CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H
