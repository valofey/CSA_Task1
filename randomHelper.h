#ifndef randomHelper
#define randomHelper

#include <cstdlib>

//------------------------------------------------------------------------------
// randomHelper.h - содержит генератор случайных чисел в диапазоне от 1 до 10.
//------------------------------------------------------------------------------

inline int Random() {
    return rand() % 9 + 1;
}

#endif //randomHelper.
