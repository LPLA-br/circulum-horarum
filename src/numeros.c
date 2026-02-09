#include <stdint.h>
#include <stdio.h>

#include <raylib.h>

#include "constantes.h"
#include "circulodashoras.h"
#include "componentesangulo.h"
#include "degrad.h"
#include "numeros.h"

/** Desc: Recebe callback (texto,px,py,fontSize,Cor) */
void renderizarNumeros(
      void(*escritorTextos)(const char*,int,int,int,Color),
      CirculoDasHoras* cdh
    )
{
  auto float subRaio = (cdh->raio * (9.0/10.0));
  auto char numeroEscrito[4];

  for ( auto uint8_t i = 0; i < HORAS_NO_DIA; i++ )
  {
    float angulo = normalizarPorModuloEmGraus( (float)((float)CIRCULO_GRAUS*((float)i/NUMERO_RAIOS)) + FATIA/2 - CORRECAO_ANGULAR );

    sprintf( numeroEscrito, "%i", i );

    escritorTextos(
        numeroEscrito,
        obterComponenteX( subRaio, angulo ) + cdh->posicao->x,
        obterComponenteY( subRaio, angulo ) + cdh->posicao->y,
        20, RED );
  }
}


