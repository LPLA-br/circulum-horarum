#ifndef CIRCULO_DAS_HORAS
#define CIRCULO_DAS_HORAS

#include <raylib.h>

//TODO: segregar estruturas para seus respectivos headers.


/* DEPENDÊNCIAS
 *
 * Tela
 * |_CirculoDasHoras
 *   |_RaioFixo
 * */

typedef struct
{
  int largura;
  int altura;
  const char* titulo;
} Tela;

typedef struct
{
  Vector2* centro;
  Vector2* borda;
} RaioFixo;

typedef struct
{
  float raio;
  Vector2* posicao;

  RaioFixo* (*DesenharRaiosDasHoras)();
  RaioFixo* (*DesenharPonteiroHoraCorrente)();
} CirculoDasHoras;

//---------
CirculoDasHoras* CirculoDasHoras_construtor( Tela* tela );
void CirculoDasHoras_destrutor( CirculoDasHoras* circulo );
//---------
Tela* Tela_construtor( int altura, int largura, const char* titulo );
void Tela_destrutor( Tela* t );
//---------
RaioFixo* raiosDasHoras_policonstrutor( CirculoDasHoras* circulo );
void raiosDasHoras_polidestrutor( RaioFixo* raiosFixos );
//---------


//recebe angulo desejado e retorna componentes x,y para borda do Vector2
Vector2* obterComponentesParaAngulo( float angulo, int raio );

#endif
