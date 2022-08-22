/*
Nombre: Utilerias.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/14/2020
Descripción: Cabecera para los archivos "Utilerias.cpp" y "Utilerias.tpp"
*/

#ifndef OPERACIONESCONJUNTOS_UTILERIAS_H
#define OPERACIONESCONJUNTOS_UTILERIAS_H

#define TAM_MAX 100

enum Operaciones{UNION = 1, INTERSECCION, DIFERENCIA, CONTENENCIA, COMPLEMENTO, PERTENENCIA};

//**********************************************************************************************************************
/**\brief Función que presenta el menú y captura la opción.
 *
 * \return Opción ingresada por el usuario
 */
int Menu();
//**********************************************************************************************************************
/**\brief Función que captura la cardinalidad de los vectores.
 *
 * \return Cardinalidad ingresada por el usuario.
 */
int CapCardinalidad();
//**********************************************************************************************************************
/** \brief Plantilla que permite la captura segura de cualquier tipo de dato ingresado.
 *
 * \param &n Referencia del valor ingresado.
 * \param const char solicitud[] La sentencia de charácteres a imprimir.
 *
 */
template <typename TIPO>
void CapturaSegura(TIPO &n, const char solicitud[]);
//**********************************************************************************************************************

#include "Utilerias.tpp"
#endif //OPERACIONESCONJUNTOS_UTILERIAS_H
