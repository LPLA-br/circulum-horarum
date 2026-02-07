#ifndef PONTEIROAGORA_H_INCLUDED
#define PONTEIROAGORA_H_INCLUDED

#include <stdint.h>

#include <raylib.h>
#include "circulodashoras.h"

//#define DIA_EM_SEGUNDOS 86400
//#define DIA_EM_MINUTOS  720

#define HORAS_NO_DIA 23
#define MINUTOS_NA_HORA 59

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
