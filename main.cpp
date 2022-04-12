#include "CVector.h"
#include "CVector0.h"
#include "CVector1.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "rus");

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
    ifstream in;
    in.open("input.txt");
    if (!in.is_open())
        return 1;
    while (!in.eof())
    {
        CVector* A;
        int I;
        in >> I;
        char File[255];
        in >> File;
        char Data[500];
        in.getline(Data, 500);
        if (I == 0)
            A = new CVector0(Data);
        else if (I == 1)
            A = new CVector1(Data);
        A->output(File);
        delete A;
    }
    return 0;
}
