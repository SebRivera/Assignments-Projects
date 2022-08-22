cmake_minimum_required(VERSION 3.15)
project(Cartas_SGRC)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(Cartas_SGRC main.cpp Utilerias.cpp Utilerias.h "ImpresionCartas.cpp" "ImpresionCartas.h" ImpresionCartasOriginal.cpp)