//****************
//CIRCVLVM HORARVM
//****************
#include <stdlib.h>
#include <stdint.h>

#include <raylib.h>
#include "CirculoDasHoras.h"

int main(void)
{
  Tela* tela = Tela_construtor( 1600, 700, "CIRCVLVM HORARVM" );

  InitWindow( tela->largura, tela->altura, tela->titulo );
  SetTargetFPS( 30 );

  //Objetos
  CirculoDasHoras* cdh = CirculoDasHoras_construtor( tela );

  Vector2 inicio = *(Vector2*)cdh->posicao ;
  Vector2 fim = { (float)(cdh->posicao->x), (float)(cdh->posicao->y - cdh->raio) };

  bool a = true;
  while (!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(BLACK);
      DrawText( "CIRCVLVM HORARVM", 10, 10, 20, WHITE );
      DrawCircleV( *(Vector2*)cdh->posicao, cdh->raio, WHITE );
      DrawLineV( inicio, fim, BLACK ); a=false;
    EndDrawing();
  }

  //raios
  CirculoDasHoras_destrutor( cdh );
  Tela_destrutor( tela );
  CloseWindow();
  exit(0);
}

