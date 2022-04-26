#ifndef INC_4_1SEM_CVECTOR0_H
#define INC_4_1SEM_CVECTOR0_H

#include "CVector.h"

class CVector0: public CVector{
public:
    CVector0();
    CVector0(int size) : CVector(size){};

    CVector0(char* str);
    using CVector::operator=;


    int output(const char *FileName = NULL);
};
CVector0 operator+(const CVector &, const CVector &);
CVector0 operator-(const CVector &, const CVector &);
//double CVector0:: operator * (const CVector &, const CVector &);

#endif //INC_4_1SEM_CVECTOR0_H