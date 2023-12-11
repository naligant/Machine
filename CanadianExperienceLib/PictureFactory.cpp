/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineAdapter.h"
#include <machine-api.h>


/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    auto picture = std::make_shared<Picture>();

    // Create the background and add it
    auto background = std::make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            std::make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 620));
    picture->AddActor(sparty);

    int frameRate = background->GetPicture()->GetTimeline()->GetFrameRate();
    auto machineOne =
        std::make_shared<MachineAdapter>(L"MachineOne", resourcesDir);
    machineOne->SetMachineNumber(1);
    machineOne->SetPosition(wxPoint(500, 1050));
    machineOne->SetTimeline(background->GetPicture()->GetTimeline());
    machineOne->StartFrame(1 * frameRate);
    machineOne->EndFrame(10 * frameRate);
    background->SetMachineNum(machineOne);
    background->AddDrawable(machineOne);

    auto machineTwo =
        std::make_shared<MachineAdapter>(L"MachineTwo", resourcesDir);
    machineTwo->SetMachineNumber(2);
    machineTwo->SetPosition(wxPoint(1500, 1050));
    machineTwo->SetTimeline(background->GetPicture()->GetTimeline());
    machineTwo->StartFrame(5 * frameRate);
    machineTwo->EndFrame( 18* frameRate);
    background->SetMachineNum(machineTwo);
    background->AddDrawable(machineTwo);

    return picture;
}

