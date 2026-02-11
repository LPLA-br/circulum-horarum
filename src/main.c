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
  CirculoDasHorasBidividido* circuloHorasBidividido = CirculoDasHorasBidividido_construtor( tela, 100 );
  RaioFixo* raiosHoras = RaiosDasHoras_policonstrutor( circuloHorasBidividido->circuloHoras );
  PonteiroAgoraEspesso* ponteiroAgoraEspesso = PonteiroAgoraEspesso_construtor( circuloHorasBidividido->circuloHoras );
  definirGMT( ponteiroAgoraEspesso->ponteiroAgora, -3 );

  InitWindow( tela->largura, tela->altura, tela->titulo );
  SetTargetFPS( 30 );

  while (!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(BLACK);
      DrawText( "CIRCVLVM HORARVM", 10, 10, 20, WHITE );

      renderizarCirculoDasHorasBidividido( DrawCircleSector, circuloHorasBidividido );
      renderizarRaiosFixos( DrawLineV, raiosHoras );
      renderizarPonteiroDoAgoraComEspessura( DrawLineEx, ponteiroAgoraEspesso, circuloHorasBidividido->circuloHoras  );
      renderizarNumeros( DrawText, circuloHorasBidividido->circuloHoras );

    EndDrawing();
  }

  //desalocação em sequência reversa.
  PonteiroAgoraEspesso_destrutor( ponteiroAgoraEspesso );
  RaiosDasHoras_polidestrutor( raiosHoras );
  CirculoDasHorasBidividido_destrutor( circuloHorasBidividido );
  Tela_destrutor( tela );
  CloseWindow();
  exit(0);
}

