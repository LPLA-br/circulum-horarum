# CIRCULUM HORARUM - LPLA-br

Aplicação de relógio das vinte e quatro horas para teres uma
visão aprimorada do teu dia.

# COMO COMPILAR E EXECUTAR ESTE SOFTWARE

Compilação da versão em debug:
```
$ build-debug.sh
$ ./build-debug/main
```

Compilação da versão modo release:
```
$ build.sh
$ ./build/main
```

Limpar resultados de todas compilações:
```
$ clear-all.sh
```

# PADRÕES DE CODIFICAÇÃO

I. Estruturas sempre possuem funções construtoras e destrutoras.
II. Herança por decoração de estruturas base em estruturas derivadas.
III. Encapsulamento arbitrado pelo programador.
IV. Polimorfismo por ponteiro à função e à estrutura.
V. Poucas responsabilidades por header.h

# VERSÃO

```
0.2.6
 - Func: Visualizar hora corrente no circulo das horas.
 - Fix: correção da orientação das horas com meia noite no topo.
 - Fix: correção da divisão das horas e minutos.
 - Fix/Improve: circulo das horas bidividido
 - Fix/Improve: ponteiro do agora mais grosso
 - Fix: Patch com definição de PI para compilações clang
 - Fix: Correção de tautologia na verificação do GMT
 - Func: Alterar dimensões da tela através de parâmetros da compilação.
 
```

# LICENSA

This software is under "BSD-3-clause" license
read more about in: https://opensource.org/license/BSD-3-clause

