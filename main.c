//****************
//CIRCVLVM HORARVM
//****************
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include <raylib.h>
#include "circulodashoras.h"
#include "tela.h"
#include "raiofixo.h"
#include "ponteiroagora.h"

int main(void)
{
  Tela* tela = Tela_construtor( 1600, 700, "CIRCVLVM HORARVM" );
  CirculoDasHoras* cdh = CirculoDasHoras_construtor( tela );
  RaioFixo* raiosHoras = RaiosDasHoras_policonstrutor( cdh );
  PonteiroAgora* pa = PonteiroAgora_construtor( cdh );
  definirGMT( pa, -3 );

  InitWindow( tela->largura, tela->altura, tela->titulo );
  SetTargetFPS( 30 );

  while (!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(BLACK);
      DrawText( "CIRCVLVM HORARVM", 10, 10, 20, WHITE );

      renderizarCirculoDasHoras( DrawCircleV, cdh );
      renderizarRaiosFixos( DrawLineV, raiosHoras );
      renderizarPonteiroDoAgora( DrawLineV, pa, cdh );

    EndDrawing();
  }

  //desalocação em sequência reversa.
  PonteiroAgora_destrutor( pa );
  RaiosDasHoras_polidestrutor( raiosHoras );
  CirculoDasHoras_destrutor( cdh );
  Tela_destrutor( tela );
  CloseWindow();
  exit(0);
}

