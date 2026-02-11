#ifndef CIRCULO_DAS_HORAS_INCLUDED
#define CIRCULO_DAS_HORAS_INCLUDED

#include <raylib.h>

#include "tela.h"

typedef struct
{
  float raio;
  Vector2* posicao;
} CirculoDasHoras;

CirculoDasHoras* CirculoDasHoras_construtor( Tela* tela );
void CirculoDasHoras_destrutor( CirculoDasHoras* circulo );

// @obsoleto
void renderizarCirculoDasHoras( void(*renderizador)(Vector2,float,Color), CirculoDasHoras* cdh );

// EXTENSÃO - NOVA FORMA DE RENDERIZAR O CIRCULO DAS HORAS. -------------------------------------------

#define QUANTIDADE_SEMI_CIRCULOS_CIRCULO_DAS_HORAS 2

typedef struct
{
  float anguloInicial;
  float anguloFinal;
  Color cor;
} SemiCirculo;

// float startAngle, float endAngle, int segments, Color color
typedef struct
{
  CirculoDasHoras* cdh;
  SemiCirculo* SemiCirculos;
  int segmentos;
} CirculoDasHorasBidividido;

CirculoDasHorasBidividido* CirculoDasHorasBidividido_construtor( Tela* tela, int segmentos );
void CirculoDasHorasBidividido_destrutor( CirculoDasHorasBidividido* cdhb );

void renderizarCirculoDasHorasBidividido( void(*renderizador)(Vector2,float,float,float,int,Color), CirculoDasHorasBidividido* cdhb );

#endif
