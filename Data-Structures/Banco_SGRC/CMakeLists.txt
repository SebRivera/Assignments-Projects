cmake_minimum_required(VERSION 3.17)
project(Banco_SGRC)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(Banco_SGRC main.cpp Cola.h Cola.tpp Persona.h Persona.cpp Banco.h Banco.cpp)