/*
Nombre: Utilerias.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/14/2020
Descripción: Archvivo que contiene las funciones de utilerias.
*/

#include <iostream>

#include "Utilerias.h"

using namespace std;
//**********************************************************************************************************************
int Menu()
{
    int Op;
    cout << "0)Salir" << endl;
    cout << "1)Union de Dos Conjuntos" << endl;
    cout << "2)Intersecci\242n de Dos Conjuntos" << endl;
    cout << "3)Diferencia de Dos Conjuntos:" << endl;
    cout << "4)Contenencia de un Conjunto en Otro (B en A):" << endl;
    cout << "5)Complemento de un Conjunto (Respecto al Universo Dado):" << endl;
    cout << "6)Pertenencia de un Elemento a un Conjunto:" << endl;

    do {
        CapturaSegura(Op, "Eliga Opcion: ");
        if(Op <0 || Op >6) cout << "Fuera de Rango..." << endl;
    }while (Op <0 || Op >6);
    cout << endl;
    return Op;
}
//**********************************************************************************************************************
int CapCardinalidad()
{
    int Dim;
    do{
        cout << "(Rando 1-" << TAM_MAX << ')';
        CapturaSegura(Dim,"Cardinalidad: ");
    }while(Dim < 0 || Dim > TAM_MAX);
    return Dim;
}
//**********************************************************************************************************************

