//
// Created by jhon1 on 29.05.2025.
//

#ifndef CCOLLIDER2D_H
#define CCOLLIDER2D_H
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_stdinc.h>

#include "CActor.h"
#include "CVector2.h"

class CActor;

class CCollider2D {
    public:
    CCollider2D();
    ~CCollider2D();

    SDL_Rect& GetBoundingBox();

    SDL_bool IsColliding (CCollider2D& Collider)
    {
        const SDL_Rect* Temp = Collider.m_Collider;
        return SDL_HasIntersection(m_Collider, Temp);
    }

    void SetPosition (const CVector2 &pos, const CVector2 &offset);
    void SetDimension (const CVector2 &dim);
    CActor* GetParent() const;

    private:
    SDL_Rect* m_Collider;
};



#endif //CCOLLIDER2D_H
