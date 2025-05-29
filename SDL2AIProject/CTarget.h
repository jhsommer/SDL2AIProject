//
// Created by jhon1 on 12.05.2025.
//

#ifndef CTARGET_H
#define CTARGET_H
#include "CActor.h"
#include "ICollider2D.h"


class CTarget : public CActor, ICollider2D
{
public:
    CTarget();
    void Render(SDL_Renderer &_Renderer) const override;
    CCollider2D& GetCollider() override;

private:
    CCollider2D* Collider2D;
};



#endif //CTARGET_H
