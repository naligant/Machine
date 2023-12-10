/**
 * @file Body.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_BODY_H
#define CANADIANEXPERIENCE_MACHINELIB_BODY_H
#include "Component.h"
#include "PhysicsPolygon.h"
#include "Polygon.h"
#include "RotationSource.h"
#include "IRotationSink.h"
class Body : public Component, public IRotationSink
{
private:
    cse335::PhysicsPolygon mPolygon;


public:
    Body();
    /// Copy constructor (disabled)
    Body(const Body &) = delete;

    /// Assignment operator
    void operator=(const Body &) = delete;

    void Rectangle(int x, int y, int width, int height);
    void AddPoint(double x, double y);
    void Update(double elapsed) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Reset() override;
    void SetDynamic();
    void SetKinematic();
    void SetImage(const std::wstring &filename);
    void SetInitialPosition(double x, double y);
    void Circle(int radius);
    void SetPhysics(double density, double friction, double restitution);
    void InstallPhysics(std::shared_ptr<b2World> world) override;
    void Rotate(double rotation, double speed) override;
    void BottomCenteredRectangle(int x, int y);
    void SetInitialRotation(double rotation);

//    RotationSink *GetSink() {return &mSink;}


};

#endif //CANADIANEXPERIENCE_MACHINELIB_BODY_H
