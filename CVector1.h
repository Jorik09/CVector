

#ifndef INC_4_1SEM_CVECTOR1_H
#define INC_4_1SEM_CVECTOR1_H

#include "CVector.h"

class CVector1: public CVector{
public:
    CVector1();
    CVector1(int size) : CVector (size){};
    CVector1(char* str);
    CVector1(const CVector &other) : CVector(other){};
    using CVector :: operator=;

    int output(const char *FileName = NULL);
};

#endif //INC_4_1SEM_CVECTOR1_H