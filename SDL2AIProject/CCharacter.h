//
// Created by jhon1 on 11.05.2025.
//

#ifndef CCHARACTER_H
#define CCHARACTER_H
#include "CActor.h"
#include "CTarget.h"
#include "ICollider2D.h"


class CAIController;

class CCharacter : public CActor, ICollider2D
{
    public:
    CCharacter();
    ~CCharacter();

    CCollider2D& GetCollider() override;
    CCollider2D& GetPickUpCollider() override;

    void Render(SDL_Renderer &_Renderer) const override;
    void Update(float DeltaTime) override;

    void SetController(CAIController* Controller);
    float GetHeading () const {return _Heading;}
    void Thrust(float Ratio, float DeltaTime);
    void SetRotationRate(const float _RotationRate) {RotationRate = _RotationRate;}

    //Get the next (first) Object in the list

    protected:
    CVector2 Velocity;
    //List of Objects that were collided with

    private:
    CCollider2D* PerceptionCollider;
    CCollider2D* PickUpCollider;

    CAIController* AIController;
    float RotationRate;
    CVector2 ColliderDimension;
    std::vector<CTarget*> Targets;

};



#endif //CCHARACTER_H
