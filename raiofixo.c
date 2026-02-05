#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "raiofixo.h"
#include "componentesangulo.h"

/** desc: aponta para centro do circulo & aponta para alocado. Retorna matriz de tamanho NUMERO_RAIOS */
RaioFixo* raiosDasHoras_policonstrutor( CirculoDasHoras* circulo )
{
  RaioFixo* raios = malloc( sizeof( RaioFixo ) * NUMERO_RAIOS );

  for ( int i = 0; i < NUMERO_RAIOS; i++ )
  {
    (raios+i)->centro = circulo->posicao;
    (raios+i)->borda = obterComponentesXYBorda_subconstrutor( circulo->posicao, circulo->raio, (int)(CIRCULO_GRAUS*(i/NUMERO_RAIOS)) );
  }

  return raios;
}

/** desc: limpa e libera memória das bordas (componentes) & limpa toda estrutura raiosFixos desalocando-a. */
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

/* desc: subconstrutor de "raiosDasHoras_policonstrutor" para calculo das componentes.
 * PRIVADO */
Vector2* obterComponentesXYBorda_subconstrutor( Vector2* centro, float raio, float anguloGraus )
{
  Vector2* posicaoBorda = malloc( sizeof(Vector2) );

  posicaoBorda->x = centro->x + obterComponenteX( raio, anguloGraus );
  posicaoBorda->y = centro->y + obterComponenteY( raio, anguloGraus );

  return posicaoBorda;
}


