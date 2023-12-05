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
#include <b2_world_callbacks.h>
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
    ///boolean for if the hamster is initially supposed to run
    bool mIsInitialRunning = false;
    /// The position of the hamster cage
    wxPoint2DDouble mPosition;

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
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;
    void Update(double elapsed) override;
    void Reset() override;
    void SetInitiallyRunning(bool running);
    void SetPosition(double x, double y);
    void SetSpeed(double speed) override {mSpeed = speed;};
    void InstallPhysics(std::shared_ptr<b2World> world) override;


};

#endif //CANADIANEXPERIENCE_MACHINELIB_HAMSTER_H
