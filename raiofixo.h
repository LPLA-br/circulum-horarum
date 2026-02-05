#ifndef RAIOFIXO_H_INCLUDED
#define RAIOFIXO_H_INCLUDED

#include <raylib.h>
#include "circulodashoras.h"

//@dependente: circulodashoras

#define NUMERO_RAIOS 23

typedef struct
{
  Vector2* centro;
  Vector2* borda;
} RaioFixo;

RaioFixo* raiosDasHoras_policonstrutor( CirculoDasHoras* circulo );
void raiosDasHoras_polidestrutor( RaioFixo* raiosFixos );

//PRIVADO
Vector2* obterComponentesXYBorda_subconstrutor( Vector2* centro, float raio, float anguloGraus );

#endif // RAIOFIXO_H_INCLUDED
