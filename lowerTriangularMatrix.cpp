//------------------------------------------------------------------------------
// lowerTriangularMatrix.cpp - содержит процедуру ввода параметров 
// для уже созданной нижнетреугольной матрицы.
//------------------------------------------------------------------------------
#include "lowerTriangularMatrix.h"
#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// Ввод параметров нижнетреугольной матрицы из файла.

void In(lowerTriangularMatrix &lowerTriangularMatrixInstance, ifstream &ifstreamInstance) {
    ifstreamInstance >> lowerTriangularMatrixInstance.dimension;
    int realDimension = (lowerTriangularMatrixInstance.dimension + 1) / 2;
    lowerTriangularMatrixInstance.lowerTriangularValues = new double[realDimension];

    for (int i = 0; i < realDimension; ++i) {
        ifstreamInstance >> lowerTriangularMatrixInstance.lowerTriangularValues[i];
    }
}

// Случайный ввод параметров нижнетреугольной матрицы.
void InRnd(lowerTriangularMatrix &lowerTriangularMatrixInstance) {
    lowerTriangularMatrixInstance.dimension = Random();
    int realDimension = (lowerTriangularMatrixInstance.dimension + 1) / 2;
    lowerTriangularMatrixInstance.lowerTriangularValues = new double[realDimension];

    for (int i = 0; i < realDimension; ++i) {
        lowerTriangularMatrixInstance.lowerTriangularValues[i] = Random();
    }
}

//------------------------------------------------------------------------------
// Вывод параметров нижнетреугольной матрицы в форматируемый поток.
void Out(lowerTriangularMatrix &lowerTriangularMatrixInstance, std::ofstream &ofstreamInstance) {
    ofstreamInstance << "lowerTriangular matrix with dimension = " << lowerTriangularMatrixInstance.dimension << "\n";
    for (int i = 0; i < lowerTriangularMatrixInstance.dimension; ++i) {
        for (int j = 0; j < lowerTriangularMatrixInstance.dimension; ++j) {
            if (j > i) {
                ofstreamInstance << 0 << " ";
            } else {
                int pos = (lowerTriangularMatrixInstance.dimension * i) + j - ((i * (i + 1)) / 2);
                ofstreamInstance << lowerTriangularMatrixInstance.lowerTriangularValues[pos] << " ";
            }
        }
        ofstreamInstance << "\n";
    }
    ofstreamInstance << "Mean = " << Mean(lowerTriangularMatrixInstance) << std::endl;
}

//------------------------------------------------------------------------------
// Вычисление среднего компонентов нижнетреугольной матрицы.
double Mean(lowerTriangularMatrix &lowerTriangularMatrixInstance) {
    double sum = 0.0;
    int realDimension = (lowerTriangularMatrixInstance.dimension + 1) / 2;

    for (int i = 0; i < realDimension; ++i) {
            sum += lowerTriangularMatrixInstance.lowerTriangularValues[i];
    }

    return sum / (lowerTriangularMatrixInstance.dimension * lowerTriangularMatrixInstance.dimension);
}
