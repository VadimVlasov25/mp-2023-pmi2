#pragma once
#ifndef VECMAT_H
#define VECMAT_H
using namespace std;
class matrix
{

private:
    double** A;
    int n, m;
public:
    matrix(int n = 1, int m = 1);
    matrix(const matrix& B);
    ~matrix();
    void set_random(double a, double b);
    void Print();
    matrix plus(const matrix& B);
    matrix operator + (const matrix& B);
    matrix operator - (const matrix& B);
    matrix operator * (const matrix& B);
    matrix& operator = (const matrix& B);
    matrix& operator += (const matrix& B);
    matrix& operator -= (const matrix& B);
    vector operator *(const vector& b);
    friend matrix operator *(const matrix& a, const double zxc);
    friend matrix operator *(const double zxc, const matrix& a);
    double operator()(const int i, const  int j);
    friend ostream& operator <<(ostream& out, const matrix& a);
    friend istream& operator >>(istream& in, matrix& a);
    friend double maxim_st(int i, matrix& MAT, vector& zxc);
    friend void prym_hod(matrix& MAT, vector& b);
    friend void obr_hod(matrix& MAT, vector& otvet_polych, vector& b);
};
class vector
{
private:
    int size;
public:
    double* vec;
    vector(int size_ = 1);
    vector(const vector& B);
    ~vector();
    vector& operator = (const vector& B);
    vector operator + (const vector& B);
    vector operator - (const vector& B);
    vector& operator += (const vector& B);
    vector& operator -= (const vector& B);
    friend vector operator * (vector zxc, double q);
    friend vector operator * (double q, vector zxc);
    vector operator ++ (int k);
    vector& operator ++ ();
    vector operator - ();
    double& operator [] (const int i) const;
    void set_random_vec(double a, double b);
    void set_vector_size(int size_);
    void  Print();
    void set_some_vec();
    friend istream& operator >> (istream& in, vector& b);
    friend ostream& operator << (ostream& out, const vector& b);
    friend class matrix;
};
#endif