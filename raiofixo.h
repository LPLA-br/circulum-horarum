#ifndef RAIOFIXO_H_INCLUDED
#define RAIOFIXO_H_INCLUDED

#include <raylib.h>
#include "circulodashoras.h"

//@dependente: circulodashoras

typedef struct
{
  Vector2* centro;
  Vector2* borda;
} RaioFixo;

RaioFixo* raiosDasHoras_policonstrutor( CirculoDasHoras* circulo );
void raiosDasHoras_polidestrutor( RaioFixo* raiosFixos );

//recebe angulo desejado e retorna componentes x,y para borda do Vector2
Vector2* obterComponentesParaAngulo( float anguloGraus, int raio );

#endif // RAIOFIXO_H_INCLUDED
