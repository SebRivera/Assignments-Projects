/*
Nombre: Polinomios.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/19/2020
Descripción: Archivo que contiene todas las funciones de operaciones con polinomios.
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#include "Utilerias.h"
#include "Polinomios.h"
//**********************************************************************************************************************
float * CrearPoli(int grado)
{
    return new float [grado];
}
//**********************************************************************************************************************
void EliminarPoli(float *&polinomio)
{
    delete [] polinomio;
    polinomio = NULL;
}
//**********************************************************************************************************************
void CapturarPoli(float polinomio[], int grado)
{
    char Solicitud[40];
    do{
        sprintf(Solicitud, "Coeficiente #%d (Diferente de 0): ", grado);
        CapturaSegura(polinomio[0], Solicitud);
    }while(polinomio[0] == 0);
    for (int i = 1; i <= grado; ++i) {
        sprintf(Solicitud, "Coeficiente #%d: ", grado - i);
        CapturaSegura(polinomio[i], Solicitud);
    }
}
//**********************************************************************************************************************
float * SumaPoli(const float polinomioA[], const float polinomioB[], int gradoA, int gradoB, int &gradoR)
{
    int DifGrados = gradoA - gradoB;
    const float *Mayor, *Menor;

    if(DifGrados >= 0) Mayor = polinomioA, Menor = polinomioB, gradoR = gradoA;
    else Mayor = polinomioB, Menor = polinomioA, gradoR = gradoB, DifGrados = -DifGrados;
    float *polinomioR= CrearPoli(gradoR);
    for(int i = 1; i < DifGrados; ++i) polinomioR[i] = Mayor[i];
    for(int i = DifGrados; i <= gradoR; ++i) polinomioR[i] = Mayor[i] + Menor[i - DifGrados];

    return polinomioR;
}
//**********************************************************************************************************************
float * RestaPoli(const float polinomioA[], const float polinomioB[], int gradoA, int gradoB, int &gradoR) {
    int DifGrados = gradoA - gradoB;
    const float *Mayor, *Menor;

    if (DifGrados >= 0) Mayor = polinomioA, Menor = polinomioB, gradoR = gradoA;
    else Mayor = polinomioB, Menor = polinomioA, gradoR = gradoB, DifGrados = -DifGrados;
    float *polinomioR = CrearPoli(gradoR);
    for (int i = 1; i < DifGrados; ++i) polinomioR[i] = Mayor[i];
    for (int i = DifGrados; i <= gradoR; ++i) polinomioR[i] = Mayor[i] - Menor[i - DifGrados];

    return polinomioR;
}
//**********************************************************************************************************************
float * MultiPoli(const float polinomioA[], const float polinomioB[], int gradoA, int gradoB, int gradoR)
{
    float *polinomioR= CrearPoli(gradoR+1);
    for (int k = 0; k <= gradoR; k++)
        polinomioR[k] = 0;

    for(int i = 0; i <= gradoA; ++i){
        for (int j = 0; j <= gradoB; ++j){
            polinomioR[i+j] += (polinomioA[i] * polinomioB[j]);
        }
    }
    return polinomioR;
}
//**********************************************************************************************************************
float * DerivadaPoli(const float polinomioA[], int gradoA, int &gradoR)
{
    gradoR = gradoA-1;
    float *polinomioR= CrearPoli(gradoR);
    for(int i = 0; i <= gradoA; ++i){
        polinomioR[i] = (polinomioA[i] * (gradoA-i));
    }
    return polinomioR;
}
//**********************************************************************************************************************
float EvaluarPoli(const float polinomioA[], int gradoA, float x)
{
    float Resultado = 0;
    for (int i = 0; i <= gradoA; ++i) {
        Resultado += (polinomioA[i]*pow(x,gradoA-i));
    }
    return Resultado;
}
//**********************************************************************************************************************
void ImprimirPoli(const float polinomio[],int grado){
    int ValAbs;
    for (int i = 0; i < grado; ++i) {
        ValAbs = polinomio[i];
        DetPolaridad(polinomio[i]);
        if (ValAbs != 0) cout << ValAbs << "x^" << grado-i << ' ';
    }
    DetPolaridad(polinomio[grado]);
    if (polinomio[grado] != 0)cout << polinomio[grado];
    cout << endl;
}
//**********************************************************************************************************************
void DetPolaridad(float Valor)
{
    if(Valor > 0) cout << "+";
    else if (Valor > 0) cout << "-";
    else cout << "";
}
//**********************************************************************************************************************
