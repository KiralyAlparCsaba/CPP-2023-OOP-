#include <iostream>
#include "Matrix.h"

int main() {
    Matrix matrix(5, 5);
    Matrix matrix2(5, 5);
    matrix.randomMatrix(5,30);
    matrix2.randomMatrix(5,30);
    Matrix result = operator*(matrix, matrix2);
    result.printMatrix();
}