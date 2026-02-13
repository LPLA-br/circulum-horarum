#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circulodashoras.h"

CirculoDasHoras* CirculoDasHoras_construtor( Tela* tela )
{
  CirculoDasHoras* circuloHoras = malloc( sizeof( CirculoDasHoras ) );

  circuloHoras->posicao = malloc( sizeof( Vector2 ) );

  circuloHoras->raio =       (float)tela->largura/2-(10.0/2);
  circuloHoras->posicao->x = (float)tela->largura/2;
  circuloHoras->posicao->y = (float)tela->altura/2;

  return circuloHoras;
}

void CirculoDasHoras_destrutor( CirculoDasHoras* circuloHoras )
{
  if ( circuloHoras != NULL )
  {
    //dependências
    free(circuloHoras->posicao );
    free( circuloHoras );
    return;
  }
  perror("CirculoDasHoras é NULL");
  exit(1);
}

void renderizarCirculoDasHoras( void(*renderizador)(Vector2,float,Color), CirculoDasHoras* circuloHoras )
{
  renderizador( *circuloHoras->posicao, circuloHoras->raio, WHITE );
  return;
}

// EXTENSÃO - NOVA FORMA DE RENDERIZAR O CIRCULO DAS HORAS. -------------------------------------------

CirculoDasHorasBidividido* CirculoDasHorasBidividido_construtor( Tela* tela, int segmentos )
{

  if ( segmentos < 50 || segmentos > 100 )
  {
    perror( "Números de segmentos em semicirculo de CirculoDasHorasBidividido inválido. Adotando 75" );
    segmentos = 75;
  }

  CirculoDasHorasBidividido* circuloHorasBidividido = malloc( sizeof( CirculoDasHorasBidividido ) );

  circuloHorasBidividido->circuloHoras = CirculoDasHoras_construtor( tela );
  circuloHorasBidividido->SemiCirculos = malloc( sizeof( SemiCirculo ) * QUANTIDADE_SEMI_CIRCULOS_CIRCULO_DAS_HORAS );

  circuloHorasBidividido->SemiCirculos[0].anguloInicial = 0.0;
  circuloHorasBidividido->SemiCirculos[0].anguloFinal = 180.0;
  circuloHorasBidividido->SemiCirculos[0].cor = WHITE;

  circuloHorasBidividido->SemiCirculos[1].anguloInicial = 180.0;
  circuloHorasBidividido->SemiCirculos[1].anguloFinal = 360.0;
  circuloHorasBidividido->SemiCirculos[1].cor = DARKGRAY;

  circuloHorasBidividido->segmentos = segmentos;

  return circuloHorasBidividido;
}

void CirculoDasHorasBidividido_destrutor( CirculoDasHorasBidividido* circuloHorasBidividido )
{
  CirculoDasHoras_destrutor( circuloHorasBidividido->circuloHoras );
  free(circuloHorasBidividido->SemiCirculos);
  free( circuloHorasBidividido );
}

void renderizarCirculoDasHorasBidividido( void(*renderizador)(Vector2,float,float,float,int,Color), CirculoDasHorasBidividido* circuloHorasBidividido )
{
  for ( int i = 0; i < QUANTIDADE_SEMI_CIRCULOS_CIRCULO_DAS_HORAS; i++ )
  {
    renderizador(
          *(circuloHorasBidividido->circuloHoras->posicao),
          circuloHorasBidividido->circuloHoras->raio,
          circuloHorasBidividido->SemiCirculos[i].anguloInicial,
          circuloHorasBidividido->SemiCirculos[i].anguloFinal,
          circuloHorasBidividido->segmentos,
          circuloHorasBidividido->SemiCirculos[i].cor
        );
  }
  return;
}

