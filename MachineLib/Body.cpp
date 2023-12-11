/**
 * @file Body.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "Body.h"
Body::Body()
{
}
/**
 * Override for rectangle function in PhysicsPolygon
 * @param x
 * @param y
 * @param width
 * @param height
 */
void Body::Rectangle(int x, int y, int width, int height)
{
    mPolygon.Rectangle(x, y, width, height);
}

/**
 * Override for AddPoint function in PhysicsPolygon
 * @param x
 * @param y
 */
void Body::AddPoint(double x, double y)
{
    mPolygon.AddPoint(x, y);
}
/**
 * Override for Update in Component
 * @param elapsed
 */
void Body::Update(double elapsed)
{

}
/**
 * Override for Draw from Component
 * @param graphics
 */
void Body::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.Draw(graphics);
}
/**
 * Override for Reset()
 */
void Body::Reset()
{

}
/**
 * Override for SetDynamic function in PhysicsPolygon
 */
void Body::SetDynamic()
{

    mPolygon.SetDynamic();
}
/**
 * Override for SetKinematic function in PhysicsPolygon
 */
void Body::SetKinematic()
{
    mPolygon.SetKinematic();
}
/**
 * Override for SetInitialPosition function in PhysicsPolygon
 * @param x
 * @param y
 */
void Body::SetInitialPosition(double x, double y)
{
    mPolygon.SetInitialPosition(x, y);
}
/**
 * Override for SetImage function in PhysicsPolygon
 * @param filename
 */
void Body::SetImage(const std::wstring &filename )
{
    mPolygon.SetImage(filename);
}
/**
 * Override for Circle function in PhysicsPolygon
 * @param radius
 */
void Body::Circle(int radius)
{
    mPolygon.Circle(radius);
}
/**
 * Override for SetPhysics function in PhysicsPolygon
 * @param density
 * @param friction
 * @param restitution
 */
void Body::SetPhysics(double density, double friction, double restitution)
{
    mPolygon.SetPhysics(density, friction, restitution);
}
/**
 * Override for InstallPhysics function in PhysicsPolygon
 * @param world
 */
void Body::InstallPhysics(std::shared_ptr<b2World> world)
{
    mPolygon.InstallPhysics(world);
}
/**
 * Override for Rotate function in Component
 * @param rotation
 * @param speed
 */
void Body::Rotate(double rotation, double speed)
{
    mPolygon.SetAngularVelocity(-speed);
}
/**
 * Override for BottomCenteredRectangle function in PhysicsPolygon
 * @param x
 * @param y
 */
void Body::BottomCenteredRectangle(int x, int y)
{
    mPolygon.BottomCenteredRectangle(x, y);
}
/**
 * Override for SetInitialRotation function in PhysicsPolygon
 * @param rotation
 */
void Body::SetInitialRotation(double rotation)
{
   mPolygon.SetInitialRotation(rotation);
}