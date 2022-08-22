/*
Nombre: main.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 24 de Febrero de 2020
Descripción: Programa que imprime cartas inglesas al azar cuando el usuario pulse cualquier tecla, y al presionar la tecla Escape, se termina el programa.
*/

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>

#include "Utilerias.h"
#include "ImpresionCartas.h"

#define ESCAPE 27

using std::cout;
using std::endl;

int main()
{
    system("color 2f");
    char Tecla;
    int x=5, y=5, AuxX=x;

    TamVentana(200,38);
    CambiaCursor(APAGADO);

    srand(time(NULL));

    do{
           if(kbhit()){
               Tecla = getch();
               if(Tecla == ESCAPE) break;
               EstablecerColor(BLANCO,NEGRO);
               if(x>=138){
                   x=5;
                   y=5;
                   AuxX=x;
               }
               if(y==24){
                   x= AuxX+2;
                   y=5;
                   AuxX= x;
               }
               Marco(ANCHO,ALTO,x+=2,++y);
               Carta(rand() % 13 + 1,rand() % 4 + 3,x,y);
           }
    }while(Tecla != ESCAPE);
    system("pause");
    return 0;
}