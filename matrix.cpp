//------------------------------------------------------------------------------
// matrix.cpp - содержит процедуры связанные с созданием и обработкой 
// обобщенной матрицы.
//------------------------------------------------------------------------------
#include <fstream>
#include "matrix.h"
using namespace std;

//------------------------------------------------------------------------------
// Ввод параметров обобщенной матрицы из файла.
bool In(matrix &matrixInstance, ifstream &ifstreamInstance) {
    int key;
    ifstreamInstance >> key;
    switch(key) {
        case 1:
            matrixInstance.keyInstance = matrix::normalMatrix;
            In(matrixInstance.normalMatrixInstance, ifstreamInstance);
            return true;
        case 2:
            matrixInstance.keyInstance = matrix::diagonalMatrix;
            In(matrixInstance.diagonalMatrixInstance, ifstreamInstance);
            return true;
        case 3:
            matrixInstance.keyInstance = matrix::lowerTriangularMatrix;
            In(matrixInstance.lowerTriangularMatrixInstance, ifstreamInstance);
            return true;
        default:
            return false;
    }
}

// Случайный ввод обобщенной матрицы.
bool InRnd(matrix& matrixInstance) {
    auto key = rand() % 2 + 1;
    switch(key) {
        case 1:
            matrixInstance.keyInstance = matrix::normalMatrix;
            InRnd(matrixInstance.normalMatrixInstance);
            return true;
        case 2:
            matrixInstance.keyInstance = matrix::diagonalMatrix;
            InRnd(matrixInstance.diagonalMatrixInstance);
            return true;
        case 3:
            matrixInstance.keyInstance = matrix::lowerTriangularMatrix;
            InRnd(matrixInstance.lowerTriangularMatrixInstance);
            return true;
        default:
            return false;
}
}

//------------------------------------------------------------------------------
// Вывод параметров текущей матрицы в поток.
void Out(matrix &matrixInstance, ofstream &ofstreamInstance) {
    switch(matrixInstance.keyInstance) {
        case matrix::normalMatrix:
            Out(matrixInstance.normalMatrixInstance, ofstreamInstance);
            break;
        case matrix::diagonalMatrix:
            Out(matrixInstance.diagonalMatrixInstance, ofstreamInstance);
            break;
        case matrix::lowerTriangularMatrix:
            Out(matrixInstance.lowerTriangularMatrixInstance, ofstreamInstance);
            break;
        default:
            ofstreamInstance << "Incorrect matrix!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического элементов матрицы.
double Mean(matrix &matrixInstance) {
    switch(matrixInstance.keyInstance) {
        case matrix::normalMatrix:
            return Mean(matrixInstance.normalMatrixInstance);
            break;
        case matrix::diagonalMatrix:
            return Mean(matrixInstance.diagonalMatrixInstance);
            break;
        case matrix::lowerTriangularMatrix:
            return Mean(matrixInstance.lowerTriangularMatrixInstance);
            break;
        default:
            return 0.0;
    }
}
