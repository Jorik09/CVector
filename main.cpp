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

    CVector0 a(2);
    CVector1 b(2);
    CVector0 s(2);
    CVector0 d(2);
    double h;
    a[0]= 1.1; a[1]= 2.2;
    b[0]= 1.0; b[1]= 1.0;
    cout << "a: "<<a;
    cout << "b: "<<b;
    s = a + b;
    if ((s[0]==2.1)&&(s[1]==3.2))
    cout << "AT1 success"<< endl;
    s = a - b;
    cout << "s "<<s;
    if ((s[0]==0.1)&&(s[1]==1.2))
    cout << "AT2 success"<< endl;


    /*CVector0 a(5);
    CVector0 c(4);
    CVector0 b(4);
    double h;
    CVector0 s(4);

    b[3] = 1.9;
    cout << "a: "<<a;
    cout << "b: "<<b;
    cout << "c: "<<c;

    s = b + c;
    cout << "b + c =  "<<s;
    a = b - c;
    cout << "b - c =  "<<a;
    h = b * c;
    cout << "скалярное произвидение b и c:  "<< h << endl;*/
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
