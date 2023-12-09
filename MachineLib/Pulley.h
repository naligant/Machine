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

class Pulley : public Component, public IRotationSink
{
private:
    double mRadius = 0.0;
    double mSpeed = 0.0;
    double mRotation = 0.0;
    int mX = 0;
    int mY = 0;
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
    RotationSource* GetSource() {return &mSource;}



};

#endif //CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
