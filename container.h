//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер.
//------------------------------------------------------------------------------

#include "matrix.h"
#include <fstream>
using namespace std;
//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива.
struct container {
    enum {maxLength = 10000}; // Максимальная длина.
    int length; // текущая длина
    matrix cont[maxLength];
};

// Инициализация контейнера.
void Init(container &containerInstance);

// Очистка контейнера от элементов (освобождение памяти).
void Clear(container &containerInstance);

// Ввод содержимого контейнера из указанного потока.
void In(container &containerInstance, ifstream &ifstreamInstance);

// Случайный ввод содержимого контейнера.
void InRnd(container &containerInstance, int size);

// Вывод содержимого контейнера в указанный поток.
void Out(container &containerInstance, ofstream &ofstreamInstance);

// Вычисление суммы периметров всех фигур в контейнере.
double MeanSum(container &containerInstance);
