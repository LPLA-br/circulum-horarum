//****************
//CIRCVLVM HORARVM
//****************
#include <stdlib.h>
#include <stdint.h>

#include <raylib.h>

#include "circulodashoras.h"
#include "tela.h"
#include "raiofixo.h"
#include "ponteiroagora.h"
#include "numeros.h"

int main(void)
{
  Tela* tela = Tela_construtor( 1600, 700, "CIRCVLVM HORARVM" );
  CirculoDasHorasBidividido* cdhb = CirculoDasHorasBidividido_construtor( tela, 100 );
  RaioFixo* raiosHoras = RaiosDasHoras_policonstrutor( cdhb->cdh );
  PonteiroAgora* pa = PonteiroAgora_construtor( cdhb->cdh );
  definirGMT( pa, -3 );

  InitWindow( tela->largura, tela->altura, tela->titulo );
  SetTargetFPS( 30 );

  while (!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(BLACK);
      DrawText( "CIRCVLVM HORARVM", 10, 10, 20, WHITE );

      renderizarCirculoDasHorasBidividido( DrawCircleSector, cdhb );
      renderizarRaiosFixos( DrawLineV, raiosHoras );
      renderizarPonteiroDoAgora( DrawLineV, pa, cdhb->cdh );
      renderizarNumeros( DrawText, cdhb->cdh );

    EndDrawing();
  }

  //desalocação em sequência reversa.
  PonteiroAgora_destrutor( pa );
  RaiosDasHoras_polidestrutor( raiosHoras );
  CirculoDasHorasBidividido_destrutor( cdhb );
  Tela_destrutor( tela );
  CloseWindow();
  exit(0);
}

