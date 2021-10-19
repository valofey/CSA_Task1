//------------------------------------------------------------------------------
// normalMatrix.cpp - содержит процедуру ввода параметров 
// для уже созданной нормальной матрицы.
//------------------------------------------------------------------------------

#include "normalMatrix.h"
#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// Ввод параметров нормальной матрицы из файла.
void In(normalMatrix &normalMatrixInstance, ifstream &ifstreamInstance) {
    ifstreamInstance >> normalMatrixInstance.dimension;
    normalMatrixInstance.matrix = new double *[normalMatrixInstance.dimension];

    for (int i = 0; i < normalMatrixInstance.dimension; ++i) {
        normalMatrixInstance.matrix[i] = new double[normalMatrixInstance.dimension];
        for (int j = 0; j < normalMatrixInstance.dimension; ++j) {
            ifstreamInstance >> normalMatrixInstance.matrix[i][j];
        }
    }
}

// Случайный ввод параметров нормальной матрицы.
void InRnd(normalMatrix &normalMatrixInstance) {
    normalMatrixInstance.dimension = Random();
    normalMatrixInstance.matrix = new double *[normalMatrixInstance.dimension];

    for (int i = 0; i < normalMatrixInstance.dimension; ++i) {
        normalMatrixInstance.matrix[i] = new double[normalMatrixInstance.dimension];
        for (int j = 0; j < normalMatrixInstance.dimension; ++j) {
            normalMatrixInstance.matrix[i][j] = Random()+(static_cast<float>(Random())/10);
        }
    }
}
//------------------------------------------------------------------------------
// Вывод параметров нормальной матрицы в форматируемый поток.
void Out(normalMatrix &normalMatrixInstance, std::ofstream &outputFileStream) {
    outputFileStream << "normalMatrixInstance matrix with dimension = " << normalMatrixInstance.dimension << "\n";
    for (int i = 0; i < normalMatrixInstance.dimension; ++i) {
        for (int j = 0; j < normalMatrixInstance.dimension; ++j) {
            outputFileStream << normalMatrixInstance.matrix[i][j] << " ";
        }
        outputFileStream << "\n";
    }
    outputFileStream << "Mean = " << Mean(normalMatrixInstance) << "\n" << std::endl;
}

//------------------------------------------------------------------------------
// Вычисление среднего компонентов нормальной матрицы.
double Mean(normalMatrix &normalMatrixInstance) {
    double sum = 0.0;

    for (int i = 0; i < normalMatrixInstance.dimension; ++i) {
        for (int j = 0; j < normalMatrixInstance.dimension; ++j) {
            sum += normalMatrixInstance.matrix[i][j];
        }
    }

    return sum / (normalMatrixInstance.dimension * normalMatrixInstance.dimension);
}
