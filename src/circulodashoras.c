#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circulodashoras.h"

CirculoDasHoras* CirculoDasHoras_construtor( Tela* tela )
{
  CirculoDasHoras* cdh = malloc( sizeof( CirculoDasHoras ) );

  cdh->posicao = malloc( sizeof( Vector2 ) );

  cdh->raio =       (float)tela->largura/2-(10.0/2);
  cdh->posicao->x = (float)tela->largura/2;
  cdh->posicao->y = (float)tela->altura/2;

  return cdh;
}

void CirculoDasHoras_destrutor( CirculoDasHoras* circulo )
{
  if ( circulo != NULL )
  {
    //dependências
    free(circulo->posicao );
    free( circulo );
    return;
  }
  perror("CirculoDasHoras é NULL");
  exit(1);
}

void renderizarCirculoDasHoras( void(*renderizador)(Vector2,float,Color), CirculoDasHoras* cdh )
{
  renderizador( *cdh->posicao, cdh->raio, WHITE );
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

  CirculoDasHorasBidividido* cdhb = malloc( sizeof( CirculoDasHorasBidividido ) );

  cdhb->cdh = CirculoDasHoras_construtor( tela );
  cdhb->SemiCirculos = malloc( sizeof( SemiCirculo ) * QUANTIDADE_SEMI_CIRCULOS_CIRCULO_DAS_HORAS );

  cdhb->SemiCirculos[0].anguloInicial = 0.0;
  cdhb->SemiCirculos[0].anguloFinal = 180.0;
  cdhb->SemiCirculos[0].cor = WHITE;

  cdhb->SemiCirculos[1].anguloInicial = 180.0;
  cdhb->SemiCirculos[1].anguloFinal = 360.0;
  cdhb->SemiCirculos[1].cor = DARKGRAY;

  cdhb->segmentos = segmentos;

  return cdhb;
}

void CirculoDasHorasBidividido_destrutor( CirculoDasHorasBidividido* cdhb )
{
  CirculoDasHoras_destrutor( cdhb->cdh );
  free(cdhb->SemiCirculos);
  free( cdhb );
}

void renderizarCirculoDasHorasBidividido( void(*renderizador)(Vector2,float,float,float,int,Color), CirculoDasHorasBidividido* cdhb )
{
  for ( int i = 0; i < QUANTIDADE_SEMI_CIRCULOS_CIRCULO_DAS_HORAS; i++ )
  {
    renderizador( *(cdhb->cdh->posicao), cdhb->cdh->raio, cdhb->SemiCirculos[i].anguloInicial, cdhb->SemiCirculos[i].anguloFinal, cdhb->segmentos, cdhb->SemiCirculos[i].cor );
  }
  return;
}

