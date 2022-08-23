/*
Nombre: FuncionesMatrices.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 5/18/2020
Descripción: Cabecera para el archivo "FuncionesMatrices.cpp"
*/

#ifndef OPERACIONESMATRICES_SGRC_FUNCIONESMATRICES_H
#define OPERACIONESMATRICES_SGRC_FUNCIONESMATRICES_H

enum Operaciones{
        CREAR = 1, /** Crear un nuevo archivo */
        SUMAR, /** Sumar dos matrices */
        RESTAR, /** Restar dos matrices */
        MULTIPLICAR, /** Multiplicar dos matrices */
        ESCALAR, /** Multiplicar una matriz por un escalar */
        TRANSPUESTA, /** Transpuesta de una matriz */
        INVERSA /** Inversa de una matriz */
};

/**@brief Función que crea una matriz mediante memoria dinámica con los renglones juntos.
 *
 * @param m Número de renglones de la matriz.
 * @param n Número de columnas de la matriz.
 * @return La dirección donde inicia la matriz.
 */
float **CrearMatriz(int m, int n);
/**@brief Función que libera memoria de la matriz con los renglones juntos.
 *
 * @param matriz La matriz por referencia a liberar.
 */
void EliminarMatriz(float **&matriz);
/**@brief Función que suma dos matrices.
 *
 * @param matrizA Primera matriz a sumar.
 * @param matrizB Segunda matriz a sumar.
 * @param m Número de renglones de las matrices.
 * @param n Número de columnas de las matrices.
 * @return La matriz suma.
 */
float **SumarMatrices(const float * const *matrizA, const float * const *matrizB, int m, int n);
/**@brief Función que resta dos matrices.
 *
 * @param matrizA Matriz a restar.
 * @param matrizB Matriz resta.
 * @param m Número de renglones de las matrices.
 * @param n Número de columnas de las matrices.
 * @return La matriz resta.
 */
float **RestarMatrices(const float * const *matrizA, const float * const *matrizB, int m, int n);
/**@brief Función que multiplica dos matrices.
 *
 * @param matrizA Primera matriz a multiplicar.
 * @param matrizB Segunda matriz a multiplicar.
 * @param m Número de renglones de la matrizA.
 * @param n Número de columnas de la matrizA.
 * @param nB Número de columnas de la matrizB
 * @return La matriz multiplicada.
 */
float **MultiMatrices(const float * const *matrizA, const float * const *matrizB, int m, int n, int nB);
/**@brief Función que multiplica una matriz por un escalar.
 *
 * @param matriz La matriz sobre el cual se harán los cambios.
 * @param m Número de renglones de la matriz.
 * @param n Número de columnas de la matriz.
 * @param escalar Valor por el cual se multiplicará la matriz.
 * @return La matriz resultado.
 */
float **EscalarPorMatriz(const float * const *matriz, int m, int n, float escalar);
/**@brief Función que encuentra la matriz transpuesta de una matriz.
 *
 * @param matriz La matriz sobre el cual se harán los cambios.
 * @param m Número de renglones de la matriz.
 * @param n Número de columnas de la matriz.
 * @return La matriz transpuesta.
 */
float **TransPMatriz(const float * const *matriz, int m, int n);
/**@brief Función que encuentra la matriz inversa de una matriz.
 *
 * @param matriz La matriz sobre el cual se harán los cambios.
 * @param n Dimensión de la matriz.
 * @param matrizR Matriz en donde se guardara la matriz inversa.
 * @return True si es invertible, False si no es invertible.
 */
bool InversaMatriz(const float * const *matriz, short n, float * const *matrizR);
/**@brief Función que captura los elementos de una matriz.
 *
 * @param matriz Matriz a capturar.
 * @param m Número de renglones de la matriz.
 * @param n Número de columnas de la matriz.
 */
void CapturarMatriz(float * const *matriz, short m, short n);
/**@brief Función que imprime una matriz.
 *
 * @param matriz Matriz a imprimir.
 * @param m Número de renglones de la matriz.
 * @param n Número de columnas de la matriz.
 */
void ImprimirMatriz(const float * const *matriz, short m, short n);

#endif //OPERACIONESMATRICES_SGRC_FUNCIONESMATRICES_H
