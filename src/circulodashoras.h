#ifndef CIRCULO_DAS_HORAS_INCLUDED
#define CIRCULO_DAS_HORAS_INCLUDED

#include <raylib.h>

#include "tela.h"

typedef struct
{
  float raio;
  Vector2* posicao;
} CirculoDasHoras;

CirculoDasHoras* CirculoDasHoras_construtor( Tela* tela );
void CirculoDasHoras_destrutor( CirculoDasHoras* circulo );

void renderizarCirculoDasHoras( void(*renderizador)(Vector2,float,Color), CirculoDasHoras* cdh );

#endif
