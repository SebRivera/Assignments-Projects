/*
Nombre: main.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/14/2020
Descripción: Programa modular que calcula las operaciones básicas entre conjuntos.
*/
#include <iostream>
#include <cstdlib>

#include "Utilerias.h"
#include "Conjuntos.h"

using namespace std;

int main()
{
    int Opcion;
    cout << "Programa que permite realizar las operaci\242nes basicasde conjuntos" << endl;
    do {
        Opcion = Menu();
        if (Opcion == 0) {
            system("pause");
            return 0;
        }

        char ConjuntoA[TAM_MAX], ConjuntoB[TAM_MAX], Universo[TAM_MAX];
        int CardA, CardB, CardU;
        switch(Opcion){
            case UNION:
            case INTERSECCION:
            case DIFERENCIA:
            case CONTENENCIA:
                cout << "Primero: Ingrese la cardinalidad del conjunto A... " << endl;
                CardA = CapCardinalidad();
                cout << endl;
                cout << "Ahora ingrese los elementos del conjunto A." << endl;
                CapturarCon(ConjuntoA, CardA);
                cout << endl;

                cout << "Segundo: Ingrese la cardinalidad del conjunto B..." << endl;
                CardB = CapCardinalidad();
                cout << endl;
                cout << "Ahora ingrese los elementos del conjunto B." << endl;
                CapturarCon(ConjuntoB, CardB);
                cout << endl;
                break;
            case COMPLEMENTO:
                cout << "Primero: Ingrese la cardinalidad del Universo..." << endl;
                CardU = CapCardinalidad();
                cout << endl;
                cout << "Ahora ingrese los elementos del Universo." << endl;
                CapturarCon(Universo, CardU);
                cout << endl;
                break;
            case PERTENENCIA:
                cout << "Ingrese la cardinalidad del conjunto..."  << endl;
                CardA = CapCardinalidad();
                cout << endl;
                cout << "Ahora ingrese los elementos del conjunto." << endl;
                CapturarCon(ConjuntoA, CardA);
        }

        switch(Opcion){
            case UNION: {
                int CardR = CardA + CardB;
                char ConjuntoR[TAM_MAX * 2];
                int Rep = UnionCon(ConjuntoA, ConjuntoB, ConjuntoR, CardA, CardB);
                ImprimirCon(ConjuntoA, CardA, "Conjunto A: ");
                ImprimirCon(ConjuntoB, CardB, "Conjunto B: ");
                ImprimirCon(ConjuntoR, CardR - Rep, "Conjunto Resultante: ");
                system("pause");
                break;
            }
            case INTERSECCION: {
                char ConjuntoR[TAM_MAX];
                int CardR = 0;
                InterCon(ConjuntoA, ConjuntoB, ConjuntoR, CardA, CardB, CardR);
                ImprimirCon(ConjuntoA, CardA, "Conjunto A: ");
                ImprimirCon(ConjuntoB, CardB, "Conjunto B: ");
                ImprimirCon(ConjuntoR, CardR, "Conjunto Resultante: ");
                system("pause");
                break;
            }
            case DIFERENCIA: {
                char ConjuntoR[TAM_MAX];
                int CardR = 0;
                DiferenciaCon(ConjuntoA, ConjuntoB, ConjuntoR, CardA, CardB, CardR);
                ImprimirCon(ConjuntoA, CardA, "Conjunto A: ");
                ImprimirCon(ConjuntoB, CardB, "Conjunto B: ");
                ImprimirCon(ConjuntoR, CardR, "Conjunto Resultante: ");
                system("pause");
                break;
            }
            case CONTENENCIA: {
                char ConjuntoR[TAM_MAX];
                int CardR = 0;
                DiferenciaCon(ConjuntoB, ConjuntoA, ConjuntoR, CardB, CardA, CardR);
                ImprimirCon(ConjuntoA, CardA, "Conjunto A: ");
                ImprimirCon(ConjuntoB, CardB, "Conjunto B: ");
                if(CardR == 0)
                    cout << "El conjunto B si est\240 contenido en A" << endl;
                else
                    cout << "El conjunto B no est\240 contenido en A" << endl;
                system("pause");
                break;
            }
            case COMPLEMENTO: {
                char ConjuntoR[TAM_MAX];
                int Eleccion;

                do{
                    int CardR = 0;
                    cout << "Ingrese la cardinalidad del conjunto ..." << endl;
                    CardA = CapCardinalidad();

                    cout << "Ahora ingrese los elementos del conjunto." << endl;
                    CapturarCon(ConjuntoA, CardA);
                    cout << endl;

                    ImprimirCon(Universo, CardU, "Universo: ");
                    ImprimirCon(ConjuntoA, CardA, "Conjunto A: ");
                    DiferenciaCon(ConjuntoA, Universo, ConjuntoR, CardA, CardU, CardR);
                    if( CardR == 0){
                        DiferenciaCon(Universo, ConjuntoA, ConjuntoR, CardU, CardA, CardR);
                        cout << "El complemento del conjunto A con respecto al universo es:" << endl;
                        ImprimirCon(ConjuntoR, CardR, "CardR: ");
                    }
                    else
                        cout << "El conjunto A no es un subconjunto del universo." << endl;
                    system("pause");

                    cout << "\250Desea ingresar un nuevo conjunto?" << endl;
                    cout << "0) No." << endl;
                    cout << "1) Si." << endl;
                    do {
                        CapturaSegura(Eleccion, "Eliga Opcion: ");
                        if(Eleccion != 0 && Eleccion != 1) cout << "Fuera de Rango..." << endl;
                    }while(Eleccion != 0 && Eleccion != 1);
                }while(Eleccion != 0);
                system("pause");
                break;
            }
            case PERTENENCIA:{
                int Elemento;
                int Eleccion;
                do {
                    cout << "Ingrese el elemento que desee buscar dentro del conjunto: ";
                    cin >> Elemento;
                    cout << endl;
                    ImprimirCon(ConjuntoA, CardA, "CardA: ");
                    cout << endl << "Elemento: " << Elemento;
                    if (PerteneceAlConjunto(ConjuntoA, CardA, Elemento))
                        cout << "Su elemento si pertenece al conjunto" << endl;
                    else
                        cout << "Su elemento no pertenece al conjunto" << endl;

                    cout << "\250Desea ingresar un nuevo elemento?" << endl;
                    cout << "0) No." << endl;
                    cout << "1) Si." << endl;
                    do {
                        CapturaSegura(Eleccion, "Eliga Opcion: ");
                        if (Eleccion != 0 && Eleccion != 1) cout << "Fuera de Rango..." << endl;
                    } while (Eleccion != 0 && Eleccion != 1);
                }while(Eleccion !=0);
                system("pause");
            }
        }
        system("cls");
    }while(Opcion != 0);
}



