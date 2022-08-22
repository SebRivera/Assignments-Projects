/*
Nombre: OperacionesPoli_SGRC.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/19/2020
Descripción: Cabecera para Polinomios.cpp
*/

#ifndef OPERACIONESPOLI_SGRC_POLINOMIOS_H
#define OPERACIONESPOLI_SGRC_POLINOMIOS_H
//**********************************************************************************************************************
/** \brief Función que crea el arreglo de un polinomio mediante memoria dinamica.
 *
 * \param grado Grado del polinomio (tamaño).
 * \return El arreglo del polinomio.
 */
float * CrearPoli(int grado);
//**********************************************************************************************************************
/** Función que Destruye el arreglo de un polinomio mediante memoria dinamica.
 *
 * \param polinomio El polinomio a destruir.
 */
void EliminarPoli(float *&polinomio);
//**********************************************************************************************************************
/**\brief Función que permite la captura del polinomio.
 *
 * \param polinomio Polinomio en donde se guardaran los datos.
 * \param gardo Grado del polinomio (tamaño).
 */
void CapturarPoli(float polinomio[], int grado);
//**********************************************************************************************************************
/**\brief Función que permite la impresión de un polinomio.
 *
 * \param polinomio Polinomio a Imprimir
 * \param gardo Grado del polinomio (tamaño).
 */
void ImprimirPoli(const float polinomio[],int grado);
//**********************************************************************************************************************
/**\brief Función que determina la polaridad de un valor.
 *
 * @param Valor Valor a determinar si es positivo o negativo.
 */
void DetPolaridad(float Valor);
//**********************************************************************************************************************
/** \brief Función que realiza la suma de dos polinomios.
 *
 * \param polinomioA Primer polinomiio a sumar.
 * \param polinomioB Segundo polinomiio a sumar.
 * \param gradoA Grado del primer polinomio.
 * \param gradoB Grado del segundo polinomio.
 * \param gradoR Grado del polinomio resultante.
 * \return El polinomio resultante.
 */
float * SumaPoli(const float polinomioA[], const float polinomioB[], int gradoA, int gradoB, int &gradoR);
//**********************************************************************************************************************
/** \brief Función que realiza la resta de dos polinomios.
 *
 * \param polinomioA Primer polinomiio a restar.
 * \param polinomioB Segundo polinomiio a restar.
 * \param gradoA Grado del primer polinomio.
 * \param gradoB Grado del segundo polinomio.
 * \param gradoR Grado del polinomio resultante.
 * \return El polinomio resultante.
 */
float * RestaPoli(const float polinomioA[], const float polinomioB[], int gradoA, int gradoB, int &gradoR);
//**********************************************************************************************************************
/** \brief Función que realiza la multiplicación de dos polinomios.
 *
 * \param polinomioA Primer polinomiio a multiplicar.
 * \param polinomioB Segundo polinomiio a multiplicar.
 * \param gradoA Grado del primer polinomio.
 * \param gradoB Grado del segundo polinomio.
 * \param gradoR Grado del polinomio resultante.
 * \return El polinomio resultante.
 */
float * MultiPoli(const float polinomioA[], const float polinomioB[], int gradoA, int gradoB, int gradoR);
//**********************************************************************************************************************
/**\brief Función que calcula la derivada de de un polinomio
 *
 * \param polinomioA Polinomio al cual se calculara la derivda.
 * \param gradoA Grado del polinomio A.
 * \param gradoR Grado del polinomio resultante.
 * \return El polinomio resultante.
 */
float * DerivadaPoli(const float polinomioA[], int gradoA, int &gradoR);
//**********************************************************************************************************************
/**\brief Función que evalua un polinomio con una x dada.
 *
 * \param polinomioA Polinomio a evaluar.
 * \param grado Grado del polinomio a evaluar
 * \param x Valor con el cual se evaluará
 * \return Resultado de la evaluación
 */
float EvaluarPoli(const float polinomioA[],int grado, float x);
//**********************************************************************************************************************
#endif //OPERACIONESPOLI_SGRC_POLINOMIOS_H
