#ifndef CIRCULO_DAS_HORAS
#define CIRCULO_DAS_HORAS

#include <raylib.h>

#include "tela.h"

//@dependente: tela.h

typedef struct
{
  float raio;
  Vector2* posicao;

  /* DEPENDÊNCIA CIRCULAR -> separar responsabilidades!
   * RaioFixo* (*DesenharRaiosDasHoras)();
  RaioFixo* (*DesenharPonteiroHoraCorrente)();*/
} CirculoDasHoras;

CirculoDasHoras* CirculoDasHoras_construtor( Tela* tela );
void CirculoDasHoras_destrutor( CirculoDasHoras* circulo );

void renderizarCirculoDasHoras( void(*renderizador)(Vector2,float,Color), CirculoDasHoras* cdh );

#endif
