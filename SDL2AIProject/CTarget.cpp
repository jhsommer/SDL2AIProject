//
// Created by jhon1 on 12.05.2025.
//

#include "CTarget.h"

CTarget::CTarget() : CActor(CVector2 (CVector2(200, 150)), {CVector2(-2,-2), CVector2(-2, 2), CVector2(2, 2), CVector2 (2, -2)}, 0.f )
 {
    Collider2D = new CCollider2D;
 }

void CTarget::Render(SDL_Renderer &_Renderer) const {
    CActor::Render(_Renderer);

    if(Collider2D != nullptr) {
        SDL_SetRenderDrawColor(&_Renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
        Collider2D->SetPosition(_Position, {-50, -50});
        Collider2D->SetDimension({100, 100});
        SDL_RenderDrawRect(&_Renderer, &Collider2D->GetBoundingBox());
    }
}

CCollider2D & CTarget::GetCollider()
{
    return *Collider2D;
}
