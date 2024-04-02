#include <iostream>
#include "vecmat.h"
#include <iomanip>
#include <ctime>
using namespace std;

matrix::matrix(int n_, int m_) : n(n_), m(m_) {
    A = new double* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new double[m];
        for (int j = 0; j < m; j++)
            A[i][j] = 0.0;
    }
}

matrix::matrix(const matrix& B) : n(B.n), m(B.m) {
    A = new double* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new double[m];
        for (int j = 0; j < m; j++)
            A[i][j] = B.A[i][j];
    }
}

matrix::~matrix() {
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
}

void matrix::set_random(double a, double b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = a + (b - a) * (double)rand() / (double)RAND_MAX;
        }
    }
}

void matrix::Print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(4) << A[i][j] << " ";
        }
        cout << endl;
    }
}

matrix matrix::plus(const matrix& B) {
    matrix c(n, m);
    if (n == B.n && m == B.m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c.A[i][j] = A[i][j] + B.A[i][j];
            }
        }
    }
    else {
        cout << "ERROR" << endl << "return NULL matrix" << endl;
    }
    return c;
}

matrix matrix::operator +(const matrix& B) {
    matrix c(n, m);
    if (n == B.n && m == B.m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c.A[i][j] = A[i][j] + B.A[i][j];
            }
        }
    }
    else {
        cout << "ERROR" << endl << "return NULL matrix" << endl;
    }
    return c;
}

matrix matrix::operator -(const matrix& B) {
    matrix c(n, m);
    if (n == B.n && m == B.m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c.A[i][j] = A[i][j] - B.A[i][j];
            }
        }
    }
    else {
        cout << "ERROR" << endl << "return NULL matrix" << endl;
    }
    return c;
}

matrix& matrix::operator =(const matrix& B) {
    if (this == &B) return *this;
    if (n != B.n || m != B.m) {
        for (int i = 0; i < n; i++)
            delete[] A[i];
        delete[] A;
        A = new double* [B.n];
        for (int i = 0; i < n; i++)
            A[i] = new double[B.m];
        m = B.m;
        n = B.n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = B.A[i][j];
        }
    }
    return *this;
}

matrix matrix::operator * (const matrix& B) {
    matrix c(n, B.m);
    if (m == B.n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < B.m; j++) {
                double q = 0.0;
                for (int k = 0; k < B.n; k++)
                    q += A[i][k] * B.A[k][j];
                c.A[i][j] = q;
            }
        }
    }
    else {
        cout << "ERROR" << endl << "return NULL matrix" << endl;
    }
    return c;
}

matrix& matrix::operator += (const matrix& B) {
    if (n == B.n && m == B.m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] += B.A[i][j];
            }
        }
    }
    else {
        cout << "ERROR" << endl;
    }
    return *this;
}

matrix& matrix::operator -= (const matrix& B) {
    if (n == B.n && m == B.m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] -= B.A[i][j];
            }
        }
    }
    else {
        cout << "ERROR" << endl;
    }
    return *this;
}

ostream& operator << (ostream& os, const matrix& B) {
    os << "Your Matrix" << endl;
    for (int i = 0; i < B.n; i++) {
        for (int j = 0; j < B.m; j++) {
            os << B.A[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator >> (istream& is, matrix& B) {
    cout << "Print raz-r (n, m):  ";
    is >> B.n >> B.m;
    B.A = new double* [B.n];
    for (int i = 0; i < B.n; i++) {
        B.A[i] = new double[B.m];
        cout << "Print " << i + 1 << " Strok:   ";
        for (int j = 0; j < B.m; j++) {
            is >> B.A[i][j];
        }
    }
    return is;
}

double& matrix::operator()(const int i, const int j) {
    return A[i][j];
}

const double& matrix::operator()(const int i, const int j) const {
    return A[i][j];
}
Vector::Vector(int size) : size(size)
{
    vec = new double[size];
}

void Vector::Print()
{
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << endl;
    }
}

void Vector::Generate(int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        vec[i] = min + (max - min) * ((double)rand() / double(RAND_MAX));
    }
}

Vector& Vector::operator=(const Vector& tor)
{
    if (this == &tor) return *this;
    if (size != tor.size)
    {
        delete[] vec;
        vec = new double[tor.size];
        size = tor.size;
    }
    for (int i = 0; i < size; i++)
    {
        vec[i] = tor.vec[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector& tor)
{
    if (size != tor.size)
    {
        cout << "wrong len" << endl;
        return *this;
    }
    Vector result(size);
    for (int i = 0; i < size; i++)
    {
        result.vec[i] = vec[i] + tor.vec[i];
    }
    return result;
}

Vector Vector::operator-(const Vector& tor)
{
    if (size != tor.size)
    {
        cout << "wrong len" << endl;
        return *this;
    }
    Vector result(size);
    for (int i = 0; i < size; i++)
    {
        result.vec[i] = vec[i] - tor.vec[i];
    }
    return result;
}

Vector& Vector::operator+=(const Vector& tor)
{
    if (size != tor.size)
    {
        cout << "wrong len" << endl;
        return *this;
    }
    for (int i = 0; i < size; i++)
    {
        vec[i] += tor.vec[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& tor)
{
    if (size != tor.size)
    {
        cout << "wrong len" << endl;
        return *this;
    }
    for (int i = 0; i < size; i++)
    {
        vec[i] -= tor.vec[i];
    }
    return *this;
}

Vector Vector::operator*(double scalar)
{
    Vector result(size);
    for (int i = 0; i < size; i++)
    {
        result.vec[i] = vec[i] * scalar;
    }
    return result;
}

double& Vector::operator[](int index)
{
    return vec[index];
}

ostream& operator<<(ostream& os, const Vector& vec)
{
    for (int i = 0; i < vec.size; i++)
    {
        os << vec.vec[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, Vector& vec)
{
    for (int i = 0; i < vec.size; i++)
    {
        is >> vec.vec[i];
    }
    return is;
}

double Vector::Norm()
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += vec[i] * vec[i];
    }
    return sqrt(sum);
}

Vector::~Vector()
{
    delete[] vec;
}