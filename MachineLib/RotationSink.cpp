/**
 * @file RotationSink.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "RotationSink.h"
#include "RotationSource.h"

RotationSink::RotationSink(IRotationSink* component)
{
    mComponent = component;
}
void RotationSink::Rotate(double rotation, double speed)
{
   mComponent->Rotate(rotation, speed);
}
