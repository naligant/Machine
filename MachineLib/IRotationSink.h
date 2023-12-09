/**
 * @file IRotationSink.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_IROTATIONSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_IROTATIONSINK_H
//class IRotationSource;
class Component;
class IRotationSink {
public:

    /// Destructor
    virtual ~IRotationSink() = default;
    virtual void Rotate(double rotation, double speed) = 0;
};


#endif //CANADIANEXPERIENCE_MACHINELIB_IROTATIONSINK_H
