
#ifndef INC_4_1SEM_CVECTOR_H
#define INC_4_1SEM_CVECTOR_H

#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cstring>

using namespace std;

class CVector {
protected:
    int Size;
    double *data;
public:
    CVector();

    CVector(int size);

    CVector(int size, const char* FileName);

    CVector(const CVector &other);

    CVector &operator=(const CVector &other);

    double & operator[](int index);

    const double & operator[](int index)const;

    CVector operator+(const CVector &other);

    CVector &operator+=(const CVector &other);

    CVector operator-(const CVector &other);

    CVector &operator-=(const CVector &other);

    double operator*(const CVector &other);

    virtual int output(const char *FileName = NULL){return 0;};

    ~CVector();

    friend ostream &operator<<(ostream &out, const CVector &value);
};





ostream &operator<<(ostream &out, const CVector &value);
#endif //INC_4_1SEM_CVECTOR_H