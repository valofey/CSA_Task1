//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера.
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера.
void Init(container &containerInstance){
    containerInstance.length = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти).
void Clear(container &containerInstance) {
    containerInstance.length = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока.
void In(container &containerInstance, ifstream &ifst) {
    while(!ifst.eof()) {
        if(In(containerInstance.cont[containerInstance.length], ifst)) {
            containerInstance.length++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера.
void InRnd(container &containerInstance, int size) {
    while(containerInstance.length < size) {
        if(InRnd(containerInstance.cont[containerInstance.length])) {
            containerInstance.length++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток.
void Out(container &containerInstance, ofstream &ofst) {
    ofst << "Container contains " << containerInstance.length << " elements." << endl;
    for(int i = 0; i < containerInstance.length; i++) {
        ofst << i << ": ";
        Out(containerInstance.cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
// Вычисление суммы периметров всех фигур в контейнере.
double MeanSum(container &containerInstance) {
    double sum = 0.0;
    for(int i = 0; i < containerInstance.length; i++) {
        sum += Mean(containerInstance.cont[i]);
    }
    return sum;
}
