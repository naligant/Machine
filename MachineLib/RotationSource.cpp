/**
 * @file RotationSource.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "RotationSource.h"
#include "IRotationSink.h"

RotationSource::RotationSource(Component* component)
{
    mComponent = component;
}
void RotationSource::AddSink(std::shared_ptr<IRotationSink> sink)
{
    mSink.push_back(sink);

}

void RotationSource::Rotate(double rotation, double speed)
{
    for (auto sink : mSink)
        if(sink != nullptr)
        {
            sink->Rotate(rotation, speed);
        }
}