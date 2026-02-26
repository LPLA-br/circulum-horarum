#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

// CONSTANTES

// ponteiroagora
#define HORAS_NO_DIA 24
#define MINUTOS_NA_HORA 60

#define ESPESSURA_PONTEIRO_ESPESSO 4

//circulo das horas
#define CIRCULO_GRAUS 360

//Desc: patch de correção de posição das horas.
#define CORRECAO_ANGULAR 90

// componentesangulo
#define LOCAL_MAX 360.0
#define LOCAL_MIN 0.0

// raiosFixos
#define NUMERO_RAIOS 24

#define FATIA (float)((float)CIRCULO_GRAUS)/(HORAS_NO_DIA)

//math (patch para indefinição nos padrões não gnu)
#define M_PI 3.14159265358979323846

// CONSTANTES DEFINIDAS EM TEMPO DE COMPILAÇÃO (-DNOME)
// tamanho tela
#ifndef LARGURA 
	#define LARGURA 800
#endif

#ifndef ALTURA
#define ALTURA 600
#endif

#endif // CONSTANTES_H_INCLUDED
