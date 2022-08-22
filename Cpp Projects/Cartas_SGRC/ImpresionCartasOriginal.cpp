/*
Nombre: ////.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 3/1/2020
Descripción: Este archivo solo es para tener guardado la primera versión de la impresión de las cartas.
*/

//void Carta(int Denominacion, int Palo, int x, int y) {
//
//    int PosX = x, PosY = y;
//
//    char DetPalo[2] = " ";
//    switch (Palo) {                        //Se determina la figura del palo
//        case 3:
//            EstablecerColor(BLANCO, ROJOCLARO);
//            strcpy(DetPalo, "\3");
//            break;
//        case 4:
//            EstablecerColor(BLANCO, ROJOCLARO);
//            strcpy(DetPalo, "\4");
//            break;
//        case 5:
//            strcpy(DetPalo, "\5");
//            break;
//        case 6:
//            strcpy(DetPalo, "\6");
//
//    }
//    switch (Denominacion) {
//        case 1:                       //Caso de Denominacion 1 o "A"
//
//            gotoxy(x + 1, y + 1);    //Esquina Superior
//            cout << "A";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//            gotoxy(x + 6, y + 3);   //Impresión de Figura Central
//            cout << DetPalo;
//
//            gotoxy(x+=5, y+=4);
//            for(int i = 1 ; i<=4 ; ++i){
//                cout << DetPalo;
//                gotoxy(x+2,y);
//                cout << DetPalo;
//                gotoxy(x,++y);
//            }
//            x = PosX;
//            y = PosY;
//
//            gotoxy(x+6,y+5);
//            cout << DetPalo;
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "A";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 2:                             //Caso de Denominación 2
//
//            gotoxy(x + 1, y + 1);     //Esquina Superior
//            cout << "2";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+6,y+4);          //Impresión de Figura Central
//            cout << DetPalo;
//            gotoxy(x+6,y+6);
//            cout << DetPalo;
//
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "2";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 3:                             //Caso de Denominación 3
//
//            gotoxy(x + 1, y + 1);    //Esquina Superior
//            cout << "3";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+=6,y+=3);         //Impresión de Figura Central
//            for(int i = 1; i <= 3 ; ++i){
//                cout << DetPalo;
//                gotoxy(x,y+=2);
//            }
//            x = PosX;
//            y = PosY;
//
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "3";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 4:                             //Caso de Denominación 4
//
//            gotoxy(x + 1, y + 1);     //Esquina Superior
//            cout << "4";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+=5,y+=4);        //Impresión de Figura Central
//            for(int i = 0; i <= 1 ; ++i){
//                cout << DetPalo;
//                gotoxy(x+2,y);
//                cout << DetPalo;
//                gotoxy(x,y+=2);
//            }
//            x = PosX;
//            y = PosY;
//
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "4";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 5:                             //Caso de Denominación 5
//
//            gotoxy(x + 1, y + 1);     //Esquina Superior
//            cout << "5";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+=5,y+=4);        //Impresión de Figura Central
//            for(int i = 0; i <= 1 ; ++i){
//                cout << DetPalo;
//                gotoxy(x+2,y);
//                cout << DetPalo;
//                gotoxy(x,y+=2);
//            }
//            x = PosX;
//            y = PosY;
//            gotoxy(x+6,y+5);
//            cout << DetPalo;
//
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "5";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 6:                             //Caso de Denominación 6
//
//            gotoxy(x + 1, y + 1);    //Esquina Superior
//            cout << "6";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+=5,y+=3);         //Impresión de Figura Central
//            for(int i = 1; i <= 3 ; ++i){
//                cout << DetPalo;
//                gotoxy(x+2,y);
//                cout << DetPalo;
//                gotoxy(x,y+=2);
//            }
//            x = PosX;
//            y = PosY;
//
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "6";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 7:                             //Caso de Denominación 7
//
//            gotoxy(x + 1, y + 1);    //Esquina Superior
//            cout << "7";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+=5,y+=3);         //Impresión de Figura Central
//            for(int i = 1; i <= 3 ; ++i){
//                cout << DetPalo;
//                gotoxy(x+2,y);
//                cout << DetPalo;
//                gotoxy(x,y+=2);
//            }
//            x = PosX;
//            y = PosY;
//            gotoxy(x+6,y+4);
//            cout << DetPalo;
//
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "7";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 8:                             //Caso de Denominación 8
//
//            gotoxy(x + 1, y + 1);    //Esquina Superior
//            cout << "8";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+=5,y+=3);         //Impresión de Figura Central
//            for(int i = 1; i <= 3 ; ++i){
//                cout << DetPalo;
//                gotoxy(x+2,y);
//                cout << DetPalo;
//                gotoxy(x,y+=2);
//            }
//            x = PosX;
//            y = PosY;
//            gotoxy(x+6,y+4);
//            cout << DetPalo;
//            gotoxy(x+6,y+6);
//            cout << DetPalo;
//
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "8";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 9:                             //Caso de Denominación 9
//
//            gotoxy(x + 1, y + 1);    //Esquina Superior
//            cout << "9";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+=5,y+=3);         //Impresión de Figura Central
//            for(int i = 1; i <= 3 ; ++i){
//                cout << DetPalo;
//                gotoxy(x+2,y);
//                cout << DetPalo;
//                gotoxy(x,y+=2);
//            }
//            x = PosX;
//            y = PosY;
//            x = PosX;
//            y = PosY;
//            gotoxy(x+=6,y+=4);
//            for(int i = 1; i <= 3 ; ++i){
//                cout << DetPalo;
//                gotoxy(x,++y);
//            }
//            x = PosX;
//            y = PosY;
//
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "9";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 10:                             //Caso de Denominación 10
//
//            gotoxy(x + 1, y + 1);      //Esquina Superior
//            cout << "10";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+=5,y+=3);         //Impresión de Figura Central
//            for(int i = 1; i<=5 ; ++i){
//                cout << DetPalo;
//                gotoxy(x+2,y);
//                cout<< DetPalo;
//                gotoxy(x,++y);
//            }
//            x = PosX;
//            y = PosY;
//
//            //*********************************************************
//            gotoxy(x + 10, y + 9);    //Esquina Inferior
//            cout << "10";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 11:                           //Caso de Denominación 11 o "J"
//
//            gotoxy(x + 1, y + 1);    //Esquina Superior
//            cout << "J";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+=3,y+=3);        //Impresión de Figura Central
//            for(int i = 1; i<=7 ; ++i){
//                cout << DetPalo;
//                gotoxy(++x,y);
//            }
//            x = PosX;
//            y = PosY;
//            gotoxy(x+=6,y+=4);
//            for(int i = 1; i<=3 ; ++i){
//                cout << DetPalo;
//                gotoxy(x,++y);
//            }
//            x = PosX;
//            y = PosY;
//            gotoxy(x+=4,y+=7);
//            for(int i = 1; i<=3 ; ++i){
//                cout << DetPalo;
//                gotoxy(++x,y);
//            }
//            x = PosX;
//            y = PosY;
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "J";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 12:                           //Caso de Denominación 12 o "Q"
//
//            gotoxy(x + 1, y + 1);          //Esquina Superior
//            cout << "Q";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+5,y+1);               //Impresión de Figura Central
//            cout << DetPalo;
//            gotoxy(x+7,y+1);
//            cout << DetPalo;
//
//            gotoxy(x+=4,y+=2);
//            for(int i = 1; i<=3 ; ++i){
//                cout << DetPalo;
//                gotoxy(x+=2,y);
//            }
//            x = PosX;
//            y = PosY;
//
//            gotoxy(x+=4,y+=3);
//            for(int i = 1; i<=5; ++i){
//                cout << DetPalo;
//                gotoxy(++x,y);
//            }
//            x = PosX;
//            y = PosY;
//            gotoxy(x+=4,y+=4);
//            for(int i = 1; i <=3; ++i){
//                cout << DetPalo;
//                gotoxy(x+4,y);
//                cout << DetPalo;
//                gotoxy(x,++y);
//            }
//            x = PosX;
//            y = PosY;
//            gotoxy(x+=4,y+=7);
//            for(int i = 1; i<=5; ++i){
//                cout << DetPalo;
//                gotoxy(++x,y);
//            }
//            x = PosX;
//            y = PosY;
//            gotoxy(x+7,y+6);
//            cout << DetPalo;
//            gotoxy(x+9,y+8);
//            cout << DetPalo;
//
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "Q";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//            break;
//
//        case 13:                           //Caso de Denominación 13 o "K"
//
//            gotoxy(x + 1, y + 1);    //Esquina Superior
//            cout << "K";
//            gotoxy(x + 1, y + 2);
//            cout << DetPalo;
//            //*********************************************************
//
//            gotoxy(x+5,y+1);               //Impresión de Figura Central
//            cout << DetPalo;
//            gotoxy(x+8,y+1);
//            cout << DetPalo;
//
//            gotoxy(x+=5,y+=2);
//            for(int i = 1; i<=4 ; ++i){
//                cout << DetPalo;
//                gotoxy(++x,y);
//            }
//            x = PosX;
//            y = PosY;
//
//            gotoxy(x+=5,y+=3);
//            for(int i = 1; i <=5; ++i){
//                cout << DetPalo;
//                gotoxy(x,++y);
//            }
//            x = PosX;
//            y = PosY;
//
//            gotoxy(x+8,y+3);
//            cout << DetPalo;
//            gotoxy(x+7,y+4);
//            cout << DetPalo;
//            gotoxy(x+6,y+5);
//            cout << DetPalo;
//            gotoxy(x+7,y+6);
//            cout << DetPalo;
//            gotoxy(x+8,y+7);
//            cout << DetPalo;
//
//            //*********************************************************
//            gotoxy(x + 11, y + 9);    //Esquina Inferior
//            cout << "K";
//            gotoxy(x + 11, y + 8);
//            cout << DetPalo;
//    }
//}
