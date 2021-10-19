//------------------------------------------------------------------------------
// normalMatrix.h - содержит описание нормальной матрицы и её интерфейса.
//------------------------------------------------------------------------------

# include "randomHelper.h"
#include <fstream>
using namespace std;

// Нормальная матрица.
struct normalMatrix {
    int dimension;
    double **matrix;
};
typedef struct normalMatrix normalMatrix;

// Ввод параметров нормальной матрицы из файла.
void In(normalMatrix &normalMatrixInstance, ifstream &ifstreamInstance);

// Случайный ввод параметров нормальной матрицы.
void InRnd(normalMatrix &normalMatrixInstance);

// Вывод параметров нормальной матрицы в форматируемый поток.
void Out(normalMatrix &normalMatrixInstance, ofstream &ofstreamInstance);

// Вычисление среднего компонентов нормальной матрицы.
double Mean(normalMatrix &normalMatrixInstance);
