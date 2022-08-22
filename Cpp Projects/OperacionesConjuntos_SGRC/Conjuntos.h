/*
Nombre: Conjuntos.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/14/2020
Descripción: Cabecera para el archivo "Conjuntos.cpp".
*/

#ifndef OPERACIONESCONJUNTOS_CONJUNTOS_H
#define OPERACIONESCONJUNTOS_CONJUNTOS_H
//**********************************************************************************************************************
/** \brief Función que captura los elementos de un conjuto dado.
 *
 * \param conjunto Arreglo del conjunto a capturar.
 * \param cardinalidad Tamaño del arreglo.
 */
void CapturarCon(char conjunto[], int cardinalidad);
//**********************************************************************************************************************
/** \brief Función que evalua si un valor pertenece al conjunto dado.
 *
 * \param conjunto Arreglo del conjunto a capturar.
 * \param cardinalidad Tamaño del arreglo.
 * \param valor Dato a evaluar sobre el conjunto.
 * \return True si pertenece al conjunto, False si no pertenece al conjunto.
 */
bool PerteneceAlConjunto(const char conjunto[], int cardinalidad, char valor);
//**********************************************************************************************************************

/** \brief Función que imprime un conjunto dado.
 *
 * \param conjunto Arreglo del conjunto a capturar.
 * \param cardinalidad Tamaño del arreglo.
 * \param nombreCon Solicitud a imprimir el nombre del conjunto.
 */
void ImprimirCon(const char conjunto[], int cardinalidad, const char nombreCon[]);
//**********************************************************************************************************************
/**\brief Función que realiza la union de dos conjuntos.
 *
 * \param conjuntoA Primer conjunto de la operación.
 * \param conjuntoB Segundo conjunto de la operación.
 * \param conjuntoR Conjunto Resultado de la operación.
 * \param cardA Tamaño del conjunto A.
 * \param cardB Tamaño del conjunto B.
 * \return La cantidad de veces que se repitio algún elemento.
 */
int UnionCon(const char conjuntoA[], const char conjuntoB[], char conjuntoR[], int cardA, int cardB);
//**********************************************************************************************************************
/** \brief Función que obtiene la intersección de dos conjuntos
 *
 * \param conjuntoA Primer conjunto de la operación.
 * \param conjuntoB Segundo conjunto de la operación.
 * \param conjuntoR Conjunto Resultado de la operación.
 * \param cardA Tamaño del conjunto A.
 * \param cardB Tamaño del conjunto B.
 * @param cardR Tamaño del Conjunto Resultante
 */
void InterCon(const char conjuntoA[], const char conjuntoB[], char conjuntoR[], int cardA, int cardB, int &cardR);
//**********************************************************************************************************************
/** \brief Función que realiza la diferencia de dos conjuntos.
 *
 * \param conjuntoA Primer conjunto de la operación.
 * \param conjuntoB Segundo conjunto de la operación.
 * \param conjuntoR Conjunto Resultado de la operación.
 * \param cardA Tamaño del conjunto A.
 * \param cardB Tamaño del conjunto B.
 * @param cardR Tamaño del Conjunto Resultante
 */
void DiferenciaCon(const char conjuntoA[], const char conjuntoB[], char conjuntoR[], int cardA, int cardB, int &cardR);
//**********************************************************************************************************************

#endif //OPERACIONESCONJUNTOS_CONJUNTOS_H
