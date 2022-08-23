/*
Nombre: MetodosOrdenamineto.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/26/2020
Descripción: Cabecera para el archivo de "MetodosOrdenamineto.cpp".
*/

#ifndef TIPOSORDENAMINETOS_SGRC_METODOSORDENAMIENTO_H
#define TIPOSORDENAMINETOS_SGRC_METODOSORDENAMIENTO_H

enum Metodos{BURBUJA = 1, SELECCION, INSERCION, QUICKSORT, MERGESORT};

//**********************************************************************************************************************
/**\brief Función que intercambia dos valores de un arreglo.
 *
 * \param arreglo Arreglo sobre el cual se hará el intercambio.
 * \param indiceA Indice del primer valor a intercambiar.
 * \param indiceB Indice del segundo valor a intercambiar.
 */
void Intercambiar(int arreglo[], int indiceA, int indiceB);
//**********************************************************************************************************************
/** \brief Función que ordena los elementos de un arreglo mediante el método de Burbuja.
 *
 * \param arreglo Arreglo a ordenar.
 * \param tamano Tamaño del arreglo para imprimir el histograma.
 * \param caracter Carácter para imprimir el histograma.
 */
void Burbuja(int arreglo[], int tamano, char caracter);
//**********************************************************************************************************************
/** \brief Función que ordena los elementos de un arreglo mediante el método de Selección.
 *
 * \param arreglo Arreglo a ordenar.
 * \param tamano Tamaño del arreglo para imprimir el histograma.
 * \param caracter Carácter para imprimir el histograma.
 */
void Seleccion(int arreglo[], int tamano, char caracter);
//**********************************************************************************************************************
/** \brief Función que ordena los elementos de un arreglo mediante el método de Incersión.
 *
 * \param arreglo Arreglo a ordenar.
 * \param tamano Tamaño del arreglo para imprimir el histograma.
 * \param caracter Carácter para imprimir el histograma.
 */
void Insercion(int arreglo[], int tamano, char caracter);
//**********************************************************************************************************************
/**\brief Función que ordena los elementos de un arreglo mediante el método de QuickSort.
 *
 * \param arreglo Arreglo a ordenar.
 * \param izq Indice para el valor de la izquierda.
 * \param der izq Indice para el valor de la derecha.
 * \param tamano Tamaño del arreglo para imprimir el histograma.
 * \param caracter Carácter para imprimir el histograma.
 */
void QuickSort(int *arreglo, int izq, int der, int tamano, char caracter);
//**********************************************************************************************************************
/**\brief Función que ordena los elementos de un arreglo mediante el método de MergeSort.
 *
 * \param arreglo Arreglo a ordenar.
 * \param tamano Tamaño del arreglo.
 * \param tamanoH Tamaño del arreglo para imprimir el histograma.
 * \param caracter Carácter Caracter para imprimir el histograma.
 */
void MergeSort(int *arreglo, int tamano, int tamanoH, char caracter);
//**********************************************************************************************************************


#endif //TIPOSORDENAMINETOS_SGRC_METODOSORDENAMIENTO_H
