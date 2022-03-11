
#ifndef INC_4_1SEM_CVECTOR_H
#define INC_4_1SEM_CVECTOR_H

#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

class CVector {
 //private:
     int Size;
     double *data;
 public:

     CVector(int size);

     CVector(const CVector &other);

     CVector &operator=(const CVector &other);

     double & operator[](int index);

     const double & operator[](int index)const;


     CVector operator+(const CVector &other);


     CVector &operator+=(const CVector &other);

     CVector operator-(const CVector &other);

     CVector &operator-=(const CVector &other);

     double operator*(const CVector &other);

     ~CVector();

     friend ostream &operator<<(ostream &out, const CVector &value);


 };

 ostream &operator<<(ostream &out, const CVector &value);

#endif //INC_4_1SEM_CVECTOR_H