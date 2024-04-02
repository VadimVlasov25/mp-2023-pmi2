#include <iostream>
#include "Matrix.h"
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));

    matrix mat1(2, 2);
    matrix mat2(2, 2);

    mat1.set_random(1.0, 10.0);
    mat2.set_random(1.0, 10.0);

    cout << "Matrix 1:" << endl;
    mat1.Print();

   
    cout << "Matrix 2:" << endl;
    mat2.Print();

    matrix mat3 = mat1 + mat2;
    cout << "Summa matrix:" << endl;
    mat3.Print();

    matrix mat4 = mat1 - mat2;
    cout << "Raznoct' matrix:" << endl;
    mat4.Print();

    matrix mat5 = mat1 * mat2;
    cout << "Proizvedenie matrix:" << endl;
    mat5.Print();

    return 0;
}
