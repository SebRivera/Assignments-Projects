/*
Nombre: OperacionesMatrices_SGRC.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 5/18/2020
Descripción: Plantilla que contiene la función de captura segura.
*/

#include <iostream>
#include <limits>

#include "Utilerias.h"

template <typename TIPO>
void CapturaSegura(TIPO &n, const char solicitud[])
{
    while(true){
        std::cout << solicitud;
        std::cin >> n;

        if(std::cin.bad()) throw " Error irrecuperable en el flujo de entrada";

        if(std::cin.fail()){
            std::cout << " El valor introducido no es un n\243mero\n" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        break;
    }
}