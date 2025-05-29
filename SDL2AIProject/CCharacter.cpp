//
// Created by jhon1 on 11.05.2025.
//

#include "CCharacter.h"

CCharacter::CCharacter() : CActor({320, 200}, {CVector2 (5,0), CVector2 (-5, 3), CVector2 (-3, 0), CVector2 (-5, -3)}, 0.f )
{
    Collider2D = new CCollider2D;
}

CCharacter::~CCharacter() {
    delete Collider2D;
}

void CCharacter::Render(SDL_Renderer &_Renderer) const {
    CActor::Render(_Renderer);

    if(Collider2D != nullptr) {
        SDL_SetRenderDrawColor(&_Renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
        Collider2D->SetPosition(_Position, {-50, -50});
        Collider2D->SetDimension({100, 100});
        SDL_RenderDrawRect(&_Renderer, &Collider2D->GetBoundingBox());
    }
}

CCollider2D & CCharacter::GetCollider()
{
    return *Collider2D;
}
