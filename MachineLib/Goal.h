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
/**
 * Class for basketball hoop in machine
 */
class Goal : public Component, public b2ContactListener
{
private:
    ///position of hoal
    wxPoint mPosition;
    ///polygon
    cse335::Polygon mPolygon;
    ///physics polygon for post
    cse335::PhysicsPolygon mPost;
    ///physics polygon for goal
    cse335::PhysicsPolygon mGoal;
    ///score for goal
    int mScore;

public:
    Goal(const std::wstring imagesDir);
    /// Copy constructor (disabled)
    Goal(const Goal &) = delete;
    /// Assignment operator
    void operator=(const Goal &) = delete;
    void BeginContact(b2Contact* contact) override;
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Update(double elapsed) override;
    void Reset() override;
    void SetPosition(double x, double y);
    void InstallPhysics(std::shared_ptr<b2World> world) override;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_GOAL_H
