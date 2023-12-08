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
#include "RotationSink.h"
#include <b2_world_callbacks.h>
class Conveyor : public Component,  public b2ContactListener, public IRotationSink
{
private:
    cse335::PhysicsPolygon mConveyor;
    double mSpeed = 0.0;
    wxPoint2DDouble mPosition;
    /// Rotation sink for this component
    RotationSink mSink;

    IRotationSource* mSource = nullptr;
public:
    Conveyor(const std::wstring imagesDir);
    /// Copy constructor (disabled)
    Conveyor(const Conveyor &) = delete;

    /// Assignment operator
    void operator=(const Conveyor &) = delete;
//    void TransferMotion();
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
    void Update(double elapsed) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;
    void Reset() override;
    void SetPosition(wxPoint2DDouble point);
    wxPoint2DDouble GetPosition() {return mPosition;}
    wxPoint GetShaftPosition();
    void Rotate(double rotation, double speed) override;
    void SetSource(IRotationSource* source) override {mSource = source;}
    void InstallPhysics(std::shared_ptr<b2World> world) override;


};

#endif //CANADIANEXPERIENCE_MACHINELIB_CONVEYOR_H
