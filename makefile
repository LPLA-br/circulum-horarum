#NOME DO PROJETO
PROJ_NAME=main

#COMPILADOR
CC=gcc

#FLAGS DO COMPILADOR (vide manual do compilador)
CC_FLAGS=-O0		\

#GBC DEGUG FLAG
CC_DFLAG=-g

# PREFIXO SRC
SRC=./src/
# CÓDIGOS FONTE
SRCS= $(SRC)main.c \
			$(SRC)circulodashoras.c \
			$(SRC)tela.c \
			$(SRC)raiofixo.c \
			$(SRC)degrad.c \
			$(SRC)componentesangulo.c \
			$(SRC)ponteiroagora.c

# OBJETOS GERADOS DOS CÓDIGOS FONTE
OBJS= main.o \
			circulodashoras.o \
			tela.o \
			raiofixo.o \
			degrad.o \
			componentesangulo.o \
			ponteiroagora.o

# LIGAÇÃO PARA raylib (adiciona (-L PATH) se não instalado)
RECLAMES= -lm -lraylib

#EXTRA PARA CAPTURA DE PROBLEMAS
EXTRA= -Wall -Wextra -Wpedantic -fsanitize=address,undefined

#COMPILAÇÃO FINAL

all: $(OBJS)
	$(CC) $(OBJS) -o $(PROJ_NAME).out $(RECLAMES) $(CC_FLAGS)

#COMPILAÇÃO PARA DEBUG ASSEMBLY COM O GDB (gnu debugger)

debug: $(OBJS)
	$(CC) $(CC_DFLAG) $(EXTRA) $(SRCS) -o $(PROJ_NAME).gdb $(RECLAMES) $(CC_FLAGS) 

#COMPILAÇÃO DOS OBJETOS

main.o:
	$(CC) -c $(SRC)main.c -o main.o

#SUBPARTES

circulodashoras.o:
	$(CC) -c $(SRC)circulodashoras.c -o circulodashoras.o

raiofixo.o:
	$(CC) -c $(SRC)raiofixo.c -o raiofixo.o

ponteiroagora.o:
	$(CC) -c $(SRC)ponteiroagora.c -o ponteiroagora.o

tela.o:
	$(CC) -c $(SRC)tela.c -o tela.o

degrad.o:
	$(CC) -c $(SRC)degrad.c -o degrad.o

componentesangulo.o:
	$(CC) -c $(SRC)componentesangulo.c -o componentesangulo.o


# REMOÇÃO DO RESULTADO DA COMPILAÇÃO

clean:
	rm ./${PROJ_NAME}.out *.o 

debugclean:
	rm ./${PROJ_NAME}.gdb *.o
