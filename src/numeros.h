#ifndef NUMEROS_H_INCLUDED
#define NUMEROS_H_INCLUDED

#include <raylib.h>
#include "circulodashoras.h"

void renderizarNumeros(
        void(*escritorTextos)(const char*,int,int,int,Color),
        CirculoDasHoras* cdh
      );

#endif // NUMEROS_H_INCLUDED
