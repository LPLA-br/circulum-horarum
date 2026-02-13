#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "constantes.h"
#include "ponteiroagora.h"
#include "componentesangulo.h"
#include "degrad.h"

PonteiroAgora* PonteiroAgora_construtor( CirculoDasHoras* circuloHoras )
{
  PonteiroAgora* ponteiroAgora = malloc( sizeof( PonteiroAgora ) );

  ponteiroAgora->gmt = 0;

  carregarHoraMinutoCorrente( ponteiroAgora );

  ponteiroAgora->anguloGraus = CORRECAO_ANGULAR;

  ponteiroAgora->centro = circuloHoras->posicao;

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
void rotacionarHorariamentePonteiroAgora( PonteiroAgora* ponteiroAgora, CirculoDasHoras* circuloHoras )
{
  ponteiroAgora->bordaMovel->x = ponteiroAgora->centro->x + obterComponenteX( circuloHoras->raio, ponteiroAgora->anguloGraus );
  ponteiroAgora->bordaMovel->y = ponteiroAgora->centro->y + obterComponenteY( circuloHoras->raio, ponteiroAgora->anguloGraus );

  return;
}

/** Desc: função pública para correção de GMT */
void definirGMT( PonteiroAgora* ponteiroAgora , int8_t GMTproposto )
{
  if ( GMTproposto >= -11 && GMTproposto <= 12 )
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

  return;
}

/** Desc: computa angulo horário sem ajuste dos minutos. */
void computarAnguloEmFuncaoDaHora( PonteiroAgora* ponteiroAgora )
{
  ponteiroAgora->anguloGraus = normalizarPorModuloEmGraus( ( ((float)CIRCULO_GRAUS/HORAS_NO_DIA)*ponteiroAgora->hora ) - CORRECAO_ANGULAR );
}

/** Desc: subfunção (não dependente -> complementar) de "computarAnguloEmFuncaoDaHora()"  */
void computarAcrescimoDosMinutosParaAnguloDaHoraComputadada( PonteiroAgora* ponteiroAgora )
{
  if ( ponteiroAgora->minuto == MINUTOS_NA_HORA ) return; //responsabilidade superior

  ponteiroAgora->anguloGraus += ( FATIA / MINUTOS_NA_HORA ) * ponteiroAgora->minuto;
}

void renderizarPonteiroDoAgora( void(*renderizador)(Vector2,Vector2,Color), PonteiroAgora* ponteiroAgora, CirculoDasHoras* circuloHoras )
{
  carregarHoraMinutoCorrente( ponteiroAgora );
  rotacionarHorariamentePonteiroAgora( ponteiroAgora, circuloHoras );
  computarAnguloEmFuncaoDaHora( ponteiroAgora );
  computarAcrescimoDosMinutosParaAnguloDaHoraComputadada( ponteiroAgora );
  renderizador( *ponteiroAgora->centro, *ponteiroAgora->bordaMovel, RED );
  return;
}

// EXTENSÃO -- Deriva ponteiro do agora espesso.

PonteiroAgoraEspesso* PonteiroAgoraEspesso_construtor( CirculoDasHoras* circuloHoras )
{
  PonteiroAgoraEspesso* ponteiroAgoraEspesso = malloc( sizeof( PonteiroAgoraEspesso ) );

  ponteiroAgoraEspesso->ponteiroAgora = PonteiroAgora_construtor( circuloHoras );
  ponteiroAgoraEspesso->espessura = ESPESSURA_PONTEIRO_ESPESSO;
  
  return ponteiroAgoraEspesso;
}

void PonteiroAgoraEspesso_destrutor( PonteiroAgoraEspesso* ponteiroAgoraEspesso )
{
  PonteiroAgora_destrutor( ponteiroAgoraEspesso->ponteiroAgora );
  free(ponteiroAgoraEspesso);
}

//Vector2 startPos, Vector2 endPos, float thick, Color color
void renderizarPonteiroDoAgoraComEspessura(
      void(*renderizador)(Vector2,Vector2,float,Color),
      PonteiroAgoraEspesso* ponteiroAgoraEspesso,
      CirculoDasHoras* circuloHoras
    )
{
  carregarHoraMinutoCorrente( ponteiroAgoraEspesso->ponteiroAgora );
  rotacionarHorariamentePonteiroAgora( ponteiroAgoraEspesso->ponteiroAgora, circuloHoras );
  computarAnguloEmFuncaoDaHora( ponteiroAgoraEspesso->ponteiroAgora );
  computarAcrescimoDosMinutosParaAnguloDaHoraComputadada( ponteiroAgoraEspesso->ponteiroAgora );
  renderizador( *ponteiroAgoraEspesso->ponteiroAgora->centro, *ponteiroAgoraEspesso->ponteiroAgora->bordaMovel, ponteiroAgoraEspesso->espessura, RED );
  return;
}

