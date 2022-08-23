/*
Nombre: MetodosOrdenamineto.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/26/2020
Descripción: Archivo que contiene todos las funciones de los métodos de ordenamineto.
*/

#include <iostream>
#include <windows.h>

#include "MetodosOrdenamiento.h"
#include "Utilerias.h"

using namespace std;

//**********************************************************************************************************************
void Intercambiar(int arreglo[], int indiceA, int indiceB)
{
    int Aux;
    Aux = arreglo[indiceA];
    arreglo[indiceA] = arreglo[indiceB];
    arreglo[indiceB] = Aux;
}
//**********************************************************************************************************************
void Burbuja(int arreglo[], int tamano, char caracter)
{
    bool EstaOrdenado = false;
    int temporal;

    for(int i=1; i < tamano && !EstaOrdenado; ++i){
        EstaOrdenado = true;
        for(int j=0; j < tamano - i; ++j){
            if(arreglo[j]>arreglo[j+1]){
                Intercambiar(arreglo, j, j+1);

                EstaOrdenado = false;
                gotoxy(0,2);
                Histograma(arreglo,tamano,ALTURA_MAX,caracter);
                Sleep(200);
            }
        }
    }
}
//**********************************************************************************************************************
void Seleccion(int arreglo[], int tamano, char caracter)
{
    int Menor, Mayor = tamano - 1;
    for(int i = 0; i < Mayor; ++i){
        Menor = i;
        for(int j = i+1; j < tamano; ++j){
            if(arreglo[j] < arreglo[Menor]) Menor = j;
        }
        if(Menor != i) {
            Intercambiar(arreglo, i, Menor);

            gotoxy(0,2);
            Histograma(arreglo,tamano,ALTURA_MAX,caracter);
            Sleep(200);
        }
    }
}
//**********************************************************************************************************************
void Insercion(int arreglo[], int tamano, char caracter)
{
    int Temporal, j;
    for(int i = 1; i < tamano; ++i){
        Temporal = arreglo[i];
        for(j= i-1; j >= 0; --j){
            if(arreglo[j] > Temporal) {
                arreglo[j+1] = arreglo[j];

                gotoxy(0,2);
                Histograma(arreglo,tamano,ALTURA_MAX,caracter);
                Sleep(200);
            }
            else break;
        }
        arreglo[j+1] = Temporal;

        gotoxy(0,2);
        Histograma(arreglo,tamano,ALTURA_MAX,caracter);
        Sleep(200);
    }
}
//**********************************************************************************************************************
void QuickSort(int *arreglo, int izq, int der, int tamano, char caracter)
{
    int i = izq, j = der, Pivote = arreglo[(izq+der)/2];

    while(i <= j){
        while(arreglo[i] < Pivote) i++;
        while(arreglo[j] > Pivote) j--;

        if(i <= j){
            Intercambiar(arreglo, i, j);

            gotoxy(0,2);
            Histograma(arreglo,tamano,ALTURA_MAX,caracter);
            Sleep(500);

            i++, j--;
        }
    }
    if(izq < j) QuickSort(arreglo, izq, j, tamano, caracter);
    if(i < der) QuickSort(arreglo, i, der, tamano, caracter);
}
//**********************************************************************************************************************
void Merge(int *arreglo, int *izq,int Izq,int *der,int Der, int tamano, char caracter)
{
    int i=0, j=0, k=0;
    while((i < Izq) && (j < Der)){
        if( izq[i] <= der[j]){
            arreglo[k] = izq[i];

            gotoxy(0,2);
            Histograma(arreglo,tamano,ALTURA_MAX,caracter);
            Sleep(500);

            i++;
        }else{
            arreglo[k] = der[j];

            gotoxy(0,2);
            Histograma(arreglo,tamano,ALTURA_MAX,caracter);
            Sleep(500);

            j++;
        }
        k++;
    }
    while(i < Izq){
        arreglo[k] = izq[i];

        gotoxy(0,2);
        Histograma(arreglo,tamano,ALTURA_MAX,caracter);
        Sleep(500);

        i++; k++;
    }
    while(j < Der){
        arreglo[k] = der[j];

        gotoxy(0,2);
        Histograma(arreglo,tamano,ALTURA_MAX,caracter);
        Sleep(500);

        j++; k++;
    }
}
//**********************************************************************************************************************
void MergeSort(int *arreglo, int tamano, int tamanoH, char caracter)
{
    if(tamano == 1) return;
    int Mitad = tamano / 2, *izq = CrearArreglo(Mitad), *der = CrearArreglo(tamano-Mitad);

    for(int i = 0; i < Mitad; i++) izq[i] = arreglo[i];
    for(int i = Mitad; i < tamano; i++) der[i-Mitad] = arreglo[i];

    MergeSort(izq, Mitad, tamanoH, caracter);
    MergeSort(der, tamano-Mitad, tamanoH, caracter);
    Merge(arreglo, izq, Mitad, der, tamano-Mitad, tamanoH, caracter);

    EliminarArreglo(izq);
    EliminarArreglo(der);
}
//**********************************************************************************************************************