//
// Created by jhon1 on 30.05.2025.
//

#include "CAIController.h"

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

CAIController::CAIController() : ControlledCharacter(nullptr)
{
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
    CTarget* NextTarget = nullptr;

    //acces the next Target in the list of Objects
    for (CTarget* Target : LevelTargets)
    {
        if(ControlledCharacter == nullptr) return;
        if(Target == nullptr) return;

            if(ControlledCharacter->GetCollider().IsColliding(Target->GetCollider()))
            {
                TargetsInOrder.push_back(Target);
                if(NextTarget == nullptr)
                {
                    NextTarget = TargetsInOrder.back();
                }

            }

    }

    if(NextTarget != nullptr)
    {
        GoToTarget(NextTarget);
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



