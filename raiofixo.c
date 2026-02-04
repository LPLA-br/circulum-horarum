#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "raiofixo.h"

#define NUMERO_RAIOS 23

RaioFixo* raiosDasHoras_policonstrutor( CirculoDasHoras* circulo )
{
  RaioFixo* raios = malloc( sizeof( RaioFixo ) * NUMERO_RAIOS );

  for ( int i = 0; i < NUMERO_RAIOS; i++ )
  {
    (raios+i)->centro = circulo->posicao;

    (raios+i)->borda = malloc( sizeof(Vector2) );
    (raios+i)->borda->x = circulo->posicao->x;
    (raios+i)->borda->y = (circulo->posicao->y - circulo->raio);
  }

  return raios;
}

void raiosDasHoras_polidestrutor( RaioFixo* raiosFixos )
{
  if ( raiosFixos != NULL )
  {
    //dependências
    for ( int i = 0; i < NUMERO_RAIOS; i++ )
    {
      memset( (raiosFixos+i)->borda, 0x00, sizeof(Vector2) );
      free( (raiosFixos+i)->borda );
    }

    for ( int i = 0; i < NUMERO_RAIOS; i++ )
    {
      memset( (raiosFixos+i), 0x00, sizeof( RaioFixo ) );
      free( (raiosFixos+i) );
    }
    return;
  }
  perror("raiosFixos é NULL");
  exit(1);
}

Vector2* obterComponentesParaAngulo( float anguloGraus, int raio )
{
  //raio vezes coseno de theta em graus
  return NULL;
}

// TODO: função que recebe callback DrawLineV() ...

