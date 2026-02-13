#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED

typedef struct
{
  int largura;
  int altura;
  const char* titulo;
} Tela;

Tela* Tela_construtor( int altura, int largura, const char* titulo );
void Tela_destrutor( Tela* t );

#endif // TELA_H_INCLUDED
