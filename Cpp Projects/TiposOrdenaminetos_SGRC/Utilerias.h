/*
Nombre: Utilerias.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/26/2020
Descripción: Cabecera para los archivos "Utilerias.cpp" y "Utilerias.tpp".
*/

#ifndef TIPOSORDENAMINETOS_SGRC_UTILERIAS_H
#define TIPOSORDENAMINETOS_SGRC_UTILERIAS_H

#define ALTURA_MAX 20
#define TAM_MAX 70

enum estadoCursor{APAGADO, ENCENDIDO};

enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};


//**********************************************************************************************************************
/**\brief Función que presenta el menú y captura la opción.
 *
 * \return Opción ingresada por el usuario.
 */
int Menu();
//**********************************************************************************************************************
/**\brief Función que presenta un menú auxilar y captura la opción.
 *
 * \return Opción ingresada por el usuario.
 */
int SubMenu();
//**********************************************************************************************************************
/**\brief Función que captura el tamaño del arreglo.
 *
 * \return Tamaño ingresado por el usuario.
 */
int CapMAX(int tamano);
//**********************************************************************************************************************
/** \brief Función que crea un arreglo mediante memoria dinamica.
 *
 * \param tamano Tamaño del arreglo.
 * \return El arreglo creado.
 */
int * CrearArreglo(int tamano);
//**********************************************************************************************************************
/** Función que destruye el arreglo creado mediante memoria dinamica.
 *
 * \param polinomio El polinomio a destruir.
 */
void EliminarArreglo(int *&arreglo);
//**********************************************************************************************************************
/**\brief
 *
 * \param arreglo Recibe el arreglo a imprimir.
 * \param largo Recibe el tamaño del arreglo.
 * \param alturaMax Recibe el valor máximo que cada valor en el arreglo puede tener.
 * \param caracter Carácter con el cual se imprimirá.
 */
void Histograma(int *arreglo ,int largo ,int alturaMax ,char caracter);
//**********************************************************************************************************************
/** \brief Función que mueve al Cursor a la Coordenada (x,y)
 *
 * \param x Posición en x
 * \param y Posición en y
 */
void gotoxy(short x,short y);
//**********************************************************************************************************************
/** \brief Función que Determina el tamaño de la ventana de la consola
 *
 * \param Ancho Ancho de la ventana
 * \param Alto Altura de la ventana
 */
void TamVentana(int Ancho, int Alto);
//**********************************************************************************************************************
/** \brief Función que determina el estado y el modo del cursor
 *
 * \param estado Establece el cursor a apagado o encendido
 * \param modo Establece el grosor del Cursor
 */
void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);
//**********************************************************************************************************************
/** \brief Plantilla que permite la captura segura de cualquier tipo de dato ingresado.
 *
 * \param &n Referencia del valor ingresado.
 * \param const char solicitud[] La sentencia de carácteres a imprimir.
 */
template <typename TIPO>
void CapturaSegura(TIPO &n, const char solicitud[]);
//**********************************************************************************************************************

#include "Utilerias.tpp"
#endif //TIPOSORDENAMINETOS_SGRC_UTILERIAS_H
