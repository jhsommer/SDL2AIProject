//
// Created by jhon1 on 11.05.2025.
//

#ifndef CVECTOR2_H
#define CVECTOR2_H



class CVector2
{
public:
    CVector2(float X, float Y);

    CVector2(float AngleDeg);

    float x, y;

    void Rotate(float Angle);
};

CVector2 operator+ (const CVector2 &v1, const CVector2 &v2);
CVector2 operator- (const CVector2 &v1, const CVector2 &v2);

#endif //CVECTOR2_H
