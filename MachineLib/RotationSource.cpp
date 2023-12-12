/**
 * @file RotationSource.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "RotationSource.h"
#include "IRotationSink.h"
/**
 * constructor
 * @param component
 */
RotationSource::RotationSource(Component* component)
{
}
/**
 * adds sink to source
 * @param sink
 */
void RotationSource::AddSink(std::shared_ptr<IRotationSink> sink)
{
    mSink.push_back(sink);

}
/**
 * adds rotation to all components
 * @param rotation
 * @param speed
 */
void RotationSource::Rotate(double rotation, double speed)
{
    for (auto sink : mSink)
        if(sink != nullptr)
        {
            sink->Rotate(rotation, speed);
        }
}