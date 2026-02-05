#include <math.h> //-lm
#include "degrad.h"

float radianoParaGrau( float radiano )
{
  return radiano * (180/M_PI);
}

float grauParaRadiano( float grau )
{
  return grau * (M_PI/180);
}

