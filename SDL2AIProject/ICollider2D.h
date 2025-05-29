//
// Created by jhon1 on 29.05.2025.
//

#ifndef ICOLLIDER2D_H
#define ICOLLIDER2D_H
#include "CCollider2D.h"


class ICollider2D {
    public:
        virtual ~ICollider2D()= default;
        virtual CCollider2D& GetCollider() = 0;
};



#endif //ICOLLIDER2D_H
