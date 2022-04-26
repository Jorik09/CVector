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

public:
    CVector();

    CVector(int size);

    CVector(int size, const char* FileName);

    CVector(const CVector &other);

    CVector &operator=(const CVector &other);

    double & operator[](int index);
    double *data;
    int size() const {
        return Size;
    }

    const double & operator[](int index)const;
    //CVector0 operator+(const CVector&, const CVector&);

    CVector &operator+=(const CVector &other);

    //CVector operator-(const CVector &other);

    CVector &operator-=(const CVector &other);

    //double operator*(const CVector &other);

    virtual int output(const char *FileName = NULL)=0;

    ~CVector();

    friend ostream &operator<<(ostream &out, const CVector &value);
};





ostream &operator<<(ostream &out, const CVector &value);
#endif //INC_4_1SEM_CVECTOR_H