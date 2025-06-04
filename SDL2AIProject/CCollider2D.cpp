//
// Created by jhon1 on 29.05.2025.
//

#include "CCollider2D.h"

CCollider2D::CCollider2D()
{
    m_Collider = new SDL_Rect;

    m_Collider->x = 0;
    m_Collider->y = 0;
    m_Collider->w = 0;
    m_Collider->h = 0;
}

CCollider2D::~CCollider2D()
{
    delete m_Collider;
}

SDL_Rect & CCollider2D::GetBoundingBox() {
    return *m_Collider;
}

void CCollider2D::SetPosition(const CVector2 &pos, const CVector2 &offset) {
    m_Collider->x = pos.x + offset.x;
    m_Collider->y = pos.y + offset.y;
}

void CCollider2D::SetDimension(const CVector2 &dim) {
    m_Collider->w = dim.x;
    m_Collider->h = dim.y;
}
