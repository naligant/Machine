/**
 * @file RotationSource.cpp
 * @author Prajeeth Naliganti
 */

#include "RotationSource.h"
#include "IRotationSink.h"
#include "IRotationSource.h"

RotationSource::RotationSource(IRotationSource* component)
{
    mComponent = component;
}
void RotationSource::AddSink(std::shared_ptr<IRotationSink> sink)
{
    mSink.push_back(sink);
    sink->SetSource(mComponent);

}

void RotationSource::Rotate(double rotation, double speed)
{
    for (auto sink : mSink)
        if(sink != nullptr)
        {
            sink->Rotate(rotation, speed);
        }
}