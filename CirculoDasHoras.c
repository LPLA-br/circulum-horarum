#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CirculoDasHoras.h"

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
    memset( circulo->posicao, 0x00, sizeof(Vector2) );
    free(circulo->posicao );

    memset( circulo, 0x00, sizeof(CirculoDasHoras) );
    free( circulo );
  }
  perror("CirculoDasHoras é NULL");
  exit(1);
}

//------

Tela* Tela_construtor( int altura, int largura, const char* titulo )
{
  Tela* t = malloc( sizeof(Tela) );

  t->altura = altura;
  t->largura = largura;
  t->titulo = titulo;

  return t;
}

void Tela_destrutor( Tela* t )
{
  if ( t != NULL )
  {
    free(t);
    return;
  }
  perror("Tela é NULL");
  exit(1);
}

//------

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

// TODO: função que recebe callback DrawLineV() ...

