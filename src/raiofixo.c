#include <stdlib.h>
#include <stdio.h>

#include <raylib.h>

#include "constantes.h"
#include "raiofixo.h"
#include "componentesangulo.h"

/** desc: aponta para centro do circulo & aponta para alocado. Retorna matriz de tamanho NUMERO_RAIOS */
RaioFixo* RaiosDasHoras_policonstrutor( CirculoDasHoras* circulo )
{
  RaioFixo* raios = malloc( sizeof( RaioFixo ) * NUMERO_RAIOS );

  for ( int i = 0; i < NUMERO_RAIOS; i++ )
  {
    (raios+i)->centro = circulo->posicao;
    (raios+i)->borda = obterComponentesXYBorda_subconstrutor( circulo->posicao, circulo->raio, (CIRCULO_GRAUS*((float)i/NUMERO_RAIOS)) );
  }

  return raios;
}

/** desc: limpa e libera memória das bordas (componentes) & limpa toda estrutura raiosFixos desalocando-a. */
void RaiosDasHoras_polidestrutor( RaioFixo* raiosFixos )
{
  if ( raiosFixos != NULL )
  {
    //dependências
    for ( int i = 0; i < NUMERO_RAIOS; i++ )
    {
      free( (raiosFixos+i)->borda );
    }

    free( raiosFixos );
    return;
  }
  perror("raiosFixos é NULL");
  exit(1);
}

/* desc: subconstrutor de "RaiosDasHoras_policonstrutor" para calculo das componentes.
 * PRIVADO */
Vector2* obterComponentesXYBorda_subconstrutor( Vector2* centro, float raio, float anguloGraus )
{
  Vector2* posicaoBorda = malloc( sizeof(Vector2) );

  posicaoBorda->x = centro->x + obterComponenteX( raio, anguloGraus );
  posicaoBorda->y = centro->y + obterComponenteY( raio, anguloGraus );

  return posicaoBorda;
}

void renderizarRaiosFixos( void(*renderizador)(Vector2,Vector2,Color), RaioFixo* raios )
{
  for ( int i = 0; i < NUMERO_RAIOS; i++ )
  {
    renderizador( *(raios+i)->centro, *(raios+i)->borda, BLACK );
  }

  return;
}

