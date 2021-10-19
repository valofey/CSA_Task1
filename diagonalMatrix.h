//------------------------------------------------------------------------------
// diagonalMatrix.h - содержит описание диагональной матрицы и её интерфейса.
//------------------------------------------------------------------------------

# include "randomHelper.h"
#include <fstream>
using namespace std;

//Диагональная матрица.
struct diagonalMatrix {
    int dimension;
    double *diagonalValues;
};
typedef struct diagonalMatrix diagonalMatrix;

// Ввод параметров диагональной матрицы из файла.
void In(diagonalMatrix &diagonalMatrixInstance, ifstream &ifstreamInstance);

// Случайный ввод параметров диагональной матрицы.
void InRnd(diagonalMatrix &diagonalMatrixInstance);

// Вывод параметров диагональной матрицы в форматируемый поток.
void Out(diagonalMatrix &diagonalMatrixInstance, ofstream &ofstreamInstance);

// Вычисление среднего компонентов диагональной матрицы.
double Mean(diagonalMatrix &diagonalMatrixInstance);