/*
Nombre: main.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 06/03/2021
Descripción: Programa que pemrite simular un banco utilizando la clase Banco.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "Banco.h"
#include "Utilerias.h"

using namespace std;
int main() {
    srand (time(NULL));
    Banco bancoR("Archivos/Nombres.txt", "Archivos/Apellidos.txt");
    int duracion;
    bancoR.imprimirLogo();
    cout << endl;
    cout << "Bienvenido a la simulaci\242n del Riviera Bank" << endl;
    cout << endl;
    cout << "\250Cu\240ntos minutos (M\241nimo 60 min) desea que dure la jornada?  (1 minuto = 1 segundo)" << endl;
    do {
        CapturaSegura(duracion, "Ingrese el tiempo: ");
        if (duracion < 60) cout << "Fuera de rango..." << endl;
    } while (duracion < 60);
    system("cls");

    bancoR.asignarTiempoTotal(duracion);
    int nuevoCliente;
    int cajaCerrada = 10 + rand() % 11;
    do {
        nuevoCliente = 1 + rand() % 100;
        if (nuevoCliente >= 82) bancoR.agregarCliente();
        if (cajaCerrada >= 0) {
            bancoR.imprimirBanco();
            cajaCerrada--;
            Sleep(1000);
            system("cls");
            bancoR.decrementarTiempoTotal();
            continue;
        }else{
            bancoR.abrirCaja();
        }
        if (!bancoR.estaOcupado()){
            bancoR.atenderCliente();
            bancoR.asignarTiempoAsignadoClienteActual(5 + rand() % 16);
        }else{
            bancoR.decrementarTiempoAsignadoClienteActual();
            bancoR.aumentarTiempoEnAtencion();
        }

        if(bancoR.obtenerTiempoAsignadoClienteActual() == 0){
            bancoR.terminarCliente();
            bancoR.reiniciarTiempoEnAtencion();
        }
        bancoR.imprimirBanco();
        Sleep(1000);
        system("cls");
        bancoR.decrementarTiempoTotal();
    }while(bancoR.obtenerTiempoTotal() != 0);
    if (bancoR.estaOcupado()){
        bancoR.terminarCliente();
    }
    bancoR.imprimirReporteBanco();
    system("pause");
    return 0;
}


