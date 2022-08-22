/*
Nombre: Utilerias.tpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/19/2020
Descripción: Plantilla que contiene la función de captura segura.
*/
#include <iostream>
#include <limits>

#include "Utilerias.h"

using namespace std;

//**********************************************************************************************************************

template <typename TIPO>
void CapturaSegura(TIPO &n, const char solicitud[])
{
    while(true){
        cout << solicitud;
        cin >> n;

        if(cin.bad()) throw " Error irrecuperable en el flujo de entrada";

        if(cin.fail()){
            cout << " El valor introducido no es un n\243mero\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(),'\n');
            continue;
        }
        break;
    }
}
//**********************************************************************************************************************

