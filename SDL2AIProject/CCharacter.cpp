//
// Created by jhon1 on 11.05.2025.
//

#include "CCharacter.h"

#include <iostream>
#include <ostream>

#include "CAIController.h"

CCharacter::CCharacter() : CActor({400, 230},
                                  {CVector2(5, 0), CVector2(-5, 3), CVector2(-3, 0), CVector2(-5, -3)},
                                  0.f), Velocity(CVector2{0, 0}), AIController(nullptr), RotationRate(0),
                           ColliderDimension({250, 250})
{
    PerceptionCollider = new CCollider2D;
    PickUpCollider = new CCollider2D;
}

CCharacter::~CCharacter()
{
    delete PerceptionCollider;
    delete AIController;
}

void CCharacter::Render(SDL_Renderer &_Renderer) const {
    CActor::Render(_Renderer);

    if(PerceptionCollider != nullptr) {
        SDL_SetRenderDrawColor(&_Renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
        PerceptionCollider->SetPosition(_Position, {(ColliderDimension.x/2)* -1, (ColliderDimension.y/2) * -1});
        PerceptionCollider->SetDimension(ColliderDimension);

        PickUpCollider->SetPosition(_Position, {-10, -10});
        PickUpCollider->SetDimension({20, 20});

        SDL_RenderDrawRect(&_Renderer, &PerceptionCollider->GetBoundingBox());
        SDL_RenderDrawRect(&_Renderer, &PickUpCollider->GetBoundingBox());
    }
}

void CCharacter::Update(float DeltaTime)
{
    CActor::Update(DeltaTime);
    Velocity = Velocity * 0.98;

    _Position += (Velocity * DeltaTime);
    _Heading += (RotationRate * DeltaTime);

    if( _Position.x >= 640)
    {
        _Position.x = 640;
    }

    if(_Position.y >= 480)
    {
        _Position.y = 480;
    }
}

void CCharacter::SetController(CAIController* Controller)
{
    AIController = Controller;
}

void CCharacter::Thrust(float Ratio, float DeltaTime)
{
    Velocity += CVector2(_Heading) * Ratio * 350.f * DeltaTime;
}


CCollider2D & CCharacter::GetCollider()
{
    return *PerceptionCollider;
}

CCollider2D & CCharacter::GetPickUpCollider()
{
    return *PickUpCollider;
}
