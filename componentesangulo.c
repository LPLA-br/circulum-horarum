#include <math.h> //-lm

#include "componentesangulo.h"
#include "degrad.h"

/** retorna comprimento da componente X */
float obterComponenteX( const float hipotenusa, float anguloGraus )
{
  float anguloRadiano = grauParaRadiano( anguloGraus );
  return hipotenusa * cosf(anguloRadiano );
}

/** retorna comprimento da componente Y */
float obterComponenteY( const float hipotenusa, float anguloGraus )
{
  float anguloRadiano = grauParaRadiano( anguloGraus );
  return hipotenusa * sinf( anguloRadiano );
}

