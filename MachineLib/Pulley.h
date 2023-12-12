/**
 * @file Pulley.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
#define CANADIANEXPERIENCE_MACHINELIB_PULLEY_H

#include "Polygon.h"
#include "Component.h"
#include "IRotationSink.h"
#include "RotationSource.h"
/**
 * rotation source and sink to Hamster and other objects
 */
class Pulley : public Component, public IRotationSink
{
private:
    ///radius of pulley
    double mRadius = 0.0;
    ///speed of pulley
    double mSpeed = 0.0;
    ///rotation of pulley
    double mRotation = 0.0;
    ///x location of pulley
    int mX = 0;
    ///y location of pulley
    int mY = 0;
    ///wheel polygon
    cse335::Polygon mWheel;
    /// The vector of pulley objects
    std::shared_ptr<Pulley> mPulley = nullptr;
    /// Rotation source for this component
    RotationSource mSource;

public:
    Pulley(double radius);
    /// Copy constructor (disabled)
    Pulley(const Pulley &) = delete;
    /// Assignment operator
    void operator=(const Pulley &) = delete;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Drive(std::shared_ptr<Pulley> pulley);
    void Update(double elapsed) override;
    void Rotate(double rotation, double speed) override;
    void Reset() override;
    void SetImage(const std::wstring &filename);
    void SetPosition(double x, double y);
    /**
     * Gets the rotation source
     * @return
     */
    RotationSource* GetSource() {return &mSource;}



};

#endif //CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
