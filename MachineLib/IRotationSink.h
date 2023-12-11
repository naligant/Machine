/**
 * @file IRotationSink.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_IROTATIONSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_IROTATIONSINK_H
class Component;
/**
 * Interface for rotation sinks
 */
class IRotationSink {
public:

    /// Destructor
    virtual ~IRotationSink() = default;
    /**
     * Rotation function for sinks
     * @param rotation
     * @param speed
     */
    virtual void Rotate(double rotation, double speed) = 0;
};


#endif //CANADIANEXPERIENCE_MACHINELIB_IROTATIONSINK_H
