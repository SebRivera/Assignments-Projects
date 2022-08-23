cmake_minimum_required(VERSION 3.15)
project(OperacionesMatrices_SGRC)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(OperacionesMatrices_SGRC main.cpp Utilerias.tpp Utilerias.h Utilerias.cpp FuncionesMatrices.h FuncionesMatrices.cpp)