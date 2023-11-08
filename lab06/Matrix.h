//
// Created by Alpar on 2023. 11. 08..
//

#ifndef CPP_2022_MATRIX_H
#define CPP_2022_MATRIX_H
#include <iostream>
using namespace std;

class Matrix {
public:
//Methods
// Default constructor
    Matrix(int mRows = 10, int mCols =10);
// Copy constructor
    Matrix(const Matrix& what);
// Move constructor
    Matrix(Matrix&& what );
// Destructor
    ~Matrix();

    //fills the matrix with identical elements
    void fillMatrix(double value);
    //fills the matrix with random real numbers in the range [a, b)
    void randomMatrix(int a, int b); //fills
    void printMatrix(ostream& os = cout) const;
    bool isSquare() const;
    int getRows() const { return this->mRows;}
    int getCols() const { return this->mCols;}
    friend Matrix operator+(const Matrix& x, const Matrix& y);

    // operation is permitted on matrices having proper dimensions
    // otherwise throws an out_of_range exception!!
    friend Matrix operator*(const Matrix& x, const Matrix& y);

private:
//Data
    double ** mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};




#endif //CPP_2022_MATRIX_H
