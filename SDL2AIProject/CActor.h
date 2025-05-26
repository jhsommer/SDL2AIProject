//
// Created by jhon1 on 11.05.2025.
//

#ifndef CACTOR_H
#define CACTOR_H
#include <vector>
#include <SDL2/SDL_render.h>

#include "CVector2.h"


class CActor {

    public:
    CActor(const CVector2& Position, const std::vector<CVector2>& Edges, const float Heading);
    virtual ~CActor();

    virtual void Update(float DeltaTime);
    void Render(SDL_Renderer& _Renderer) const;

    protected:
    CVector2 _Position;
    float _Heading;

    private:
    std::vector<CVector2> _Edges;

};



#endif //CACTOR_H
