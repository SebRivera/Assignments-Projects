/*
Nombre: Utilerias.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/19/2020
Descripción: Cabecera para los archivos "Utilerias.cpp" y "Utilerias.tpp"
*/

#ifndef OPERACIONESPOLI_SGRC_UTILERIAS_H
#define OPERACIONESPOLI_SGRC_UTILERIAS_H

#define TAM_MAX 20

enum Operaciones{SUMA = 1, RESTA, MULTIPLICACION, DIVISION, DERIVADA, EVALUACION};

//**********************************************************************************************************************

/**\brief Función que presenta el menú y captura la opción.
 *
 * \return Opción ingresada por el usuario
 */
int Menu();
//**********************************************************************************************************************
/**\brief Función que captura el grado del polinomio.
 *
 * \return Grado ingresada por el usuario.
 */
int CapGrado();
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
#endif //OPERACIONESPOLI_SGRC_UTILERIAS_H
