#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circulodashoras.h"

CirculoDasHoras* CirculoDasHoras_construtor( Tela* tela )
{
  CirculoDasHoras* cdh = malloc( sizeof( CirculoDasHoras ) );

  cdh->posicao = malloc( sizeof( Vector2 ) );

  cdh->raio = (tela->largura/2-(10/2));
  cdh->posicao->x = tela->largura/2;
  cdh->posicao->y = tela->altura/2;

  return cdh;
}

void CirculoDasHoras_destrutor( CirculoDasHoras* circulo )
{
  if ( circulo != NULL )
  {
    //dependências
    free(circulo->posicao );
    free( circulo );
  }
  perror("CirculoDasHoras é NULL");
  exit(1);
}


