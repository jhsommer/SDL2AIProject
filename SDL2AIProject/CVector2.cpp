//
// Created by jhon1 on 11.05.2025.
//

#include "CVector2.h"

#include <complex>
#define pi 3.1415926535897932384626433832795

CVector2::CVector2(float X, float Y) : x(X), y(Y)
{
}

CVector2::CVector2(float AngleDeg) {
    float AngleRad = pi *  AngleDeg / 180.f;

    x = cos(AngleRad);
    y = sin(AngleRad);
}

float CVector2::GetDistance(const CVector2 &other) const
{
    float DeltaX = x - other.x;
    float DeltaY = y - other.y;

    return sqrt(DeltaX * DeltaX + DeltaY * DeltaY);
}

void CVector2::Rotate(float Angle) {
    float AngleRad = Angle * pi / 180.f;
    float NewX = cos(AngleRad) * x - sin(AngleRad) * y;
    float NewY = sin(AngleRad) * x + cos(AngleRad) * y;

    x = NewX;
    y = NewY;
}

float CVector2::GetHeading() const {
   float DegRad = atan2(y, x);
    float AngleRad = 180.f * DegRad  / pi ;
    return AngleRad;
}

CVector2 operator+(const CVector2 &v1, const CVector2 &v2)
{
    return (CVector2(v1.x + v2.x, v1.y + v2.y));
}

CVector2 operator-(const CVector2 &v1, const CVector2 &v2) {

    return (CVector2(v1.x - v2.x, v1.y - v2.y));
}

CVector2 operator*(const CVector2 &V1, const float Scalar) {

    return (CVector2(V1.x * Scalar, V1.y * Scalar));
}

void operator+=(CVector2 &v1, const CVector2 &v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
}



