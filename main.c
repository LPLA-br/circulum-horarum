//****************
//CIRCVLVM HORARVM
//****************
#include <stdlib.h>
#include <stdint.h>

#include <raylib.h>
#include "circulodashoras.h"
#include "tela.h"
#include "raiofixo.h"

int main(void)
{
  Tela* tela = Tela_construtor( 1600, 700, "CIRCVLVM HORARVM" );
  CirculoDasHoras* cdh = CirculoDasHoras_construtor( tela );
  RaioFixo* raiosHoras = raiosDasHoras_policonstrutor( cdh );

  InitWindow( tela->largura, tela->altura, tela->titulo );
  SetTargetFPS( 30 );

  while (!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(BLACK);
      DrawText( "CIRCVLVM HORARVM", 10, 10, 20, WHITE );
      DrawCircleV( *(Vector2*)cdh->posicao, cdh->raio, WHITE );
      //DrawLineV( inicio, fim, BLACK );
    EndDrawing();
  }

  //desalocação em sequência reversa.
  CirculoDasHoras_destrutor( cdh );
  Tela_destrutor( tela );
  CloseWindow();
  exit(0);
}

