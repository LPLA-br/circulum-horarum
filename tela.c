#include "tela.h"
#include <stdio.h>
#include <stdlib.h>

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


