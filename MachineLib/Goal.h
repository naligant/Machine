/**
 * @file Goal.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_GOAL_H
#define CANADIANEXPERIENCE_MACHINELIB_GOAL_H
#include "Polygon.h"
#include "PhysicsPolygon.h"
#include "Component.h"
#include <b2_world_callbacks.h>
class Goal : public Component, public b2ContactListener
{
private:
    double mX = 0.0;
    double mY = 0.0;
    cse335::Polygon mPolygon;
    cse335::PhysicsPolygon mPost;
    cse335::PhysicsPolygon mGoal;
    int mScore;

public:
    Goal(const std::wstring imagesDir);
    /// Copy constructor (disabled)
    Goal(const Goal &) = delete;

    /// Assignment operator
    void operator=(const Goal &) = delete;

    void BeginContact(b2Contact* contact) override;
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;
    void Update(double elapsed) override;
    void Reset() override;
    void SetPosition(double x, double y);
    void InstallPhysics(std::shared_ptr<b2World> world) override;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_GOAL_H
