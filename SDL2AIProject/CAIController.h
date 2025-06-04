//
// Created by jhon1 on 30.05.2025.
//

#ifndef CAICONTROLLER_H
#define CAICONTROLLER_H

#include <vector>

#include "CActor.h"

class CTarget;
class CCharacter;

class CAIController
{
    public:
    CAIController();
    ~CAIController();
    void SetControlledCharacter(CCharacter* _Character);
    void Update(float DeltaTime, const std::vector<CTarget*>& LevelTargets);


    protected:
    CCharacter* ControlledCharacter;

    private:
    std::vector<CTarget*> TargetsInOrder;
    void GoToTarget(CTarget* _Target) const;
};



#endif //CAICONTROLLER_H
