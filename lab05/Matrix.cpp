#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) : mRows(mRows), mCols(mCols) {
    this->mElements = new double*[mRows];
    for (int i = 0; i < this->mRows; ++i) {
        this->mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &copy) {
    this->mRows = copy.mRows;
    this->mCols = copy.mCols;
    this->mElements = new double*[copy.mRows];
    for (int i = 0; i < this->mRows; ++i) {
        this->mElements[i] = new double[copy.mCols];
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = copy.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&move) {
    this->mRows = move.mRows;
    this->mCols = move.mCols;
    this->mElements = move.mElements;
    move.mElements = nullptr;
    move.mRows = move.mCols = 0;
}

Matrix::~Matrix() {
    for (int i = 0; i < this->mRows; ++i) {
        delete[] mElements[i];
    }
    delete[] mElements;
    this->mRows = this->mCols = 0;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<> dist(a, b);
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = dist(mt);
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            os << this->mElements[i][j] << " ";
        }
        os << endl;
    }
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows or x.mCols != y.mCols) {
        throw out_of_range("not the same dimensions");
    }
    Matrix res(x.mRows, y.mCols);
    for (int i = 0; i < res.mRows; ++i) {
        for (int j = 0; j < res.mCols; ++j) {
            res.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return res;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mCols != y.mRows) {
        throw out_of_range("wrong dimensions");
    }
    Matrix res(x.mRows, y.mCols);
    for (int i = 0; i < res.mRows; ++i) {
        for (int j = 0; j < res.mCols; ++j) {
            res.mElements[i][j] = 0;
            for (int k = 0; k < x.mCols; ++k) {
                res.mElements[i][j] += x[i][k] * y[k][j];
            }
        }
    }
    return res;
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix(os);
    return os;
}

double* Matrix::operator[](int index) {
    if (index < 0 or index >= this->mRows)
        throw out_of_range("wrong index");
    return this->mElements[index];
}

double *Matrix::operator[](int index) const {
    if (index < 0 or index >= this->mRows)
        throw out_of_range("wrong index");
    return this->mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (this == &mat) {
        return *this;
    }
    if (this->mRows != mat.mRows or this->mCols != mat.mCols) {
        throw out_of_range("not the same dimensions");
    }
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = mat.mElements[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
    for (int i = 0; i < this->mRows; ++i) {
        delete[] mElements[i];
    }
    delete[] mElements;

    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    this->mElements = mat.mElements;
    mat.mElements = nullptr;
    mat.mRows = 0;
    return *this;
}


