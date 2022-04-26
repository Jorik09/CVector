

#ifndef INC_4_1SEM_CVECTOR1_H
#define INC_4_1SEM_CVECTOR1_H

#include "CVector.h"

class CVector1: public CVector{
public:
    CVector1();

    CVector1(char* str);

    int output(const char *FileName = NULL);
};

#endif //INC_4_1SEM_CVECTOR1_H