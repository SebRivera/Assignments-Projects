/*
Nombre: FuncionesMatrices.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 5/20/2020
Descripción: Funciónes para realizar operaciones con matrices.
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "FuncionesMatrices.h"
#include "Utilerias.h"

float **CrearMatriz(int m, int n)
{
    float **Matriz = NULL;
    Matriz = new float *[m];
    Matriz[0] = new float [m*n];
    for(int i = 1; i < m; ++i) Matriz[i] = Matriz[i-1] + n;
    return  Matriz;
}

void EliminarMatriz(float **&matriz)
{
    delete [] matriz[0];
    delete [] matriz;
    matriz = NULL;
}

float **SumarMatrices(const float * const *matrizA, const float * const *matrizB, int m, int n)
{
    float **MatrizR = CrearMatriz(m, n);

    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            MatrizR[i][j] = matrizA[i][j] + matrizB[i][j];

    return MatrizR;
}

float **RestarMatrices(const float * const *matrizA, const float * const *matrizB, int m, int n)
{
    float **MatrizR = CrearMatriz(m, n);

    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            MatrizR[i][j] = matrizA[i][j] - matrizB[i][j];

    return MatrizR;
}

float **MultiMatrices(const float * const *matrizA, const float * const *matrizB, int m, int n, int nB)
{
    float **MatrizR = CrearMatriz(m, nB);

    for(int i = 0; i < m; ++i)
        for(int j = 0; j < nB; ++j)
            for(int k = 0; k < n; ++k) MatrizR[i][j] += matrizA[i][k] * matrizB[k][j];

    return MatrizR;
}

float **EscalarPorMatriz(const float * const *matriz, int m, int n, float escalar)
{
    float **MatrizR = CrearMatriz(m, n);

    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            MatrizR[i][j] = matriz[i][j] * escalar;
    return MatrizR;
}

float **TransPMatriz(const float * const *matriz, int m, int n)
{
    float **MatrizR = CrearMatriz(n, m);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            MatrizR[i][j] = matriz[j][i];

    return MatrizR;
}
//**********************************************************************************************************************
/**@brief Función que intercambia dos renglones dentro de una matriz.
 *
 * @param matriz La matriz sobre el cual se harán los cambios.
 * @param n Dimensión de la matriz.
 * @param renUno Primer renglón a intercambiar.
 * @param renDos Segundo renglón a intercambiar.
 */
static void IntercambiarRenglones(float * const *matriz, short n, short renUno, short renDos)
{
    float Aux;
    for(int j = 0; j < n; ++j) {
        Aux = matriz[renUno][j];
        matriz[renUno][j] = matriz[renDos][j];
        matriz[renDos][j] = Aux;
    }
}
/**@brief Función que multiplica un renglón dentro de una matriz por un escalar.
 *
 * @param matriz La matriz sobre el cual se harán los cambios.
 * @param n Dimensión de la matriz.
 * @param renglon Renglón sobre el cual se hará la multiplicación.
 * @param escalar Valor el cual se multiplicará por un renglón
 */
static void MultiplicarRenglon(float * const *matriz, short n, short renglon, float escalar)
{
    for(int j = 0; j < n; ++j)
        matriz[renglon][j] = matriz[renglon][j] * escalar;
}
/**@brief Función que multiplica un renglón y se lo suma a otro.
 *
 * @param matriz La matriz sobre el cual se harán los cambios.
 * @param n Dimensión de la matriz.
 * @param renSumar Renglón a sumar.
 * @param renMulti Renglón a multiplicar.
 * @param escalar Valor por el cual se multiplicará por el renMulti.
 */
static void SumarMultiplosRenglones(float * const *matriz,  short n, short renSumar, short renMulti, float escalar)
{
    for(int j = 0; j < n; ++j)
        matriz[renSumar][j] = matriz[renSumar][j] + matriz[renMulti][j] * escalar;

}
//**********************************************************************************************************************
bool InversaMatriz(const float * const *matriz, short n, float * const *matrizR)
{
    float **MatrizAux = CrearMatriz(n,2*n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            MatrizAux[i][j] = matriz[i][j];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j){
            MatrizAux[i][n+j] = 0;
        }
        MatrizAux[i][n+i] = 1;
    }
    for(int i = 0; i < n; ++i) {
        if(MatrizAux[i][i] == 0){
            bool esInvertible = false;
            for(int j = i+1; j < n; ++j) {
                if(MatrizAux[j][i] != 0){
                    IntercambiarRenglones(MatrizAux,2*n,i,j);
                    esInvertible = true;
                    break;
                }
            }
            if(!esInvertible) return false;
        }
        MultiplicarRenglon(MatrizAux,2*n,i,1/MatrizAux[i][i]);
        for(int j = 0; j < i; ++j) SumarMultiplosRenglones(MatrizAux,2*n,j,i,-MatrizAux[j][i]);
        for(int j = i+1; j < n; ++j) SumarMultiplosRenglones(MatrizAux,2*n,j,i,-MatrizAux[j][i]);
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            matrizR[i][j] = MatrizAux[i][n+j];

    return true;
}

void CapturarMatriz(float * const *matriz, short m, short n)
{
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j){
            std::cout << "Elemento[" << i << "][" << j << "]: ";
            CapturaSegura(matriz[i][j],"");
        }
}

void ImprimirMatriz(const float * const *matriz, short m, short n)
{
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << std::setw(10) << matriz[i][j] ;
        std::cout << std::endl;
    }
}