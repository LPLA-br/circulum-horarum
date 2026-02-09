#include <math.h> //-lm
#include "degrad.h"

#include "constantes.h"

float radianoParaGrau( float radiano )
{
  return radiano * (180/M_PI);
}

float grauParaRadiano( float grau )
{
  return grau * (M_PI/180);
}

/** Desc: normaliza angulos selvagens que ultrapassam um círculo trigonométrico
 * em transbordamento ou sub transbordamento para 0-360.*/
float normalizarPorModuloEmGraus( float anguloSelvagem )
{
  return fmodf( ( fmodf( anguloSelvagem, LOCAL_MAX) + LOCAL_MAX ), LOCAL_MAX);
}

