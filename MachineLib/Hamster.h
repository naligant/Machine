/**
 * @file Hamster.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_HAMSTER_H
#define CANADIANEXPERIENCE_MACHINELIB_HAMSTER_H
#include "Component.h"
#include "PhysicsPolygon.h"
#include "Polygon.h"
#include "RotationSource.h"
#include <b2_world_callbacks.h>
/**
 * hamster is a rotation source for many other components
 */
class Hamster : public Component, public b2ContactListener
{
private:
    ///boolean to mark if hamster is running
    bool mIsRunning = false;
    ///speed of hamster
    double mSpeed = 0.0;
    ///rotation of connecter components
    double mRotation = 0.0;
    ///cage of hamster
    cse335::PhysicsPolygon mCage;
    ///wheel in cage of hamster
    cse335::Polygon mWheel;
    ///states of hamster
    std::array<cse335::Polygon, 4> mHamsters;
    ///current Hamster image
    cse335::Polygon* mCurrentHamster;
    ///boolean for if the hamster is initially supposed to run
    bool mIsInitialRunning = false;
    /// The position of the hamster cage
    wxPoint2DDouble mPosition;
    /// Rotation source for this component
    RotationSource mSource;

public:
    /**
     * constructor
     * @param imagesDir
     */
    Hamster(const std::wstring imagesDir);
    /// Copy constructor (disabled)
    Hamster(const Hamster &) = delete;
    /// Assignment operator
    void operator=(const Hamster &) = delete;
    void BeginContact(b2Contact* contact) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Update(double elapsed) override;
    void Reset() override;
    void SetInitiallyRunning(bool running);
    void SetPosition(double x, double y);
    /**
     * sets hamsters speed
     * @param speed
     */
    void SetSpeed(double speed) override {mSpeed = speed;};
    void InstallPhysics(std::shared_ptr<b2World> world) override;
    void Rotate(double rotation, double speed);
    wxPoint GetShaftPosition();
    /**
    * Get a pointer to the source object
    * @return Pointer to RotationSource object
    */
    RotationSource *GetSource() { return &mSource; }



};

#endif //CANADIANEXPERIENCE_MACHINELIB_HAMSTER_H
