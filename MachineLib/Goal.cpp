/**
 * @file Goal.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "Goal.h"
#include <iomanip>
#include <sstream>
#include <b2_contact.h>

/// Image to draw for the goal
const std::wstring GoalImage = L"/goal.png";

/// Size to draw the entire goal post image
/// This does not go into the physics system at all
const auto GoalSize = wxSize(65, 247);

/// Size to create a rectangle in the physics system only
/// (does not draw) to reflect off of the backboard and post
const auto PostSize = wxSize(10, 250);

/// Size of a target object inside the goal net that
/// we'll consider a score when touched by a ball
const auto TargetSize = wxSize(20, 5);

/// The color of the scoreboard background
const auto ScoreboardBackgroundColor = wxColor(24, 69, 59);

/// Width of the black line around the scoreboard
const int ScoreboarderLineWidth = 3;

/// Scoreboard font size (height) in cm
/// The font color is white
const int ScoreboardFontSize = 20;

/// Rectangle that represents the location relative to the
/// goal position for the scoreboard and its size.
const auto ScoreboardRectangle = wxRect2DDouble(5, 280, 30, 20);

/// Location of the scoreboard text relative to the
/// scoreboard location in cm.
const auto ScoreboardTextLocation = wxPoint2DDouble(9, 299);

/// Position of the goalpost polygon relative to the entire goal
/// This plus the location set by SetPosition is where to draw
/// the goalpost PhysicsPolygon object.
const wxPoint2DDouble PostPosition = wxPoint2DDouble(22, 0);

/// Position of the basket goal polygon relative to the entire goal
/// This plus the location set by SetPosition is where to draw
/// the goalpost PhysicsPolygon object.
const wxPoint2DDouble GoalPosition = wxPoint2DDouble(-12, 165);

/**
 * constructor
 * @param imagesDir
 */
Goal::Goal(const std::wstring imagesDir)
{

    mPolygon.BottomCenteredRectangle(GoalSize);
    mPolygon.SetImage(imagesDir + GoalImage);

    mPost.BottomCenteredRectangle(PostSize);
    mPost.SetColor(*wxBLUE);

    mGoal.BottomCenteredRectangle(TargetSize);
    mGoal.SetColor(*wxBLUE);
}
/**
 * override function BeginContact from b2ContactListener
 * @param contact
 */
void Goal::BeginContact(b2Contact *contact)
{
    mScore += 2;
}

/**
 * Handle before the solution of a contact with the
 * scoreboard target object. We take this time to
 * turn off the contact, so the ball will pass through.
 * @param contact Contqct object
 * @param oldManifold Manifold object
 */
void Goal::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
    contact->SetEnabled(false);
}
/**
 * Draws Graphics for goal
 * @param graphics
 */
void Goal::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    // Set the background color
    graphics->SetBrush(wxBrush(ScoreboardBackgroundColor));
    graphics->SetPen(wxPen(wxColour(0, 0, 0), ScoreboarderLineWidth));

    graphics->DrawRectangle(ScoreboardRectangle.m_x + mPosition.x,ScoreboardRectangle.m_y + mPosition.y, ScoreboardRectangle.m_width, ScoreboardRectangle.m_height);

    // Set the font for the scoreboard text
    wxFont font(ScoreboardFontSize,
                wxFONTFAMILY_DEFAULT,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, wxColour(255, 255, 255));

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << mScore;

    // Get the formatted string
    std::string formattedNumber = ss.str();
    graphics->Translate(ScoreboardTextLocation.m_x + mPosition.x,  ScoreboardTextLocation.m_y + mPosition.y);
    graphics->Scale(1, -1);
    graphics->DrawText(formattedNumber, 0,  0);
    graphics->PopState();

    mPolygon.DrawPolygon(graphics, mPosition.x, mPosition.y,0);
//    mPost.Draw(graphics);
//    mGoal.Draw(graphics);
}

/**
 * sets position for goal
 * @param x
 * @param y
 */
void Goal::SetPosition(double x, double y)
{
    mPost.SetInitialPosition(x + PostPosition.m_x , y + PostPosition.m_y );
    mGoal.SetInitialPosition(x + GoalPosition.m_x , y + GoalPosition.m_y );
    mPosition.x = x;
    mPosition.y = y;
}
/**
 * updates machine
 * @param elapsed
 */
void Goal::Update(double elapsed)
{

}
/**
 * resets machine
 */
void Goal::Reset()
{

}
/**
 * install physics for objects
 * @param world
 */
void Goal::InstallPhysics(std::shared_ptr<b2World> world)
{
    auto contactListener = GetContactListener();
    mPost.InstallPhysics(world);
    mGoal.InstallPhysics(world);
    contactListener->Add(mGoal.GetBody(), this);
}