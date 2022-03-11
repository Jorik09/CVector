#include "CVector.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    CVector a(5);
    CVector c(4);
    CVector b(4);
    double h;
    CVector s(4);

    b[3] = 1.9;
    cout << "a: "<<a;
    cout << "b: "<<b;
    cout << "c: "<<c;

    s = b + c;
    cout << "b + c =  "<<s;
    a = b - c;
    cout << "b - c =  "<<a;
    h = b * c;
    cout << "скалярное произвидение b и c:  "<< h << endl;

    return 0;
}
