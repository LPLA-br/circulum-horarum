#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "ponteiroagora.h"
#include "componentesangulo.h"

PonteiroAgora* PonteiroAgora_construtor( CirculoDasHoras* circulo )
{
  PonteiroAgora* ponteiroAgora = malloc( sizeof( PonteiroAgora ) );

  ponteiroAgora->gmt = 0;
  carregarHoraMinutoCorrente( ponteiroAgora );

  ponteiroAgora->anguloGraus = 90;

  ponteiroAgora->centro = circulo->posicao;

  ponteiroAgora->bordaMovel = malloc( sizeof( Vector2 ) );
  ponteiroAgora->bordaMovel->x = 0;
  ponteiroAgora->bordaMovel->y = 0;

  return ponteiroAgora;
}

void PonteiroAgora_destrutor( PonteiroAgora* ponteiroAgora )
{
  free( ponteiroAgora->bordaMovel );
  free( ponteiroAgora );
  return;
}

/** Desc: função executiva que rotaciona o ponteiroAgora por segundo enquanto
 * seu elemento bordaMovel não for nulo.*/
void rotacionarHorariamentePonteiroAgora( PonteiroAgora* ponteiroAgora, const float raio )
{
  ponteiroAgora->bordaMovel->x = ponteiroAgora->centro->x + obterComponenteX( raio, ponteiroAgora->anguloGraus );
  ponteiroAgora->bordaMovel->y = ponteiroAgora->centro->y + obterComponenteY( raio, ponteiroAgora->anguloGraus );

  return;
}

/** Desc: função publica para correção de GMT */
void definirGMT( PonteiroAgora* ponteiroAgora , int8_t GMTproposto )
{
  if ( GMTproposto >= -11 || GMTproposto <= 12 )
  {
    ponteiroAgora->gmt = GMTproposto;
    return;
  }
  perror( "GMT inválido. padrão zero mantido." );
}

/** Desc: função privada responsável por carregar a hora com ajuste GMT
 * função iterativa por segundo.*/
void carregarHoraMinutoCorrente( PonteiroAgora* ponteiroAgora )
{
  time_t t = time(NULL);
  struct tm* tempo = gmtime( &t );

  ponteiroAgora->hora = tempo->tm_hour + ponteiroAgora->gmt;
  ponteiroAgora->minuto = tempo->tm_min;

  free(tempo);
  return;
}

/** Desc: computa angulo horário sem ajuste dos minutos. */
void computarAnguloEmFuncaoDaHora( PonteiroAgora* ponteiroAgora )
{
  ponteiroAgora->anguloGraus = (CIRCULO_GRAUS * ( (float)ponteiroAgora->hora / HORAS_NO_DIA ));
}

/** Desc: subfunção de "computarAnguloEmFuncaoDaHora()"  */
void computarAcrescimoDosMinutosParaAnguloDaHoraComputadada( PonteiroAgora* ponteiroAgora )
{
  if ( ponteiroAgora->minuto == MINUTOS_NA_HORA ) return; //responsabilidade superior

  const float tamanhoDumaFatia =  ((float)CIRCULO_GRAUS / HORAS_NO_DIA) ;
  ponteiroAgora->anguloGraus = ( tamanhoDumaFatia / MINUTOS_NA_HORA ) * ponteiroAgora->minuto;
}

