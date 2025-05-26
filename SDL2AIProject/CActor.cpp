//
// Created by jhon1 on 11.05.2025.
//

#include "CActor.h"

CActor::CActor(const CVector2 &Position, const std::vector<CVector2> &Edges, const float Heading) : _Position(Position), _Edges(Edges), _Heading(Heading)
{
}

CActor::~CActor()
= default;

void CActor::Update(float DeltaTime)
{

}

void CActor::Render(SDL_Renderer &_Renderer) const
{
    std::vector<CVector2> RotadedEdges;
    for(auto Copy : _Edges)
    {
        Copy.Rotate(_Heading);
        RotadedEdges.push_back(Copy);
    }

    for (int i = 0; i < RotadedEdges.size(); i++)
    {
        CVector2 OffsetFrom = RotadedEdges[i];
        CVector2 OffsetTo = RotadedEdges[(i + 1) % RotadedEdges.size()];

        const CVector2 From = _Position + OffsetFrom;
        const CVector2 To = _Position + OffsetTo;

        SDL_RenderDrawLine(&_Renderer, From.x, From.y, To.x, To.y);
    }
}
