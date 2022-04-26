#include "CVector.h"
#include "CVector0.h"
#include "CVector1.h"

using namespace std;


CVector:: CVector(){
    this->Size = 0;
    this->data = NULL;
}

CVector:: CVector(int size)
{
    this->Size = size;
    this->data = new double [size];
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

CVector:: CVector(int size, const char* FileName) {

    this->Size = size;
    this->data = new double[size];

    ifstream in;
    in.open(FileName);
    if (!in.is_open())
        return;
    for (int i = 0; i < size; ++i)
        in >> this->data[i];
}

CVector:: CVector(const CVector &other){

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


CVector0 operator+(const CVector &first, const CVector &second) {  // перегруженный оператор +

    if (first.size() != second.size()) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        //assert(this->Size == other.Size);
    }

    CVector0 temp (first.size());

    for (int i = 0; i < first.size(); ++i) {
        temp.data[i] = first.data[i] + second.data[i];
    }

    return temp;
}

CVector& CVector:: operator+=(const CVector &other) {
    *this = *this + other;
    return *this;
}

CVector0 operator-(const CVector &first, const CVector &second) {  // перегруженный оператор +

    if (first.size() != second.size()) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        //assert(this->Size == other.Size);
    }

    CVector0 temp (first.size());

    for (int i = 0; i < first.size(); ++i) {
        temp.data[i] = first.data[i] - second.data[i];
    }

    return temp;
}

CVector& CVector:: operator-=(const CVector &other) {
    *this = *this - other;
    return *this;
}

/*double CVector:: operator*(const CVector0 &other) {  //перегруженный оператор скалярное произведение
    if (this->Size != other.Size) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        assert(this->Size == other.Size);
    }
    double S = 0;

    for (int i = 0; i < Size; ++i) {
        S += this->data[i] * other.data[i];
    }

    return S;
}*/

/*double CVector0:: operator * (const CVector &first, const CVector &second) {  // перегруженный оператор +

    if (first.size() != second.size()) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        //assert(this->Size == other.Size);
    }
    double S = 0;

    for (int i = 0; i < first.size(); ++i) {
        S += first.data[i] * second.data[i];
    }

    return S;
}*/

CVector:: ~CVector() {
    delete[] data;

}

CVector0:: CVector0(){
    this->Size = 0;
    this->data = NULL;
}

CVector0:: CVector0(char *str){
    this->Size = 0;
    for (int i = 0; str[i] != 0; ++i)
        if (str[i] == ' ')
            Size++;
    this->data = new double[this->Size];
    int k = 0;
    char *D = strtok(str, " ");
    while (D != NULL)
    {
        this->data[k] = atof(D);
        k++;
        D = strtok(NULL, " ");
    }
}

int CVector0::output(const char *FileName)
{
    ofstream out;
    out.open(FileName, fstream::out|fstream::app);
    if(!out.is_open())
        return -1;
    for(int i = 0; i < this->Size; ++i)
    {
        out << this->data[i] << ' ';
    }
    out << endl;
    out.close();
    return 0;
}

/*CVector0 CVector0::operator+(const CVector &first, const CVector &second) {
    return CVector0();
}*/

CVector1:: CVector1(){
    this->Size = 0;
    this->data = NULL;
}

CVector1:: CVector1(char *str){
    this->Size = 0;
    for (int i = 0; str[i] != 0; ++i)
        if (str[i] == ' ')
            Size++;
    this->data = new double[this->Size];
    int k = 0;
    char *D = strtok(str, " ");
    while (D != NULL)
    {
        this->data[k] = atof(D);
        k++;
        D = strtok(NULL, " ");
    }
}

int CVector1::output(const char *FileName)
{
    ofstream out;
    out.open(FileName, fstream::out|fstream::app);
    if(!out.is_open())
        return -1;
    for(int i = 0; i < this->Size; ++i)
    {
        out << this->data[i] << '\n';
    }
    out << endl;
    out.close();
    return 0;
}

ostream &operator<<(ostream &out, const CVector &value) {
    for (int i = 0; i < value.Size; ++i) {
        cout << value.data[i] << "\t";
    }
    cout << endl<< endl;
    return out;
}