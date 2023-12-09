/**
 * @file Hamster.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "Hamster.h"
#include <b2_contact.h>

/// The center point for drawing the wheel
/// relative to the bottom center of the cage
const auto WheelCenter = wxPoint2DDouble(-12, 24);

/// The size of the hamster cage in centimeters
const auto HamsterCageSize = wxSize(75, 50);

/// Size of the hamster wheel (diameter) in centimeters
const double HamsterWheelSize = 45;

/// Size of the hamster wheel (square) in centimeters
const double HamsterSize = 45;

/// Hamster initial speed if speed isn't provided
const double HamsterInitialSpeed = 1;

/// How fast the hamster runs. This is now many cycles of
/// the 3 images we make per second as images 1, 2, 3, 2, ...
const double HamsterSpeed = 4.0;

/// The offset from the bottom center of the hamster cage
/// to the center of the output shaft.
const auto HamsterShaftOffset = wxPoint2DDouble(25, 40);

/// The image for the hamster cage
const std::wstring HamsterCageImage = L"/hamster-cage.png";

/// The image for the hamster wheel
const std::wstring HamsterWheelImage = L"/hamster-wheel.png";

/// The hamster images. Image 0 is sleeping, 1-3 are
/// the running hamster animation images.
const std::wstring HamsterImages[4] =
    {L"/hamster-sleep.png", L"/hamster-run-1.png",
        L"/hamster-run-2.png", L"/hamster-run-3.png"};

Hamster::Hamster(const std::wstring imagesDir) : mSource(this)
{
    mCage.BottomCenteredRectangle(HamsterCageSize);
    mCage.SetImage(imagesDir + HamsterCageImage);

    mWheel.CenteredSquare(HamsterWheelSize);
    mWheel.SetImage(imagesDir + HamsterWheelImage);

    mSpeed = HamsterInitialSpeed;

    int len = sizeof(HamsterImages) / sizeof(HamsterImages[0]);
    for(int i=0; i < len; i++)
    {
        mHamsters[i].CenteredSquare(HamsterSize);
        mHamsters[i].SetImage(imagesDir + HamsterImages[i]);
    }

    mCurrentHamster = &mHamsters[0];
}
void Hamster::BeginContact(b2Contact* contact)
{
    mIsRunning = true;
}
void Hamster::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mCage.Draw(graphics);
    graphics->PushState();
    graphics->Translate(mPosition.m_x + WheelCenter.m_x, mPosition.m_y + WheelCenter.m_y);

    if(mSpeed < 0)
    {
        graphics->Scale(-1, 1);
    }

    // Draw the running image
    mWheel.DrawPolygon(graphics, 0, 0, mRotation);

    mCurrentHamster->DrawPolygon(graphics, 0, 0, 0);

    graphics->PopState();


}
void Hamster::Update(double elapsed)
{
//    if (mIsRunning)
//    {
//        mIsInitialRunning = true;
//    }
    if (mIsRunning || mIsInitialRunning)
    {
        mRotation += -mSpeed * elapsed;
        mSource.Rotate(mRotation, mSpeed);
        int index = int(abs(mRotation) * HamsterSpeed * HamsterSpeed) % 4;
        int order[] = {1, 2, 3, 2};
        mCurrentHamster = &mHamsters[order[index]];
//        if (mRotation)
//        {
//            mCurrentHamster = &mHamsters[1];
//        }
//        else
//        {
//            mCurrentHamster = &mHamsters[0];
//        }
    }

}
void Hamster::Reset()
{

}
void Hamster::SetInitiallyRunning(bool running)
{
    mIsInitialRunning = true;
}
void Hamster::SetPosition(double x, double y)
{
    mPosition.m_x = x;
    mPosition.m_y = y;
    mCage.SetInitialPosition(x, y);
}

void Hamster::InstallPhysics(std::shared_ptr<b2World> world)
{
    auto contactListener = GetContactListener();
    mCage.InstallPhysics(world);
    contactListener->Add(mCage.GetBody(), this);
}

void Hamster::Rotate(double rotate, double speed)
{
    mCage.SetAngularVelocity(speed);
    mSource.Rotate(rotate, speed);
}

wxPoint Hamster::GetShaftPosition()
{
    auto point = wxPoint(mPosition.m_x + HamsterShaftOffset.m_x, mPosition.m_y + HamsterShaftOffset.m_y);
    return point;
}