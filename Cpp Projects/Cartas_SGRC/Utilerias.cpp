/*mo
Nombre: Utilerias.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 2/28/2020
Descripción: Funciones denominadas como utilierias, ya que realizan acciones como cambiar el tamaño de la ventana,
                establecer el color de fondo y texto, ir a una posicion en x,y y cambiar el estado del  cursor.
*/
#include <iostream>
#include "Utilerias.h"
#include <windows.h>

using std::cout;
using std::endl;

//***************************************************
void Marco(int Ancho,int Alto, int x, int y)
{
    gotoxy(x,y);
    cout << char(ESQUINASUPI);
    for(int BH = 1 ; BH <= Ancho-2 ; ++BH) cout << char(BARRAH);
    cout << char(ESQUINASUPD) << endl;

    for(int Fila = 1 ; Fila <= Alto-2 ; ++Fila){
        gotoxy(x,++y);
        cout << char(BARRAV);
        for(int Esp = 1 ; Esp <= Ancho-2 ; ++Esp) cout << " ";
        cout << char(BARRAV) << endl;
    }

    gotoxy(x,++y);
    cout << char(ESQUINAINFI);
    for(int BH = 1 ; BH <= Ancho-2 ; ++BH) cout << char(BARRAH);
    cout << char(ESQUINAINFD) << endl;
}
//***************************************************
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

//***************************************************
void EstablecerColor(Color colorFondo, Color colorTexto)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorFondo*16 + colorTexto);
}

//***************************************************
void gotoxy(short x,short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x,y};
    SetConsoleCursorPosition(handle,coord);
}

//***************************************************
void CambiaCursor(estadoCursor estado, modoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}
