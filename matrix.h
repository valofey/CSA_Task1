//------------------------------------------------------------------------------
// matrix.h - содержит описание обобщающей структуры (матрицы).
//------------------------------------------------------------------------------

#include "normalMatrix.h"
#include "diagonalMatrix.h"
#include "lowerTriangularMatrix.h"
#include <fstream>
using namespace std;
//------------------------------------------------------------------------------
// Структура, обобщающая все имеющиеся виды матриц.
struct matrix {
    // Значения ключей для каждой из матриц.
    enum key {normalMatrix, diagonalMatrix, lowerTriangularMatrix};
    key keyInstance; // Ключ.
    // Используемые альтернативы.
    union { // Используем простейшую реализацию.
        struct normalMatrix normalMatrixInstance;
        struct diagonalMatrix diagonalMatrixInstance;
        struct lowerTriangularMatrix lowerTriangularMatrixInstance;
    };
};

// Ввод обобщенной матрицы.
bool In(matrix& matrixInstance, ifstream &ifstreamInstance);

// Случайный ввод обобщенной матрицы.
bool InRnd(matrix &matrixInstance);

// Вывод обобщенной матрицы.
void Out(matrix &matrixInstance, ofstream &ofstreamInstance);

// Вычисление среднего арифметического элементов обобщенной матрицы.
double Mean(matrix &matrixInstance);