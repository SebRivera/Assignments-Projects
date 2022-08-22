/*
Nombre: Conjuntos.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/14/2020
Descripción: Archivo que contiene las funciones relacionadas con los conjuntos.
*/
#include <iostream>
#include "Conjuntos.h"

using namespace std;

//**********************************************************************************************************************
void CapturarCon(char conjunto[], int cardinalidad)
{
    bool EstaRepetido;
    cout << "NOTA: Evite ingresar dos o mas characteres a la vez..." << endl;
    for (int i = 0; i < cardinalidad; ) {
        cout << "Ingrese el elemento #" << i+1 << "(Sin Repeticiones): ";
        cin >> conjunto[i];

        EstaRepetido = PerteneceAlConjunto(conjunto, i, conjunto[i]);
        if(!EstaRepetido) ++i;
        else cout << "\nEste elemento ya est\240 en el conjunto..." << endl;
    }
}
//**********************************************************************************************************************
bool PerteneceAlConjunto(const char conjunto[], int cardinalidad, char valor)
{
    for(int i = 0; i < cardinalidad; ++i)
        if(valor == conjunto[i]) return true;
    return false;
}
//**********************************************************************************************************************
void ImprimirCon(const char conjunto[], int cardinalidad, const char nombreCon[])
{
    if(cardinalidad != 0) {
        cout << nombreCon << '{';
        for (int i = 0; i < cardinalidad; ++i) cout << conjunto[i] << ", ";
        cout << "\b\b}" << endl;
    }else cout << nombreCon << "{ }" << endl;
}
//**********************************************************************************************************************
int UnionCon(const char conjuntoA[], const char conjuntoB[], char conjuntoR[], int cardA, int cardB)
{
    bool EstaRepetido;
    int Rep = 0;
    for(int i = 0; i <= cardA; ++i) conjuntoR[i]=conjuntoA[i];
    for(int i = 0; i <= cardB; ++i) {
        EstaRepetido = PerteneceAlConjunto(conjuntoA, cardA, conjuntoB[i]);
        if(!EstaRepetido)conjuntoR[cardA + i - Rep]=conjuntoB[i];
        else Rep += 1;
    }
    return Rep;
}
//**********************************************************************************************************************
void InterCon(const char conjuntoA[], const char conjuntoB[], char conjuntoR[], int cardA, int cardB, int &cardR)
{
    for(int i = 0; i < cardA; ++i){
        for(int j = 0; j < cardB; ++j) {
            if (conjuntoA[i] == conjuntoB[j]){
                conjuntoR[cardR++] = conjuntoA[i];
                break;
            }
        }
    }
}
//**********************************************************************************************************************
void DiferenciaCon(const char conjuntoA[], const char conjuntoB[], char conjuntoR[], int cardA, int cardB, int &cardR)
{
    bool EstaRepetido;
    for(int i = 0; i < cardA; ++i){
        EstaRepetido = false;
        for(int j = 0; j < cardB; ++j) {
            if (conjuntoA[i] == conjuntoB[j]){
                EstaRepetido = true;
                break;
            }
        }
        if(!EstaRepetido) conjuntoR[cardR++] = conjuntoA[i];
    }
}
//**********************************************************************************************************************


