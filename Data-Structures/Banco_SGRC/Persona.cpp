/*
Nombre: Persona.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 06/03/2021
Descripción: Archivo de implementación de "Persona.h"
*/


#include "Persona.h"
//******************************************************************************************************************
Persona::Persona(): nombre(""), apellido(""){}
//******************************************************************************************************************
Persona::Persona(const std::string &nombreP, const std::string &apellidoP): nombre(nombreP), apellido(apellidoP) {}
//******************************************************************************************************************
void Persona::asignarPersona(const std::string &nombreP, const std::string &apellidoP) {
    nombre = nombreP;
    apellido = apellido;
}
//******************************************************************************************************************
void Persona::asignarNombre(const std::string &nombreP) {
    nombre = nombreP;
}
//******************************************************************************************************************
void Persona::asignarApellido(const std::string &apellidoP) {
    apellido = apellidoP;
}
//******************************************************************************************************************
std::string Persona::obtenerNombre() const {
    return nombre;
}
//******************************************************************************************************************
std::string Persona::obtenerApellido() const {
    return apellido;
}
//******************************************************************************************************************
std::ostream &operator<<(std::ostream &fSalida, const Persona &persona) {
    fSalida << persona.nombre << " " << persona.apellido;
    return fSalida;
}
//******************************************************************************************************************