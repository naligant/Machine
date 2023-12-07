/**
 * @file Body.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "Body.h"
Body::Body() : mSink(this)
{
}

void Body::Rectangle(int x, int y, int width, int height)
{
    mPolygon.Rectangle(x, y, width, height);
}

void Body::AddPoint(int x, int y)
{
    mPolygon.AddPoint(x, y);
}

void Body::Update(double elapsed)
{

}
void Body::Draw(std::shared_ptr<wxGraphicsContext>graphics, int x, int y)
{
    mPolygon.Draw(graphics);
}
void Body::Reset()
{

}
void Body::SetDynamic()
{

    mPolygon.SetDynamic();
}
void Body::SetKinematic()
{
    mPolygon.SetKinematic();
}
void Body::SetInitialPosition(double x, double y)
{
    mPolygon.SetInitialPosition(x, y);
}

void Body::SetImage(const std::wstring &filename )
{
    mPolygon.SetImage(filename);
}

void Body::Circle(int radius)
{
    mPolygon.Circle(radius);
}

void Body::SetPhysics(double density, double friction, double restitution)
{
    mPolygon.SetPhysics(density, friction, restitution);
}

//std::vector<cse335::PhysicsPolygon*> Body::GetPolygon()
//{
//    std::vector<cse335::PhysicsPolygon*> vector;
//    vector.push_back(&mPolygon);
//    return vector;
//}
void Body::InstallPhysics(std::shared_ptr<b2World> world)
{
    mPolygon.InstallPhysics(world);
}

void Body::Rotate(double rotation, double speed)
{
    mPolygon.SetAngularVelocity(-speed);
}