#ifndef PONTEIROAGORA_H_INCLUDED
#define PONTEIROAGORA_H_INCLUDED

#include <stdint.h>

#include <raylib.h>
#include "circulodashoras.h"

#include "constantes.h"

typedef struct
{
  int8_t gmt;
  int hora;
  int minuto;
  float anguloGraus;

  Vector2* centro;
  Vector2* bordaMovel;
} PonteiroAgora;

PonteiroAgora* PonteiroAgora_construtor( CirculoDasHoras* circulo );
void PonteiroAgora_destrutor( PonteiroAgora* ponteiroAgora );

void rotacionarHorariamentePonteiroAgora( PonteiroAgora* ponteiroAgora, CirculoDasHoras* cdh );
void definirGMT( PonteiroAgora* ponteiroAgora , int8_t GMTproposto );
void carregarHoraMinutoCorrente( PonteiroAgora* ponteiroAgora );

void computarAnguloEmFuncaoDaHora( PonteiroAgora* ponteiroAgora );
void computarAcrescimoDosMinutosParaAnguloDaHoraComputadada( PonteiroAgora* ponteiroAgora );

void renderizarPonteiroDoAgora( void(*renderizador)(Vector2,Vector2,Color), PonteiroAgora* ponteiroAgora, CirculoDasHoras* cdh );

#endif // PONTEIROAGORA_H_INCLUDED
