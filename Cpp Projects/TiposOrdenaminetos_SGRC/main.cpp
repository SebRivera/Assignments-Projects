/*
Nombre: TiposOrdenaminetos_SGRC.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/26/2020
Descripción: Programa que ordena los valores de un arreglo mediante 5 métodos e imprime paso a paso cada cambio en
                formato de histograma.
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <cstdio>

#include "Utilerias.h"
#include "MetodosOrdenamiento.h"


int Menu();

using namespace std;
int main() {
    int Opcion, SubOpcion, Tamano;
    char Caracter;
    TamVentana(155,40);

    do {
        cout << "Programa que permite ordenar un conjunto de n\243meros desordenados presentados por un histograma." << endl;
        Opcion = Menu();
        if (Opcion == 0) {
            system("pause");
            return 0;
        }
        cout << "Ingrese la cantidad de n\243meros a ordenar (Tama\244o)..." << endl;
        Tamano = CapMAX(TAM_MAX);

        cout << "Ingrese el car\240cter del histograma: " << endl;
        cin >> Caracter;

        cout << "\250Desea ingresar los n\243meros de manera manual o generados al azar?" << endl;
        SubOpcion = SubMenu();
        try {
            int *Arreglo = CrearArreglo(Tamano);
            if (SubOpcion == 1) { // Manual
                char Solicitud[40];
                for (int i = 0; i < Tamano; ++i) {
                    sprintf(Solicitud, "Ingrese el elemento #%d (Rango 1-%d): ", i + 1, ALTURA_MAX);
                    do {
                        CapturaSegura(Arreglo[i], Solicitud);
                        if (Arreglo[i] < 1 || Arreglo[i] > ALTURA_MAX) cout << "Fuera de Rango..." << endl;
                    } while (Arreglo[i] < 1 || Arreglo[i] > ALTURA_MAX);
                }
            } else {  // Aleatorio
                srand(time(NULL));
                for (int i = 0; i < Tamano; ++i) {
                    Arreglo[i] = (rand() % 20) + 1;
                }
            }

            CambiaCursor(APAGADO, NORMAL);
            Histograma(Arreglo, Tamano, ALTURA_MAX, Caracter);
            system("cls");
            switch (Opcion) {
                case BURBUJA :
                    cout << "M\202todo de Burbuja";
                    Burbuja(Arreglo, Tamano, Caracter);
                    break;
                case SELECCION :
                    cout << "M\202todo de Selecci\242n";
                    Seleccion(Arreglo, Tamano, Caracter);
                    break;
                case INSERCION :
                    cout << "M\202todo de Inserci\242n";
                    Insercion(Arreglo, Tamano, Caracter);
                    break;
                case QUICKSORT :
                    cout << "M\202todo de QuickSort";
                    QuickSort(Arreglo, 0, Tamano - 1, Tamano, Caracter);
                    break;
                case MERGESORT :
                    cout << "M\202todo de MergeSort";
                    MergeSort(Arreglo, Tamano, Tamano, Caracter);
            }
            gotoxy(0, 2);
            Histograma(Arreglo, Tamano, ALTURA_MAX, Caracter);
            system("pause");

            CambiaCursor(ENCENDIDO, NORMAL);
            EliminarArreglo(Arreglo);
            system("cls");
        }catch(bad_alloc &){
            cout << "Error en la asignaci\242n de memoria..." << endl;
        }catch (...){
            cout << "Ocurri\242 un error inesperado" << endl;
        }
    }while(Opcion !=0);
}


