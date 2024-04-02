#pragma once
#ifndef GAUSS_H
#define GAUSS_H
using namespace std;

class gauss
{
	Matrix* A;
	Vector* x;
	Vector* b;
	int status;
public:
	Gauss(Matrix* my A, Vector* my x, Vector my b);
	


}
#endif