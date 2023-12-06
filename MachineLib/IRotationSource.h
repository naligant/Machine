/**
 * @file IRotationSource.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_IROTATIONSOURCE_H
#define CANADIANEXPERIENCE_MACHINELIB_IROTATIONSOURCE_H
class IRotationSource
{
public:

    /// Destructor
    virtual ~IRotationSource() = default;
    virtual void Rotate(double rotation, double speed) = 0;
};
#endif //CANADIANEXPERIENCE_MACHINELIB_IROTATIONSOURCE_H
