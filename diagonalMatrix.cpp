//------------------------------------------------------------------------------
// diagonalMatrix.cpp - содержит процедуру ввода параметров 
// для уже созданной диагональной матрицы.
//------------------------------------------------------------------------------
#include "diagonalMatrix.h"
#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// Ввод параметров диагональной матрицы из файла.

void In(diagonalMatrix &diagonalMatrixInstance, ifstream &ifstreamInstance) {
    ifstreamInstance >> diagonalMatrixInstance.dimension;
    diagonalMatrixInstance.diagonalValues = new double[diagonalMatrixInstance.dimension];

    for (int i = 0; i < diagonalMatrixInstance.dimension; ++i) {
        ifstreamInstance >> diagonalMatrixInstance.diagonalValues[i];
    }
}

// Случайный ввод параметров диагональной матрицы.
void InRnd(diagonalMatrix &diagonalMatrixInstance) {
    diagonalMatrixInstance.dimension = Random();
    diagonalMatrixInstance.diagonalValues = new double[diagonalMatrixInstance.dimension];

    for (int i = 0; i < diagonalMatrixInstance.dimension; ++i) {
        diagonalMatrixInstance.diagonalValues[i] = Random();
    }
}

//------------------------------------------------------------------------------
// Вывод параметров диагональной матрицы в форматируемый поток.
void Out(diagonalMatrix &diagonalMatrixInstance, std::ofstream &ofstreamInstance) {
    ofstreamInstance << "Diagonal matrix with dimension = " << diagonalMatrixInstance.dimension << "\n";
    for (int i = 0; i < diagonalMatrixInstance.dimension; ++i) {
        for (int j = 0; j < diagonalMatrixInstance.dimension; ++j) {
            if (i == j) {
                ofstreamInstance << diagonalMatrixInstance.diagonalValues[i] << " ";
            } else {
                ofstreamInstance << 0 << " ";
            }
        }
        ofstreamInstance << "\n";
    }
    ofstreamInstance << "Mean = " << Mean(diagonalMatrixInstance) << "\n" << std::endl;
}

//------------------------------------------------------------------------------
// Вычисление среднего компонентов диагональной матрицы.
double Mean(diagonalMatrix &diagonalMatrixInstance) {
    double sum = 0.0;

    for (int i = 0; i < diagonalMatrixInstance.dimension; ++i) {
            sum += diagonalMatrixInstance.diagonalValues[i];
    }

    return sum / (diagonalMatrixInstance.dimension * diagonalMatrixInstance.dimension);
}
