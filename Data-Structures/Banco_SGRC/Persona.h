/*
Nombre: Persona.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 06/03/2021
Descripción: Cabecera de la clase Persona.
*/

#ifndef BANCO_SGRC_PERSONA_H
#define BANCO_SGRC_PERSONA_H
#include <iostream>

/**@class Persona Clase que pemrite crear una persona con un nombre y apellido dado.
 */
class Persona {
public:
    //******************************************************************************************************************
    /** @brief Constructor por default de la clase.
    */
    Persona();
    //******************************************************************************************************************
    /** @brief Constructor de dos paramatros para crear una persona con un nombre y un apellido.
     *
     * @param nombreP Nombre a asignar a la persona.
     * @param apellidoP Apellido a asignar a la persona.
     */
    Persona(const std::string &nombre, const std::string &apellido);
    //******************************************************************************************************************
    /** @brief M&eacute;todo para asignar un nuevo nombre completo a una persona.
     *
     * @param nombreP Nombre a asignar a la persona.
     * @param apellidoP Apellido a asignar a la persona.
     */
    void asignarPersona(const std::string &nombreP, const std::string &apellidoP);
    //******************************************************************************************************************
    /** @brief M&eacute;todo para asignar un nuevo nombre a una persona.
     *
     * @param nombreP Nombre a asignar a la persona.
     */
    void asignarNombre(const std::string &nombreP);
    //******************************************************************************************************************
    /** @brief M&eacute;todo para asignar un nuevo apellido a una persona.
     *
     * @param apellidoP Apellido a asignar a la persona.
     */
    void asignarApellido(const std::string &apellidoP);
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener el nombre de la persona.
     *
     * @return Retorna el nombre de la persona.
     */
    std::string obtenerNombre() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener el apellido de la persona.
     *
     * @return Retorna el apellido de la persona.
     */
    std::string obtenerApellido() const;
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador "<<" para imprimir el nombre completo de la Persona.
     *
     * @param fSalida Flujo de salida.
     * @param persona Persona a imprimir.
     * @return Flujo de salida a imprimir.
     */
    friend std::ostream &operator<<(std::ostream &fSalida, const Persona &persona);
    //******************************************************************************************************************
private:
    std::string nombre;     /** String que contiene al nombre de la Persona**/
    std::string apellido;   /** String que contiene al apellido de la Persona**/
};


#endif //BANCO_SGRC_PERSONA_H
