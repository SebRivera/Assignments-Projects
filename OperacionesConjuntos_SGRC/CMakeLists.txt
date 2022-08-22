cmake_minimum_required(VERSION 3.15)
project(OperacionesConjuntos)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(OperacionesConjuntos main.cpp Utilerias.tpp Utilerias.h Utilerias.cpp Conjuntos.cpp Conjuntos.h)