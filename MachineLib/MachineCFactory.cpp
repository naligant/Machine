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
 * @param machine IMachineSystem number to create
 * @return Pointer to newly created machine
 */
std::shared_ptr<Machine> MachineCFactory::Create()
{
    auto machine = std::make_shared<Machine>(1);

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
    basketball1->SetInitialPosition(BeamX-186, 353);
    basketball1->SetDynamic();
    basketball1->SetPhysics(1, 0.5, 0.6);
    machine->AddComponent(basketball1);

    auto goal = std::make_shared<Goal>(mImagesDir);
    goal->SetPosition(270, 0);
    machine->AddComponent(goal);

    //
    // The hamster for the second-beam
    //
    auto hamster = std::make_shared<Hamster>(mImagesDir);
    hamster->SetPosition(-220, 185);
    hamster->SetInitiallyRunning(true);      // Initially running
    hamster->SetSpeed(0.60);
    machine->AddComponent(hamster);

    auto arm = std::make_shared<Body>();
    arm->SetInitialPosition(-195, 220);
    arm->AddPoint(-7, 10);
    arm->AddPoint(7, 10);
    arm->AddPoint(7, -60);
    arm->AddPoint(-7, -60);
    arm->SetImage(mImagesDir + L"/arm.png");
    arm->SetKinematic();
    hamster->GetSource()->AddSink(arm);
    machine->AddComponent(arm);

    return machine;
}