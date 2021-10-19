//------------------------------------------------------------------------------
// lowerTriangularMatrix.h - содержит описание нижнетреугольной матрицы и её интерфейса.
//------------------------------------------------------------------------------

# include "randomHelper.h"
#include <fstream>
using namespace std;

//Диагональная матрица.
struct lowerTriangularMatrix {
    int dimension;
    double *lowerTriangularValues;
};
typedef struct lowerTriangularMatrix lowerTriangularMatrix;

// Ввод параметров нижнетреугольной матрицы из файла.
void In(lowerTriangularMatrix &lowerTriangularMatrixInstance, ifstream &ifstreamInstance);

// Случайный ввод параметров нижнетреугольной матрицы.
void InRnd(lowerTriangularMatrix &lowerTriangularMatrixInstance);

// Вывод параметров нижнетреугольной матрицы в форматируемый поток.
void Out(lowerTriangularMatrix &lowerTriangularMatrixInstance, ofstream &ofstreamInstance);

// Вычисление среднего компонентов нижнетреугольной матрицы.
double Mean(lowerTriangularMatrix &lowerTriangularMatrixInstance);