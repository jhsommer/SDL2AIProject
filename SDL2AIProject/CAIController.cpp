//
// Created by jhon1 on 30.05.2025.
//

#include "CAIController.h"

#include <algorithm>
#include <iostream>
#include <ostream>

#include "CCharacter.h"
#include "CTarget.h"

float ClampAngle(float Angle)
{
    while (Angle > 180) Angle -= 360;
    while (Angle <= -180) Angle += 360;

    return Angle;
}

CAIController::CAIController() : ControlledCharacter(nullptr), DirectionToNextPoint(0,0) {
}

CAIController::~CAIController() = default;

void CAIController::SetControlledCharacter(CCharacter* _Character)
{
    if(_Character != nullptr)
    {
        _Character->SetController(this);
    }

    ControlledCharacter = _Character;
}

void CAIController::Update(float DeltaTime, const std::vector<CTarget*>& LevelTargets)
{
    if(!bInit)
    {
        bInit = true;
        return;
    }

    TargetsInOrder.clear();
    //acces the next Target in the list of Objects
    for (CTarget* Target : LevelTargets)
    {
        if(ControlledCharacter == nullptr) return;
        if(Target == nullptr) return;

            if(ControlledCharacter->GetCollider().IsColliding(Target->GetCollider()))
            {

                if(std::find(TargetsInOrder.begin(), TargetsInOrder.end(), Target) == TargetsInOrder.end() )
                {
                    TargetsInOrder.push_back(Target);
                    //std::cout << TargetsInOrder.size() << std::endl;
                }
            }

    }

    CTarget* NextTarget = nullptr;
    if(!TargetsInOrder.empty())
    {
        NextTarget = TargetsInOrder.front();
    }


    if(NextTarget != nullptr && ControlledCharacter != nullptr)
    {
        GoToTarget(NextTarget);
        ControlledCharacter->Thrust(0.25f, DeltaTime);

    }

    if( NextTarget == nullptr && ControlledCharacter != nullptr)
    {
        GoToRandomPosition();
        ControlledCharacter->Thrust(0.25f, DeltaTime);
    }
}

void CAIController::GoToTarget(CTarget* _Target) const
{
        CVector2 DirectionToTarget = _Target->GetPosition() - ControlledCharacter->GetPosition();
        float TargetHeading = DirectionToTarget.GetHeading();
        float DeltaHeading = TargetHeading - ControlledCharacter->GetHeading();

        DeltaHeading = ClampAngle(DeltaHeading);

        if(DeltaHeading > 0)
        {
           ControlledCharacter->SetRotationRate(360.f);
        }
        else ControlledCharacter->SetRotationRate(-360.f);
}

void CAIController::GoToRandomPosition()
{

   if (!bHasPoint)
    {
       DirectionToNextPoint = CVector2(rand()%640, rand()%480);
       bHasPoint = true;
    }

        CVector2 Direction = DirectionToNextPoint - ControlledCharacter->GetPosition();
        float PointHeading = Direction.GetHeading();
        float DeltaHeading = PointHeading - ControlledCharacter->GetHeading();

        DeltaHeading = ClampAngle(DeltaHeading);

        if(DeltaHeading > 5.f)
        {
            ControlledCharacter->SetRotationRate(360.f);
        }
        else if (DeltaHeading < -5.f)
        {
            ControlledCharacter->SetRotationRate(-360.f);
        }

        else
        {
            ControlledCharacter->SetRotationRate(0.f);
        }

        if( ControlledCharacter->GetPosition().GetDistance(DirectionToNextPoint)< 20)
        {
            bHasPoint = false;
        }

    std::cout << DirectionToNextPoint.x << ", " << DirectionToNextPoint.y << std::endl;

}




