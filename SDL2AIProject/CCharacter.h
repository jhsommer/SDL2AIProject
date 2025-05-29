//
// Created by jhon1 on 11.05.2025.
//

#ifndef CCHARACTER_H
#define CCHARACTER_H
#include "CActor.h"
#include "ICollider2D.h"


class CCharacter : public CActor, ICollider2D
{
    public:
    CCharacter();
    ~CCharacter();
    CCollider2D& GetCollider() override;
    void Render(SDL_Renderer &_Renderer) const override;
    //CCollider2D& GetCollider() override;
    private:
    CCollider2D* Collider2D;


};



#endif //CCHARACTER_H
