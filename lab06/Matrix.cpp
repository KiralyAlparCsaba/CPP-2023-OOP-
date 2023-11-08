//
// Created by Alpar on 2023. 11. 08..
//

#include "Matrix.h"
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double*[mRows];
    for (int i = 0; i < mRows; i++) {
        this->mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = 0;
        }
    }

}
Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double*[mRows];
    for (int i = 0; i < mRows; i++) {
        this->mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;
    what.mElements = nullptr;
}

Matrix::~Matrix() {
    if(this->mElements != nullptr){
        for (int i = 0; i < mRows; i++) {
            delete[] mElements[i];
        }
        delete[] mElements;
    }


}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; i++) {
        this->mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_real_distribution<float> dist(a,b); // return a number in the given range
    for (int i = 0; i < mRows; i++) {
        this->mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = dist(mt);
        }
    }

}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; ++j) {
            os << this->mElements[i][j] << " ";
        }
        os << endl;
    }

}

bool Matrix::isSquare() const {
    return mRows == mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if(x.mRows != y.mRows || x.mCols != y.mCols){
        throw invalid_argument("Matrix dimensions mismatch");
    }
    Matrix result(x.mRows, x.mCols);
    for (int i = 0; i < x.mRows; i++) {
        for (int j = 0; j < x.mCols; ++j) {
            result.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return result;

}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if(x.mCols != y.mRows){
        throw invalid_argument("Matrix dimensions mismatch");
    }
    Matrix result(x.mRows, y.mCols);
    for (int i = 0; i < x.mRows; i++) {
        for (int j = 0; j < y.mCols; ++j) {
            for (int k = 0; k < x.mCols; ++k) {
                result.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];

            }
        }
    }
    return result;
}
