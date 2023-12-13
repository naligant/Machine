/**
 * @file Pulley.cpp
 * @author Prajeeth Naliganti
 */
#include "pch.h"
#include "Pulley.h"
/**
 * constructor
 * @param radius
 */
Pulley::Pulley(double radius) : mSource(this)
{

    mRadius = radius;
    mWheel.CenteredSquare(mRadius * 2);
}
/**
 * Function that draws pulley
 * @param graphics
 */
void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if (mPulley)
    {
        if (mRadius == mPulley->mRadius)
        {
            wxPoint vector = wxPoint(mPulley->mX - this->mX, mPulley->mY - this->mY);
            double distance = sqrt((vector.x * vector.x) + (vector.y * vector.y));
            auto alphaX = (vector.x / distance) * mRadius;
            auto alphaY = (vector.y / distance) * mRadius;
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
        else
        {
            wxPoint vector = wxPoint(mPulley->mX - this->mX, mPulley->mY - this->mY);
            double distance = sqrt((vector.x * vector.x) + (vector.y * vector.y));
            auto theta = atan(vector.y / vector.x);
            auto phi = asin((mPulley->mRadius - this->mRadius) / distance);
            auto beta = theta + phi + (M_PI/2);
            graphics->PushState();
            wxPen Pen(*wxBLACK, 2, wxPENSTYLE_SOLID);
            graphics->SetPen(Pen);

            //Draw first belt
            wxPoint belt1Start = wxPoint(this->mX + (this->mRadius * cos(beta)), this->mY + (this->mRadius * sin(beta)));
            wxPoint belt1End = wxPoint(mPulley->mX + (mPulley->mRadius * cos(beta)), mPulley->mY + (mPulley->mRadius * sin(beta)));
            graphics->StrokeLine(belt1Start.x, belt1Start.y, belt1End.x, belt1End.y);

            //Draw Second Belt
            wxPoint belt2Start = wxPoint(this->mX - (this->mRadius * cos(beta)), this->mY - (this->mRadius * sin(beta)));
            wxPoint belt2End = wxPoint(mPulley->mX - (mPulley->mRadius * cos(beta)), mPulley->mY - (mPulley->mRadius * sin(beta)));
            graphics->StrokeLine(belt2Start.x, belt2Start.y, belt2End.x, belt2End.y);

            graphics->PopState();
            //mPulley->mWheel.DrawPolygon(graphics, mPulley->mX, mPulley->mY, mRotation);
        }
    }
    mWheel.DrawPolygon(graphics, mX, mY, mRotation);
}
/**
 * Updates machine
 * @param elapsed
 */
void Pulley::Update(double elapsed)
{
    if (mPulley)
    {
        mPulley->mRotation += -mSpeed * elapsed;
        mPulley->mSource.Rotate(mRotation, mSpeed);
    }
}
/**
 * resets machine
 */
void Pulley::Reset()
{

}
/**
 * Override for SetImage function in PhysicsPolygon
 * @param filename
 */
void Pulley::SetImage(const std::wstring &filename)
{
   mWheel.SetImage(filename);
}
/**
 * sets position of pulley
 * @param x
 * @param y
 */
void Pulley::SetPosition(double x, double y)
{
   mX = x;
   mY = y;
}
/**
 * rotation information for pulley
 * @param rotation
 * @param speed
 */
void Pulley::Rotate(double rotation, double speed)
{
    mRotation = rotation;
    if (mPulley != nullptr && mPulley->mRadius != this->mRadius)
    {
        mSpeed = this->mRadius / mPulley->mRadius;
    }
    else{
        mSpeed = speed;
    }
}
/**
 * get second pulley to connect to
 * @param pulley
 */
void Pulley::Drive(std::shared_ptr<Pulley> pulley)
{
    mPulley = pulley;
}