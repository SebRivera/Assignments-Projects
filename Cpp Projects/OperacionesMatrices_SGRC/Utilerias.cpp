/*
Nombre: OperacionesMatrices_SGRC.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 5/18/2020
Descripción: Archvivo que contiene las funciones de utilerias.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "Utilerias.h"

bool  LeerYComprobarExt(char nombreArchivo[], const char solicitud[])
{
    bool ExisteExtension = false;
    bool ExtensionInvalida = false;

    while(true){
        std::cout << solicitud;
        std::cin >> nombreArchivo;
        short TamanoNombre = strlen(nombreArchivo);
        for(int i = 0; i < TamanoNombre; ++i){
            if(nombreArchivo[i] == '.'){
                if(nombreArchivo[i+1] == 't')
                    if(nombreArchivo[i+2] == 'x')
                        if(nombreArchivo[i+3] == 't'){
                            ExisteExtension = true;
                            ExtensionInvalida = false;
                            break;
                        }
                if(nombreArchivo[i+1] == 'd')
                    if(nombreArchivo[i+2] == 'a')
                        if(nombreArchivo[i+3] == 't'){
                            ExisteExtension = true;
                            ExtensionInvalida = false;
                            break;
                        }
                ExtensionInvalida = true;
            }
        }
        if(!ExtensionInvalida) break;
    }
    return ExisteExtension;
}

int MenuCaptura(const char NombreM[])
{
    short Op;
    std::cout << "\250Como desea capturar la matriz " << NombreM << "?" << std::endl;
    std::cout << "1)Ingresar manualmente (Teclado)" << std::endl;
    std::cout << "2)Lectura de un Archivo" << std::endl;
    do {
        CapturaSegura(Op, "Eliga opci\242n: ");
        if(Op <1 || Op >2) std::cout << "Fuera de rango..." << std::endl;
    }while (Op <1 || Op >2);
    std::cout << std::endl;
    return Op;
}

int MenuGuardar()
{
    short Op;
    std::cout << "\250Desea guardar esta matriz en un archivo?" << std::endl;
    std::cout << "1)Si" << std::endl;
    std::cout << "2)No" << std::endl;
    do {
        CapturaSegura(Op, "Eliga opci\242n: ");
        if(Op <1 || Op >2) std::cout << "Fuera de rango..." << std::endl;
    }while (Op <1 || Op >2);
    std::cout << std::endl;
    return Op;
}
