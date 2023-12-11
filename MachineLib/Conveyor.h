/**
 * @file Conveyor.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_CONVEYOR_H
#define CANADIANEXPERIENCE_MACHINELIB_CONVEYOR_H
#include "PhysicsPolygon.h"
#include "Component.h"
#include "IRotationSink.h"
#include <b2_world_callbacks.h>
/**
 * Conveyor component connected to rotation sources
 */
class Conveyor : public Component,  public b2ContactListener, public IRotationSink
{
private:
    /// physics polygon object
    cse335::PhysicsPolygon mConveyor;
    ///speed of conveyor
    double mSpeed = 0.0;
    ///position of conveyor
    wxPoint2DDouble mPosition;
public:
    /**
     * constructor
     * @param imagesDir
     */
    Conveyor(const std::wstring imagesDir);
    /// Copy constructor (disabled)
    Conveyor(const Conveyor &) = delete;

    /// Assignment operator
    void operator=(const Conveyor &) = delete;
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
    void Update(double elapsed) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Reset() override;
    void SetPosition(wxPoint2DDouble point);
    /**
     * Gets position of object
     * @return
     */
    wxPoint2DDouble GetPosition() {return mPosition;}
    wxPoint GetShaftPosition();
    void Rotate(double rotation, double speed) override;
    void InstallPhysics(std::shared_ptr<b2World> world) override;


};

#endif //CANADIANEXPERIENCE_MACHINELIB_CONVEYOR_H
