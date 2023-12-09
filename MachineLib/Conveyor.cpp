/**
 * @file Conveyor.cpp
 * @author Prajeeth Naliganti
 */

#include "Conveyor.h"
#include <b2_contact.h>

/// The offset from the bottom center of the conveyor
/// to the center of the drive shaft.  48
const auto ConveyorShaftOffset = wxPoint2DDouble(48, 4);

/// The size of the conveyor in cm
const auto ConveyorSize = wxSize(125, 14);

/// The conveyor image to use
const std::wstring ConveyorImageName = L"/conveyor.png";

Conveyor::Conveyor(const std::wstring imagesDir)
{
    mConveyor.BottomCenteredRectangle(ConveyorSize);
    mConveyor.SetImage(imagesDir + ConveyorImageName);
}

void Conveyor::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{

    contact->SetTangentSpeed(mSpeed);
}
void Conveyor::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mConveyor.Draw(graphics);
}
void Conveyor::Reset()
{

}

void Conveyor::Update(double elapsed)
{
}
void Conveyor::SetPosition(wxPoint2DDouble point)
{
    mConveyor.SetInitialPosition(point.m_x, point.m_y);
    mPosition.m_x = point.m_x;
    mPosition.m_y = point.m_y;
}

wxPoint Conveyor::GetShaftPosition()
{
    auto point = wxPoint(mPosition.m_x + ConveyorShaftOffset.m_x, mPosition.m_y + ConveyorShaftOffset.m_y);
    return point;
}

void Conveyor::Rotate(double rotation, double speed)
{
    mSpeed = speed;
    auto contact = mConveyor.GetBody()->GetContactList();
    while(contact != nullptr)
    {
        if(contact->contact->IsTouching())
        {
            contact->other->SetLinearVelocity(b2Vec2(speed, 0));
        }

        contact = contact->next;
    }
}

void Conveyor::InstallPhysics(std::shared_ptr<b2World> world)
{
    mConveyor.InstallPhysics(world);
}