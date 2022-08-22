/*
Nombre: ImpresionCartas.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 2/28/2020
Descripción: Funciones en donde se imprime el relleno de la carta,
*/
#include <iostream>
#include <cstring>

#include "ImpresionCartas.h"
#include "Utilerias.h"

using std::cout;

void Carta(int Denominacion, int Palo, int x, int y) {

    int PosX = x, PosY = y;
    int DivAncho = ANCHO/2, DivAlto = ALTO/2;
    char DetPalo[2] = " ";

    switch (Palo) {                        //Se determina la figura del palo
        case CORAZON:
            EstablecerColor(BLANCO, ROJOCLARO);
            strcpy(DetPalo, "\3");
            break;

        case DIAMANTE:
            EstablecerColor(BLANCO, ROJOCLARO);
            strcpy(DetPalo, "\4");
            break;

        case TREBOL:
            strcpy(DetPalo, "\5");
            break;

        case PICAS:
            strcpy(DetPalo, "\6");
    }

    switch (Denominacion) {
        case AS:
            gotoxy(x + 1, y + 1); cout << "A";
            gotoxy(x + 1, y + 2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-3); cout << "A";
            break;

        case 10:
            gotoxy(x + 1, y + 1); cout << "10";
            gotoxy(x + 1, y + 2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-2); cout << DetPalo;
            gotoxy(x+ANCHO-3, y+ALTO-3); cout << "10";
            break;
        case JACK:
            gotoxy(x + 1, y + 1); cout << "J";
            gotoxy(x + 1, y + 2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-3); cout << "J";
            break;

        case REINA:
            gotoxy(x + 1, y + 1); cout << "Q";
            gotoxy(x + 1, y + 2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-3); cout << "Q";
            break;

        case REY:
            gotoxy(x + 1, y + 1); cout << "K";
            gotoxy(x + 1, y + 2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-3); cout << "K";
            break;

        default:
            gotoxy(x + 1, y + 1); cout << Denominacion;
            gotoxy(x + 1, y + 2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-2); cout << DetPalo;
            gotoxy(x+ANCHO-2, y+ALTO-3); cout << Denominacion;
    }

    switch (Denominacion){
        case AS:
            gotoxy(x+(DivAncho),y+(DivAlto)-2); cout << DetPalo;
            gotoxy(x+=(DivAncho)-1,y+=(DivAlto)-1);
            for(int i = 1 ; i<=4 ; ++i){
                cout << DetPalo; gotoxy(x+2,y);
                cout << DetPalo; gotoxy(x,++y);
            }
            x = PosX; y = PosY;
            gotoxy(x+(DivAncho),y+(DivAlto)); cout << DetPalo;
            break;

        case 2:
            gotoxy(x+DivAncho,y+DivAlto-1); cout << DetPalo;
            gotoxy(x+DivAncho,y+DivAlto+1); cout << DetPalo;
            break;

        case 3:
            gotoxy(x+DivAncho,y+DivAlto-1); cout << DetPalo;
            gotoxy(x+DivAncho,y+DivAlto); cout << DetPalo;
            gotoxy(x+DivAncho,y+DivAlto+1); cout << DetPalo;
            break;

        case 4:
            gotoxy(x+=DivAncho-1, y+=DivAlto-1);
            for(int i = 1; i<=2; ++i){
               cout << DetPalo;
               gotoxy(x+2,y); cout << DetPalo;
               gotoxy(x,y+=2);
            }
            x = PosX; y = PosY;
            break;

        case 5:
            gotoxy(x+=DivAncho-1, y+=DivAlto-1);
            for(int i = 1; i<=2; ++i){
                cout << DetPalo;
                gotoxy(x+2,y); cout << DetPalo;
                gotoxy(x,y+=2);
            }
            x = PosX; y = PosY;
            gotoxy(x+DivAncho,y+DivAlto); cout << DetPalo;
            break;

        case 6:
            gotoxy(x+=DivAncho-1, y+=DivAlto-2);
            for(int i = 1; i<=3; ++i){
                cout << DetPalo;
                gotoxy(x+2,y); cout << DetPalo;
                gotoxy(x,y+=2);
            }
            x = PosX; y = PosY;
            break;

        case 7:
            gotoxy(x+=DivAncho-1, y+=DivAlto-2);
            for(int i = 1; i<=3; ++i){
                cout << DetPalo;
                gotoxy(x+2,y); cout << DetPalo;
                gotoxy(x,y+=2);
            }
            x = PosX; y = PosY;
            gotoxy(x+DivAncho,y+DivAlto-1); cout << DetPalo;
            break;

        case 8:
            gotoxy(x+=DivAncho-1, y+=DivAlto-2);
            for(int i = 1; i<=3; ++i){
                cout << DetPalo;
                gotoxy(x+2,y); cout << DetPalo;
                gotoxy(x,y+=2);
            }
            x = PosX; y = PosY;
            gotoxy(x+DivAncho,y+DivAlto-1); cout << DetPalo;
            gotoxy(x+DivAncho,y+DivAlto+1); cout << DetPalo;
            break;

        case 9:
            gotoxy(x+=DivAncho-1, y+=DivAlto-2);
            for(int i = 1; i<=3; ++i){
                cout << DetPalo;
                gotoxy(x+2,y); cout << DetPalo;
                gotoxy(x,y+=2);
            }
            x = PosX; y = PosY;
            gotoxy(x+DivAncho,y+DivAlto-1); cout << DetPalo;
            gotoxy(x+DivAncho,y+DivAlto+1); cout << DetPalo;
            gotoxy(x+DivAncho,y+DivAlto); cout << DetPalo;
            break;

        case 10:
            gotoxy(x+=DivAncho-1,y+=DivAlto-2);
            for(int i= 1; i<=5; ++i){
                cout << DetPalo;
                gotoxy(x+2,y); cout << DetPalo;
                gotoxy(x,++y);
            }
            x = PosX; y = PosY;
            break;

        case JACK:
            gotoxy(x+=DivAncho-2,y+=DivAlto-2);
            for(int i = 1; i<=5; ++i){
                cout << DetPalo; gotoxy(++x,y);
            }
            x = PosX; y = PosY;
            gotoxy(x+=DivAncho,y+=DivAlto-1);
            for(int i = 1; i<=4; ++i){
                cout << DetPalo; gotoxy(x,++y);
            }
            x = PosX; y = PosY;
            gotoxy(x+DivAncho-2,y+DivAlto+2); cout << DetPalo;
            gotoxy(x+DivAncho-1,y+DivAlto+2); cout << DetPalo;
            break;

        case REINA:
            gotoxy(x+=DivAncho-2,y+=DivAlto-3);
            for(int i = 1; i<=5; ++i){
                cout << DetPalo;
                if(i%2 != 0)gotoxy(++x,--y);
                else gotoxy(++x,++y);
            }
            x = PosX; y = PosY;
            gotoxy(x+=DivAncho-2,y+=DivAlto-2);
            for(int i = 1; i<=5; ++i){
                cout << DetPalo; gotoxy(++x,y);
            }
            x = PosX; y = PosY;
            gotoxy(x+=DivAncho-2,y+=DivAlto-1);
            for(int i = 1; i<=3; ++i){
                cout << DetPalo;
                gotoxy(x+4,y);cout << DetPalo;
                gotoxy(x,++y);
            }
            x = PosX; y = PosY;
            gotoxy(x+=DivAncho-2,y+=DivAlto+2);
            for(int i = 1; i<=5; ++i){
                cout << DetPalo; gotoxy(++x,y);
            }
            x = PosX; y = PosY;
            gotoxy(x+DivAncho+1,y+DivAlto+1); cout << DetPalo;
            gotoxy(x+DivAncho+3,y+DivAlto+3); cout << DetPalo;
            break;

        case REY:
            gotoxy(x+=DivAncho-2,y+=DivAlto-2); cout << DetPalo;
            for(int i = 1; i<=5; ++i){
                cout << DetPalo; gotoxy(++x,y);
            }
            x = PosX; y = PosY;
            gotoxy(x+DivAncho-1,y+DivAlto-3); cout << DetPalo;
            gotoxy(x+DivAncho,y+DivAlto-4); cout << DetPalo;
            gotoxy(x+DivAncho+1,y+DivAlto-3); cout << DetPalo;
            gotoxy(x+=DivAncho-2,y+=DivAlto-1);
            for(int i = 1; i<=5; ++i){
                cout << DetPalo; gotoxy(x,++y);
            }
            x = PosX; y = PosY;
            gotoxy(x+DivAncho,y+DivAlto+1); cout << DetPalo;
            gotoxy(x+DivAncho+1,y+DivAlto); cout << DetPalo;
            gotoxy(x+DivAncho+1,y+DivAlto+2); cout << DetPalo;
            gotoxy(x+DivAncho+2,y+DivAlto-1); cout << DetPalo;
            gotoxy(x+DivAncho+2,y+DivAlto+3); cout << DetPalo;
    }
}