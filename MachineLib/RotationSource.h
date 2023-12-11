/**
 * @file RotationSource.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H

class IRotationSource;
class IRotationSink;
class Component;
/**
 * Makes an object a rotation source
 */
class RotationSource
{
private:
    Component* mComponent = nullptr;
    std::vector<std::shared_ptr<IRotationSink>> mSink;

public:
    /// Copy constructor (disabled)
    RotationSource(const RotationSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSource &) = delete;

    RotationSource(Component* component);

    void Rotate(double rotation, double speed);

    void AddSink(std::shared_ptr<IRotationSink> sink);

};

#endif //CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H
