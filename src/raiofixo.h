#ifndef RAIOFIXO_H_INCLUDED
#define RAIOFIXO_H_INCLUDED

#include <raylib.h>
#include "circulodashoras.h"

//@dependente: circulodashoras

#define NUMERO_RAIOS 24 // i<24 logo 0..23

typedef struct
{
  Vector2* centro;
  Vector2* borda;
} RaioFixo;

RaioFixo* RaiosDasHoras_policonstrutor( CirculoDasHoras* circulo );
void RaiosDasHoras_polidestrutor( RaioFixo* raiosFixos );

//PRIVADO
Vector2* obterComponentesXYBorda_subconstrutor( Vector2* centro, float raio, float anguloGraus );

void renderizarRaiosFixos( void(*renderizador)(Vector2,Vector2,Color), RaioFixo* raios );

#endif // RAIOFIXO_H_INCLUDED
