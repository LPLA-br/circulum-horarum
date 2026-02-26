cmake_minimum_required(VERSION 3.15...4.1)
project(circulum-horarum-core)

set (Sample_VERSION_MAJOR 0)
set (Sample_VERSION_MINOR 2)
set (Sample_VERSION_MAJOR 6)

set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED ON)
set (CMAKE_C_EXTENSIONS OFF)

set (CMAKE_C_COMPILER "clang")

message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")


#====================ARQUIVOS FONTE
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

#==================== ALVOS

add_executable(main ${SOURCES})

#HEADERS
target_include_directories(main PRIVATE raylib
  ${PROJECT_SOURCE_DIR}/include
)

# OPÇÕES DEFINÍVEIS EM TEMPO DE COMPILAÇÃO
option(ALTURA "Desc: altura da janela" 600)
option(LARGURA "Desc: largura da janela" 800)
target_compile_definitions( main PRIVATE ALTURA=${ALTURA} LARGURA=${LARGURA} )

# CONJUNTO DE FLAGS DO COMPILADOR PARA DEBUG E PARA RELEASE
target_compile_options( main PRIVATE
  $<$<CONFIG:Debug>:
  -std=c11
  -Wall
  -Wextra
	-Wpedantic 
	-Werror 
#	-Wconversion 
	-Wstrict-prototypes 
	-Wundef 
	-Wshadow 
	-Wpointer-arith 
	-fsanitize=address,undefined,leak 
	-g3
  -O0
  >
  $<$<CONFIG:Release>:-O3 -DNDEBUG>
)

# ADIÇÃO DE OPÇÕES DE LINKAGEM CLI AO COMPILADOR
target_link_options( main PRIVATE
	-fsanitize=address,undefined,leak 
)

#==================== DEPENDÊNCIAS

#VERIFICAÇÃO DE DEPENDÊNCIAS NECESSÁRIAS NO SISTEMA
find_package(raylib REQUIRED VERSION 5.5.0 )

#DEFINIÇÃO DE LINKS COM BIBLIOTECAS DO SISTEMA -lEXEMPLO
target_link_libraries(main
  m
	raylib
)

#==================== TESTES (in deo fiat)

#==================== ENPACOTAMENTO tar.gz

#set(CPACK_PACKAGE_NAME "circulum-horarum-core")
#set(CPACK_PACKAGE_VERSION "1.0.0")
#set(CPACK_GENERATOR "TGZ")
#include(CPack)

