/*
Nombre: Utilerias.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/14/2020
Descripción: Archvivo que contiene las funciones de utilerias.
*/

#include <iostream>
#include <iomanip>

#include "Utilerias.h"
#include <windows.h>

using namespace std;
//**********************************************************************************************************************
int Menu()
{
    int Op;
    cout << "0)Salir" << endl;
    cout << "1)M\202todo de Burbuja" << endl;
    cout << "2)M\202todo de Selecci\242n" << endl;
    cout << "3)M\202todo de Inserci\242n" << endl;
    cout << "4)M\202todo de QuickSort" << endl;
    cout << "5)M\202todo de MergeSort" << endl;
    do {
        CapturaSegura(Op, "Elija Opci\242n: ");
        if(Op <0 || Op >5) cout << "Fuera de Rango..." << endl;
    }while (Op <0 || Op >5);
    cout << endl;
    return Op;
}
//**********************************************************************************************************************
int SubMenu()
{
    int Op;
    cout << "1)Ingresar Manualmente" << endl;
    cout << "2)Generados al Azar" << endl;
    do {
        CapturaSegura(Op, "Eliga Opcion: ");
        if(Op <1 || Op >2) cout << "Fuera de Rango..." << endl;
    }while (Op <1 || Op >2);
    cout << endl;
    return Op;
}
//**********************************************************************************************************************

int CapMAX(int tamano)
{
    int Valor;
    do{
        cout << "(Rango 1-" << tamano << ')';
        CapturaSegura(Valor," tama\244o: ");
    }while(Valor < 0 || Valor > tamano);
    return Valor;
}
//**********************************************************************************************************************
int * CrearArreglo(int tamano)
{
    return new int [tamano];
}
//**********************************************************************************************************************
void EliminarArreglo(int *&arreglo)
{
    delete [] arreglo;
    arreglo = NULL;
}
//**********************************************************************************************************************
void Histograma(int *arreglo ,int largo ,int alturaMax ,char caracter)
{
    for(int alt = 0; alt < alturaMax; alt++)
    {
        cout << '\t';
        for(int i = 0; i < largo; i++)
        {
            cout << setw(2);
            if(alturaMax - alt > arreglo[i]) cout << ' ';
            else cout << caracter;
        }
        cout << '\n';
    }
}
//**********************************************************************************************************************
void gotoxy(short x,short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x,y};
    SetConsoleCursorPosition(handle,coord);
}
//**********************************************************************************************************************
void TamVentana(int Ancho, int Alto)
{
    _COORD coord;
    coord.X = Ancho;
    coord.Y = Alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Alto - 1;
    Rect.Right = Ancho - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}
//**********************************************************************************************************************
void CambiaCursor(estadoCursor estado, modoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}
//**********************************************************************************************************************

