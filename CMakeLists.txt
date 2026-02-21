cmake_minimum_required(VERSION 3.15...4.1)
project(circulum-horarum-core)

set (Sample_VERSION_MAJOR 0)
set (Sample_VERSION_MINOR 1)
set (Sample_VERSION_MAJOR 4)

set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED ON)
set (CMAKE_C_EXTENSIONS OFF)

set (CMAKE_C_COMPILER "clang")

message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

# Este cmake usa raylib estaticamente compilada para android

#====================ARQUIVOS FONTE
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

#==================== ALVOS

add_executable(main ${SOURCES})

#HEADERS
target_include_directories(main PRIVATE raylib
  ${PROJECT_SOURCE_DIR}/include
)

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

target_link_options( main PRIVATE
	-fsanitize=address,undefined,leak 
)

#==================== DEPENDÊNCIAS

#find_package(raylib REQUIRED)

# -lm -lraylib
target_link_libraries(main
  m
  raylib
	#	${PROJECT_SOURCE_DIR}/raylib-static/libraylib.a
)

#==================== TESTES (opcional)

#==================== ENPACOTAMENTO tar.gz

#set(CPACK_PACKAGE_NAME "circulum-horarum-core")
#set(CPACK_PACKAGE_VERSION "1.0.0")
#set(CPACK_GENERATOR "TGZ")
#include(CPack)

