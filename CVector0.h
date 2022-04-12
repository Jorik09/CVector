

#ifndef INC_4_1SEM_CVECTOR0_H
#define INC_4_1SEM_CVECTOR0_H

#include "CVector.h"

class CVector0: public CVector{
public:
    CVector0();

    CVector0(char* str);

    int output(const char *FileName = NULL);
};


#endif //INC_4_1SEM_CVECTOR0_H
