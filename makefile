#NOME DO PROJETO
PROJ_NAME=main

#COMPILADOR
CC=gcc

#FLAGS DO COMPILADOR (vide manual do compilador)
CC_FLAGS=-O0		\

#GBC DEGUG FLAG
CC_DFLAG=-g

# CÓDIGOS FONTE
SRCS= main.c CirculoDasHoras.c

# OBJETOS GERADOS DOS CÓDIGOS FONTE
OBJS= main.o CirculoDasHoras.o

# LIGAÇÃO PARA raylib (adiciona (-L PATH) se não instalado)
RECLAMES= -lraylib

#COMPILAÇÃO FINAL

all: $(OBJS)
	$(CC) $(OBJS) -o $(PROJ_NAME).out $(RECLAMES) $(CC_FLAGS)

#COMPILAÇÃO PARA DEBUG ASSEMBLY COM O GDB (gnu debugger)

debug: $(OBJS)
	$(CC) $(CC_DFLAG) $(SRCS) -o $(PROJ_NAME).gdb $(RECLAMES) $(CC_FLAGS) 

#COMPILAÇÃO DOS OBJETOS

main.o:
	$(CC) -c main.c -o main.o

CirculoDasHoras.o:
	$(CC) -c CirculoDasHoras.c -o CirculoDasHoras.o

# REMOÇÃO DO RESULTADO DA COMPILAÇÃO

clean:
	rm ./${PROJ_NAME}.out *.o 

debugclean:
	rm ./${PROJ_NAME}.gdb *.o
