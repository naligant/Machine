/**
 * @file MachineCFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "MachineCFactory.h"
#include "Machine.h"
#include "Body.h"
#include "Hamster.h"
#include "Goal.h"
#include "Pulley.h"
#include "Conveyor.h"
#include "HamsterAndConveyorFactory.h"

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";

/**
 * Constructor
 * @param resourcesDir Directory containing the machine resources
 */
MachineCFactory::MachineCFactory(std::wstring resourcesDir)
    :mResourcesDir(resourcesDir)
{
    mImagesDir = resourcesDir + ImagesDirectory;
}

/**
 * Create a machine
 * @return Pointer to newly created machine
 */
std::shared_ptr<Machine> MachineCFactory::Create()
{
    auto machine = std::make_shared<Machine>(2);

    // Notice: All dimensions are in centimeters and assume
    // the Y axis is positive in the up direction.

    const double FloorWidth = 600;
    const double FloorHeight = 15;

    //
    // The floor
    //
    // The values are chosen so the top of the floor
    // is at Y=0
    //
    auto floor = std::make_shared<Body>();
    floor->Rectangle(-FloorWidth/2, -FloorHeight, FloorWidth, FloorHeight);
    floor->SetImage(mImagesDir + L"/floor.png");
    machine->AddComponent(floor);

    const double BeamX = -25;

    // Basketball 1
    auto basketball1 = std::make_shared<Body>();
    basketball1->Circle(12);
    basketball1->SetImage(mImagesDir + L"/basketball1.png");
    basketball1->SetInitialPosition(BeamX-186, 312);
    basketball1->SetDynamic();
    basketball1->SetPhysics(1, 0.5, 0.6);
    machine->AddComponent(basketball1);

    auto goal = std::make_shared<Goal>(mImagesDir);
    goal->SetPosition(270, 0);
    machine->AddComponent(goal);

    //Top beam
    const double Beam2X = -80;
    auto beam = std::make_shared<Body>();
    beam->BottomCenteredRectangle(300, 20);
    beam->SetImage(mImagesDir + L"/beam.png");
    beam->SetInitialPosition(Beam2X, 280);
    machine->AddComponent(beam);

    //Side beam
    const double Beam3X = 140;
    auto beam2 = std::make_shared<Body>();
    beam2->BottomCenteredRectangle(20, 320);
    beam2->SetImage(mImagesDir + L"/beam.png");
    beam2->SetInitialPosition(Beam3X, 0);
    machine->AddComponent(beam2);

    //beam under
    const double Beam4X = -20;
    auto beam3 = std::make_shared<Body>();
    beam3->BottomCenteredRectangle(300, 20);
    beam3->SetImage(mImagesDir + L"/beam.png");
    beam3->SetInitialPosition(Beam4X, 160);
    machine->AddComponent(beam3);

    //Domino stack
    wxPoint position = wxPoint(Beam4X, 165);
    for(int d=0; d<10; d++)
    {
        // Where to put this domino
        auto dominos = position + wxPoint2DDouble(-70 + d * 15, 27);

        Domino(machine, dominos, 0, DominoColor::Green);
    }

    //Second ball
    auto ball1 = std::make_shared<Body>();
    ball1->Circle(12);
    ball1->SetImage(mImagesDir + L"/ball1.png");
    ball1->SetInitialPosition(Beam4X-90, 192);
    ball1->SetDynamic();
    ball1->SetPhysics(1, 0.5, 0.6);
    machine->AddComponent(ball1);

    //
    // The hamster to start reaction
    //
    auto hamster = std::make_shared<Hamster>(mImagesDir);
    hamster->SetPosition(-240, 220);
    hamster->SetInitiallyRunning(true);      // Initially running
    hamster->SetSpeed(0.60);
    machine->AddComponent(hamster);

    auto arm = std::make_shared<Body>();
    arm->SetInitialPosition(hamster->GetShaftPosition().x,hamster->GetShaftPosition().y );
    arm->AddPoint(-7, 10);
    arm->AddPoint(7, 10);
    arm->AddPoint(7, -60);
    arm->AddPoint(-7, -60);
    arm->SetImage(mImagesDir + L"/arm.png");
    arm->SetKinematic();
    hamster->GetSource()->AddSink(arm);
    machine->AddComponent(arm);

    //
    // First conveyor with a ball sitting on it
    //

    HamsterAndConveyorFactory hamsterAndConveyorFactory(machine, mImagesDir);

    hamsterAndConveyorFactory.Create(wxPoint2DDouble(-280, 20), wxPoint2DDouble(-220, 80));
    auto hamster1 = hamsterAndConveyorFactory.GetHamster();
    auto conveyor1 = hamsterAndConveyorFactory.GetConveyor();
    hamster1->SetInitiallyRunning(true);

    //Domino Stack 2
    wxPoint beamposition = wxPoint(-50, 0);
    DominoStack(machine, beamposition);

    //Hamster and conveyor 2
    auto hamsterPosition = wxPoint2DDouble(35, 0);
    auto conveyorPosition = wxPoint2DDouble(160, 330);
    auto hamster2 = std::make_shared<Hamster>(mImagesDir);
    hamster2->SetPosition(hamsterPosition.m_x, hamsterPosition.m_y);
    machine->AddComponent(hamster2);
    auto hamsterShaft2 = hamster2->GetShaftPosition();

    auto conveyor2 = std::make_shared<Conveyor>(mImagesDir);
    conveyor2->SetPosition(conveyorPosition);
    machine->AddComponent(conveyor2);
    auto conveyorShaft = conveyor2->GetShaftPosition();

    // The pulley driven by the hamster
    auto pulley1 = std::make_shared<Pulley>(10);
    pulley1->SetImage(mImagesDir + L"/pulley3.png");
    pulley1->SetPosition(hamsterShaft2.x, hamsterShaft2.y);
    machine->AddComponent(pulley1);

    hamster2->GetSource()->AddSink(pulley1);

    auto pulley2 = std::make_shared<Pulley>(30);
    pulley2->SetImage(mImagesDir + L"/pulley3.png");
    pulley2->SetPosition(conveyorShaft.x, conveyorShaft.y);
    machine->AddComponent(pulley2);

    pulley1->Drive(pulley2);

    pulley2->GetSource()->AddSink(conveyor2);

//    hamsterAndConveyorFactory.Create(wxPoint2DDouble(35, 0), wxPoint2DDouble(160, 330));
//    auto hamster2 = hamsterAndConveyorFactory.GetHamster();
//    auto conveyor2 = hamsterAndConveyorFactory.GetConveyor();
//    hamster1->SetSpeed(0.5);

    //Third ball for goal
    auto ball2= std::make_shared<Body>();
    ball2->Circle(12);
    ball2->SetImage(mImagesDir + L"/basketball2.png");
    ball2->SetInitialPosition(130, 356);
    ball2->SetDynamic();
    ball2->SetPhysics(1, 0.5, 0.6);
    machine->AddComponent(ball2);

    return machine;
}

/**
 * Create a Domino and add it to the machine.
 *
 * This has been created to make it easier to create
 * a lot of dominos
 *
 * @param machine Machine to add the domino to
 * @param position Position to place the center of the domino
 * @param rotation Rotation in turns
 * @param color Color code
 * @return Returns the created domino body
 */
std::shared_ptr<Body>  MachineCFactory::Domino(std::shared_ptr<Machine> machine, wxPoint2DDouble position, double rotation, DominoColor color)
{
    auto x = position.m_x;
    auto y = position.m_y;

    auto domino = std::make_shared<Body>();
    domino->Rectangle(-DominoWidth/2, -DominoHeight/2, DominoWidth, DominoHeight);
    switch(color)
    {
        case DominoColor::Black:
            domino->SetImage(mImagesDir + L"/domino-black.png");
            break;

        case DominoColor::Red:
            domino->SetImage(mImagesDir + L"/domino-red.png");
            break;

        case DominoColor::Green:
            domino->SetImage(mImagesDir + L"/domino-green.png");
            break;

        case DominoColor::Blue:
            domino->SetImage(mImagesDir + L"/domino-blue.png");
            break;
    }

    domino->SetInitialPosition(x, y);
    domino->SetInitialRotation(rotation);
    domino->SetDynamic();
    machine->AddComponent(domino);

    return domino;
}
/**
 * Function to make a domino stack
 * @param machine
 * @param position
 */
void MachineCFactory::DominoStack(std::shared_ptr<Machine> machine, wxPoint2DDouble position)
{
    Domino(machine, position + wxPoint2DDouble(30, DominoHeight/2), 0, DominoColor::Red);
    Domino(machine, position + wxPoint2DDouble(10, DominoHeight/2), 0, DominoColor::Blue);
    Domino(machine, position + wxPoint2DDouble(20, DominoHeight + DominoWidth/2), 0.25, DominoColor::Green);

    Domino(machine, position + wxPoint2DDouble(-10, DominoHeight/2), 0, DominoColor::Red);
    Domino(machine, position + wxPoint2DDouble(-30, DominoHeight/2), 0, DominoColor::Green);
    Domino(machine, position + wxPoint2DDouble(-20, DominoHeight + DominoWidth/2), 0.25, DominoColor::Black);

    const int DominoLevel2 = DominoHeight + DominoWidth;

    Domino(machine, position + wxPoint2DDouble(10, DominoLevel2 + DominoHeight/2), 0, DominoColor::Red);
    Domino(machine, position + wxPoint2DDouble(-10, DominoLevel2 + DominoHeight/2), 0, DominoColor::Green);
    Domino(machine, position + wxPoint2DDouble(0, DominoLevel2 + DominoHeight + DominoWidth/2), 0.25, DominoColor::Black);
}