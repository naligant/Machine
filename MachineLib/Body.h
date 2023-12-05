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

class Body : public Component
{
private:
    cse335::PhysicsPolygon mPolygon;
    double mSpeed;
public:
    Body();
    /// Copy constructor (disabled)
    Body(const Body &) = delete;

    /// Assignment operator
    void operator=(const Body &) = delete;

    void Rectangle(int x, int y, int width, int height);
    void AddPoint(int x, int y);
    void Update(double elapsed) override;
    void Draw(std::shared_ptr<wxGraphicsContext>graphics, int x, int y) override;
    void Reset() override;
    void SetDynamic();
    void SetKinematic();
    void SetImage(const std::wstring &filename) override;
    void SetInitialPosition(double x, double y);
    void Circle(int radius);
    void SetPhysics(double density, double friction, double restitution);
    void InstallPhysics(std::shared_ptr<b2World> world) override;
//    cse335::PhysicsPolygon* GetPhysicsPolygon() {return &mPhysicsPolygon;}
//    std::vector<cse335::PhysicsPolygon*> GetPolygon() override;


};

#endif //CANADIANEXPERIENCE_MACHINELIB_BODY_H
