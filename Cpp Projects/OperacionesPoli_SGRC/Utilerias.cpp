/*
Nombre: OUtilerias.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/19/2020
Descripción: Archvivo que contiene las funciones de utilerias.
*/
#include <iostream>
#include "Utilerias.h"

//**********************************************************************************************************************
int Menu()
{
    int Op;
    cout << "0)Salir" << endl;
    cout << "1)Suma de Dos Polinomios" << endl;
    cout << "2)Resta de Dos Polinomios" << endl;
    cout << "3)Multiplicaci\242n de Dos Polinomios" << endl;
    cout << "4)Divisi\242n de Dos Polinomios (A/B)" << endl;
    cout << "5)Derivada de un Polinomio" << endl;
    cout << "6)Evaluaci\242n de un Polinomio" << endl;

    do {
        CapturaSegura(Op, "Elija Opcion: ");
        if(Op <0 || Op >6) cout << "Fuera de Rango..." << endl;
    }while (Op <0 || Op >6);
    cout << endl;
    return Op;
}
//**********************************************************************************************************************
int CapGrado()
{
    int Grd;
    do{
        cout << "(Rando 1-" << TAM_MAX << ')';
        CapturaSegura(Grd,"Grado: ");
    }while(Grd < 0 || Grd > TAM_MAX);
    return Grd;
}
//**********************************************************************************************************************

