//
// Created by jhon1 on 12.05.2025.
//

#include "CTarget.h"

CTarget::CTarget() : CActor(CVector2(rand()%640, rand()&480),
                            {CVector2(-2, -2), CVector2(-2, 2), CVector2(2, 2), CVector2(2, -2)}, 0.f),
                     TargetColliderDimensions({22, 22})
{
    Collider2D = new CCollider2D;
    PickUpCollider = new CCollider2D;
}

CTarget::~CTarget()
{
    delete Collider2D;
}

void CTarget::Render(SDL_Renderer &_Renderer) const
{
    CActor::Render(_Renderer);

    if(Collider2D != nullptr)
    {
        SDL_SetRenderDrawColor(&_Renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
        Collider2D->SetPosition(_Position, {(TargetColliderDimensions.x/2)* -1, (TargetColliderDimensions.y/2) * -1});
        Collider2D->SetDimension(TargetColliderDimensions);

        PickUpCollider->SetPosition(_Position, {-6, -6});
        PickUpCollider->SetDimension({12, 12});

        SDL_RenderDrawRect(&_Renderer, &PickUpCollider->GetBoundingBox());
        SDL_RenderDrawRect(&_Renderer, &Collider2D->GetBoundingBox());
    }
}

CCollider2D & CTarget::GetCollider()
{
    return *Collider2D;
}

CCollider2D & CTarget::GetPickUpCollider()
{
    return *PickUpCollider;
}
