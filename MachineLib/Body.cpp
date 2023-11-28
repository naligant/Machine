/**
 * @file Body.cpp
 * @author Prajeeth Naliganti
 */

#include "Body.h"
Body::Body()
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
void Body::SetInitialPosition(int x, int y)
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

void Body::SetPhysics(int density, int friction, int restitution)
{
    mPolygon.SetPhysics(density, friction, restitution);
}