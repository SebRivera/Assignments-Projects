/*
Nombre: OperacionesMatrices_SGRC.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 5/18/2020
Descripción: Cabecera para los archivos "Utilerias.cpp" y "Utilerias.tpp"
*/

#ifndef OPERACIONESMATRICES_SGRC_UTILERIAS_H
#define OPERACIONESMATRICES_SGRC_UTILERIAS_H

/**@brief Función que captura el nombre de un archivo y comprueba su extensión (.txt o .dat).
 *
 * @param nombreArchivo Variable en donde se guardará el nombre del archivo.
 * @param solicitud La sentencia de caracteres a imprimir.
 * @return
 */
bool  LeerYComprobarExt(char nombreArchivo[], const char solicitud[]);
/**@brief Función que presenta un menú para capturar por teclado o mediante un archivo.
 *
 * @param NombreM Nombre de la matriz a capturar.
 * @return Opción seleccionada por el usuario.
 */
int MenuCaptura(const char NombreM[]);
/**@brief Función que presenta un menú para decidir si guardar o no la matriz en un archivo.
 *
 * @return Opción seleccionada por el usuario.
 */
int MenuGuardar();
/**@brief Plantilla que permite la captura segura de cualquier tipo de dato ingresado.
 *
 * @param n Referencia del valor ingresado.
 * @param solicitud La sentencia de caracteres a imprimir.
 */
template <typename TIPO>
void CapturaSegura(TIPO &n, const char solicitud[]);


#include "Utilerias.tpp"
#endif //OPERACIONESMATRICES_SGRC_UTILERIAS_H
