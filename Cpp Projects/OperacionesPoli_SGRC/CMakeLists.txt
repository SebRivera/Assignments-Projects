cmake_minimum_required(VERSION 3.15)
project(OperacionesPoli_SGRC)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(OperacionesPoli_SGRC main.cpp Utilerias.tpp Utilerias.h Utilerias.cpp Polinomios.cpp Polinomios.h)