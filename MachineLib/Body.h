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
    void Rectangle(int x, int y, int width, int height);
    void AddPoint(int x, int y);
    void Update(double elapsed) override;
    void Draw(std::shared_ptr<wxGraphicsContext>graphics, int x, int y) override;
    void Reset() override;
    void SetDynamic();
    void SetKinematic();
    void SetImage(const std::wstring &filename) override;
    void SetInitialPosition(int x, int y);
    void Circle(int radius);
    void SetPhysics(int density, int friction, int restitution);
//    cse335::PhysicsPolygon* GetPhysicsPolygon() {return &mPhysicsPolygon;}
//    cse335::Polygon* GetPolygon() {return &mPolygon;}


};

#endif //CANADIANEXPERIENCE_MACHINELIB_BODY_H
