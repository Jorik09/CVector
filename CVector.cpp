

#include "CVector.h"


using namespace std;

CVector:: CVector(int size) {

    this->Size = size;
    this->data = new double[size];

    for (int i = 0; i < size; ++i) {
        data[i] = i + (double)rand()/((double)rand()-10);

    }

}

CVector:: CVector(const CVector &other) {

    this->Size = other.Size;

    this->data = new double[other.Size];

    for (int i = 0; i < other.Size; ++i) {
        this->data[i] = other.data[i];
    }

}

CVector& CVector:: operator=(const CVector &other) {

    if (this == &other) return *this;

    this->Size = other.Size;

    delete[] data;

    this->data = new double[other.Size];

    for (int i = 0; i < other.Size; ++i) {
        this->data[i] = other.data[i];
    }
    return *this;
}

double& CVector:: operator[](int index){
    if (index >= this->Size){
        int N;
        N = this->Size;
        double *B;
        B = new double[N];

        for (int i = 0; i < N; ++i) {
            B[i] = this->data[i];
        }
        delete [] data;
        this->data = new double[index + 1];
        this->Size = index + 1;

        for (int i = 0; i < index + 1; ++i) {
            if(i >= N){
                this->data[i] = 0;
            }
            else this->data[i] = B[i];
        }
        delete [] B;
    }
    return data[index];
}

const double& CVector:: operator[](int index)const{
    return data[index];
}


CVector CVector:: operator+(const CVector &other) {  // перегруженный оператор +

    if (this->Size != other.Size) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        assert(this->Size == other.Size);
    }

    CVector temp(other.Size);

    for (int i = 0; i < Size; ++i) {
        temp.data[i] = this->data[i] + other.data[i];
    }

    return temp;
}

CVector& CVector:: operator+=(const CVector &other) {
    *this = *this + other;
    return *this;
}

CVector CVector:: operator-(const CVector &other) {  //перегруженный оператор -
    if (this->Size != other.Size) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        assert(this->Size == other.Size);
    }

    CVector temp(other.Size);


    for (int i = 0; i < Size; ++i) {
        temp.data[i] = this->data[i] - other.data[i];
    }

    return temp;
}

CVector& CVector:: operator-=(const CVector &other) {
    *this = *this - other;
    return *this;
}

double CVector:: operator*(const CVector &other) {  //перегруженный оператор скалярное произведение
    if (this->Size != other.Size) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        assert(this->Size == other.Size);
    }
    double S = 0;

    for (int i = 0; i < Size; ++i) {
        S += this->data[i] * other.data[i];
    }

    return S;
}

CVector:: ~CVector() {
    delete[] data;

}


ostream &operator<<(ostream &out, const CVector &value) {
    for (int i = 0; i < value.Size; ++i) {
        cout << value.data[i] << "\t";
    }
    cout << endl<< endl;
    return out;
}