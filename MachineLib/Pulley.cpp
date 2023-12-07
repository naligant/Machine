/**
 * @file Pulley.cpp
 * @author Prajeeth Naliganti
 */
#include "pch.h"
#include "Pulley.h"

Pulley::Pulley(double radius) : mSink(this)
{
    mRadius = radius;
    mWheel.CenteredSquare(mRadius * 2);
}


void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    if (mPulley)
    {
        wxPoint vector = wxPoint(mPulley->mX - this->mX, mPulley->mY - this->mY);
        double distance = sqrt((vector.x*vector.x) + (vector.y*vector.y));
        auto alphaX = (vector.x / distance)*mRadius;
        auto alphaY = (vector.y / distance)*mRadius;
        auto betaX = -alphaY;
        auto betaY = alphaX;

        // Draw the first belt
        wxPoint belt1Start = wxPoint(this->mX + betaX, this->mY + betaY);
        wxPoint belt1End = wxPoint(mPulley->mX + betaX, mPulley->mY + betaY);
        graphics->PushState();
        wxPen Pen(*wxBLACK, 2, wxPENSTYLE_SOLID);
        graphics->SetPen(Pen);
        graphics->StrokeLine(belt1Start.x, belt1Start.y, belt1End.x, belt1End.y);

        // Draw the second belt
        wxPoint belt2Start = wxPoint(this->mX - betaX, this->mY - betaY);
        wxPoint belt2End = wxPoint(mPulley->mX - betaX, mPulley->mY - betaY);
        graphics->StrokeLine(belt2Start.x, belt2Start.y, belt2End.x, belt2End.y);

        graphics->PopState();
        mPulley->mWheel.DrawPolygon(graphics, mX, mY, mRotation);
    }
    mWheel.DrawPolygon(graphics, mX, mY, mRotation);
}

void Pulley::Update(double elapsed)
{
    if (mPulley)
    {
        mPulley->mRotation += -mSpeed * elapsed;
        mSource->Rotate(mRotation, mSpeed);
    }
}

void Pulley::Reset()
{

}

void Pulley::SetImage(const std::wstring &filename)
{
   mWheel.SetImage(filename);
}

void Pulley::SetPosition(double x, double y)
{
   mX = x;
   mY = y;
}
void Pulley::SetSource(IRotationSource* source)
{
    if (mPulley)
    {
        mPulley->mSource = this;
    }
    mSource = source;
}
void Pulley::Rotate(double rotation, double speed)
{
    mRotation = rotation;
    mSpeed = speed;
}
void Pulley::Drive(std::shared_ptr<Pulley> pulley)
{
    mPulley = pulley;
}