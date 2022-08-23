/*
Nombre: main.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 5/20/2020
Descripción: Programa que perimite realizar operaciones con matrices con la utilización de archivos.
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Utilerias.h"
#include "FuncionesMatrices.h"

using namespace std;

int main()
{
    short OpcionMenu;
    cout << "Programa que perimite realizar operaciones con matrices con la utilizaci\242n de archivos" << endl;
    do {
        cout << "0)Salir" << endl;
        cout << "1)Crear un archivo con una matriz" << endl;
        cout << "2)Sumar dos matrices" << endl;
        cout << "3)Restar dos matrices" << endl;
        cout << "4)Multiplicar dos matrices" << endl;
        cout << "5)Multiplicar una matriz por un escalar" << endl;
        cout << "6)Encontrar la matriz transpuesta" << endl;
        cout << "7)Encontrar la matriz inversa" << endl;
        do {
            CapturaSegura(OpcionMenu, "Elija opci\242n: ");
            if (OpcionMenu < 0 || OpcionMenu > 7) cout << "Fuera de rango..." << endl;
        }while (OpcionMenu < 0 || OpcionMenu > 7);
        cout << endl;
        if (OpcionMenu == 0) {
            system("pause");
            return 0;
        }
        system("cls");
        short OpCapturaA, OpCapturaB;

        try{
            switch (OpcionMenu) {
                case CREAR: {
                    char NombreArchivo[50];
                    char Extensiontxt[] = ".txt";
                    bool ExisteExtension;
                    int m, n;
                    ExisteExtension = LeerYComprobarExt(NombreArchivo, // Captura el nombre del archivo y verifica si contiene extension.
                            "Ingrese el nombre del archivo a crear (con o sin '.txt' o '.dat'): ");

                    if (!ExisteExtension) strcat(NombreArchivo, Extensiontxt); // Se le agrega la extension .txt en caso de no tenerla.
                    ofstream NuevoArchivo(NombreArchivo);
                    cout << "Ingrese la dimensi\242n de la matriz (m x n): " << endl;
                    CapturaSegura(m,"Ingrese m: ");
                    CapturaSegura(n,"Ingrese n: ");

                    float **Matriz = CrearMatriz(m, n);
                    cout << "Ingrese la Matriz: " << endl;
                    CapturarMatriz(Matriz, m, n);
                    NuevoArchivo << m << ' ' << n << endl;
                    for (int i = 0; i < m; ++i){
                        for (int j = 0; j < n; ++j)
                            NuevoArchivo << Matriz[i][j] << ' ';
                        NuevoArchivo << endl;
                    }
                    NuevoArchivo.close();
                    cout << "El archivo ha sido creado con exito." << endl;
                    EliminarMatriz(Matriz);
                    system("pause");
                    system("cls");
                    break;
                }
                case SUMAR:
                case RESTAR: {
                    int m, n;
                    char ArchivoA[50];
                    char ArchivoB[50];
                    char Extensiontxt[] = ".txt";
                    bool CapTecladoA = false, CapTecladoB = false;
                    OpCapturaA = MenuCaptura("A");
                    switch (OpCapturaA) { // Switch que se encarga de obtener la dimension de la matriz dependiento del método de captura.
                        case 1: {  //Capturada mediante tecaldo.
                            cout << "Dimensi\242n de la matriz (m x n): " << endl;
                            CapturaSegura(m,"Ingrese m: ");
                            CapturaSegura(n,"Ingrese n: ");
                            CapTecladoA = true;
                            break;
                        }
                        case 2: { //Capturada mediante archivo.
                            bool ExisteExtension;
                            bool Error;
                            int Intentos = 3;
                            do {
                                Error = false;
                                ExisteExtension = LeerYComprobarExt(ArchivoA,
                                                                    "Ingrese el nombre del archivo para la Matriz A(con o sin '.txt' o '.dat'): ");
                                if (!ExisteExtension) strcat(ArchivoA, Extensiontxt);
                                ifstream matrizA(ArchivoA);
                                if (!matrizA) {
                                    cout << "Error al encontrar el archivo, ingrese el nombre otra vez (Intentos restantes: " << Intentos << " )..." << endl;
                                    Intentos -= 1;
                                    system("pause");
                                    matrizA.close();
                                    Error = true;
                                    continue;
                                }
                                matrizA >> m >> n;
                                matrizA.close();
                            }while(Error && Intentos >= 0);
                            if(Intentos == 0) continue;
                            break;
                        }
                    }
                    float **MatrizA = CrearMatriz(m, n);
                    if (CapTecladoA) { //Captura la matriz por teclado.
                        cout << "Ingrese la Matriz A:" << endl;
                        CapturarMatriz(MatrizA, m, n);
                    }else { // //Captura la matriz por el archivo.
                        ifstream matrizA(ArchivoA);
                        if (!matrizA) {
                            cout << "Error al acceder al archivo, se te regresar\240 al men\243..." << endl;
                            system("pause");
                            system("cls");
                            matrizA.close();
                            continue;
                        }
                        matrizA >> m >> n;
                        for (int i = 0; i < m; ++i)
                            for (int j = 0; j < n; ++j) {
                                matrizA >> MatrizA[i][j];
                                if (!matrizA) {
                                    cout << "Error a la lectura de datos, se te regresar\240 al men\243...";
                                    system("pause");
                                    system("cls");
                                    matrizA.close();
                                    continue;
                                }
                            }
                        matrizA.close();
                    }
                    float **MatrizB = CrearMatriz(m, n);
                    int mB, nB;
                    OpCapturaB = MenuCaptura("B");
                    switch (OpCapturaB) {
                        case 1: {
                            CapTecladoB = true;
                            break;
                        }
                        case 2: {
                            bool ExisteExtension;
                            bool Error;
                            int Intentos = 3;
                            do {
                                Error = false;
                                ExisteExtension = LeerYComprobarExt(ArchivoB,
                                                                    "Ingrese el nombre del archivo para la Matriz B(con o sin '.txt' o '.dat'): ");
                                if (!ExisteExtension) strcat(ArchivoB, Extensiontxt);
                                ifstream matrizB(ArchivoB);
                                if (!matrizB) {
                                    cout << "Error al encontrar el archivo, ingrese el nombre otra vez (Intentos restantes: " << Intentos << " )..." << endl;
                                    Intentos -= 1;
                                    system("pause");
                                    matrizB.close();
                                    Error = true;
                                    continue;
                                }
                                matrizB >> mB >> nB;
                                if (m != mB || n != nB) { //Verifica que las dimensiones sean iguales.
                                    cout << "La dimensi\242n es diferente al de la matriz A, ingrese otro archivo (Intentos restantes: " << Intentos << " )..." << endl;
                                    Intentos -= 1;
                                    system("pause");
                                    matrizB.close();
                                    Error = true;
                                    continue;
                                }
                                matrizB.close();
                            }while(Error && Intentos >= 0);
                            if(Intentos == 0) continue;
                            break;
                        }
                    }
                    if (CapTecladoB) {
                        cout << "Ingrese la Matriz B:" << endl;
                        CapturarMatriz(MatrizB, m, n);
                    } else {
                        ifstream matrizB(ArchivoB);
                        if (!matrizB) {
                            cout << "Error al encontrar el archivo, se te regresar\240 al men\243..." << endl;
                            system("pause");
                            system("cls");
                            matrizB.close();
                            continue;
                        }
                        matrizB >> m >> n;
                        for (int i = 0; i < m; ++i)
                            for (int j = 0; j < n; ++j) {
                                matrizB >> MatrizB[i][j];
                                if (!matrizB) {
                                    cout << "Error a la lectura de datos, se te regresar\240 al men\243...";
                                    system("pause");
                                    system("cls");
                                    matrizB.close();
                                    continue;
                                }
                            }
                        matrizB.close();
                    }
                    system("cls");
                    float **MatrizR = CrearMatriz(m, n);
                    int OpMenuGuardar;
                    if (OpcionMenu == SUMAR) { //Realiza la suma de matrices.
                        cout << "Suma de dos matrices" << endl;
                        cout << "Matriz A:" << endl;
                        ImprimirMatriz(MatrizA, m, n);
                        cout << "Matriz B:" << endl;
                        ImprimirMatriz(MatrizB, m, n);
                        MatrizR = SumarMatrices(MatrizA, MatrizB, m, n);
                        cout << "Resultado:" << endl;
                        ImprimirMatriz(MatrizR, m, n);
                    } else { //Realiza la resta de matrices.
                        cout << "Resta de dos matrices" << endl;
                        cout << "Matriz A:" << endl;
                        ImprimirMatriz(MatrizA, m, n);
                        cout << "Matriz B:" << endl;
                        ImprimirMatriz(MatrizB, m, n);
                        MatrizR = RestarMatrices(MatrizA, MatrizB, m, n);
                        cout << "Resultado:" << endl;
                        ImprimirMatriz(MatrizR, m, n);
                    }
                    system("pause");
                    OpMenuGuardar = MenuGuardar();
                    if (OpMenuGuardar == 1) { //Proceso de guardar la matriz resultante en un archivo.
                        char NombreArchivo[50];
                        bool ExisteExtension;

                        ExisteExtension = LeerYComprobarExt(NombreArchivo,
                                "Ingrese el nombre del archivo a crear (con o sin '.txt' o '.dat'): ");

                        if (!ExisteExtension) strcat(NombreArchivo, Extensiontxt);

                        ofstream NuevoArchivo(NombreArchivo);
                        NuevoArchivo << m << ' ' << n << endl;
                        for (int i = 0; i < m; ++i) {
                            for (int j = 0; j < n; ++j)
                                NuevoArchivo << MatrizR[i][j] << ' ';
                            NuevoArchivo << endl;
                        }
                        NuevoArchivo.close();
                        cout << "El archivo ha sido creado con exito." << endl;
                    }
                    EliminarMatriz(MatrizA);
                    EliminarMatriz(MatrizB);
                    EliminarMatriz(MatrizR);
                    system("pause");
                    system("cls");
                    break;
                }
                case MULTIPLICAR: {
                    int m, n;
                    char ArchivoA[50];
                    char ArchivoB[50];
                    char Extensiontxt[] = ".txt";
                    bool CapTecladoA = false, CapTecladoB = false;

                    OpCapturaA = MenuCaptura("A");
                    switch (OpCapturaA) {
                        case 1: {
                            cout << "Dimensi\242n de la matriz (m x n): " << endl;
                            CapturaSegura(m,"Ingrese m: ");
                            CapturaSegura(n,"Ingrese n: ");
                            CapTecladoA = true;
                            break;
                        }
                        case 2: {
                            bool ExisteExtension;
                            bool Error;
                            int Intentos = 3;
                            do {
                                Error = false;
                                ExisteExtension = LeerYComprobarExt(ArchivoA,
                                                                    "Ingrese el nombre del archivo para la matriz A(con o sin '.txt' o '.dat'): ");
                                if (!ExisteExtension) strcat(ArchivoA, Extensiontxt);

                                ifstream matrizA(ArchivoA);
                                if (!matrizA) {
                                    cout << "Error al encontrar el archivo, ingrese el nombre otra vez (Intentos restantes: " << Intentos << " )..." << endl;
                                    Intentos -= 1;
                                    system("pause");
                                    matrizA.close();
                                    Error = true;
                                    continue;
                                }
                                matrizA >> m >> n;
                                matrizA.close();
                            }while(Error && Intentos >= 0);
                            if(Intentos == 0) continue;
                            break;
                        }
                    }
                    float **MatrizA = CrearMatriz(m, n);
                    if (CapTecladoA) {
                        cout << "Ingrese la Matriz A:" << endl;
                        CapturarMatriz(MatrizA, m, n);
                    } else {
                        ifstream matrizA(ArchivoA);
                        if (!matrizA) {
                            cout << "Error al encontrar el archivo, se te regresar\240 al men\243..." << endl;
                            system("pause");
                            system("cls");
                            matrizA.close();
                            continue;
                        }
                        matrizA >> m >> n;
                        for (int i = 0; i < m; ++i)
                            for (int j = 0; j < n; ++j) {
                                matrizA >> MatrizA[i][j];
                                if (!matrizA) {
                                    cout << "Error a la lectura de datos, se te regresar\240 al men\243...";
                                    system("pause");
                                    system("cls");
                                    matrizA.close();
                                    continue;
                                }
                            }
                        matrizA.close();
                    }

                    int mB, nB;
                    OpCapturaB = MenuCaptura("B");
                    switch (OpCapturaB) {
                        case 1: {
                            mB = n;
                            cout << "Dimensi\242n de la matriz (m x n): " << endl;
                            CapturaSegura(nB,"Ingrese n: ");
                            CapTecladoB = true;
                            break;
                        }
                        case 2: {
                            bool ExisteExtension;
                            bool Error;
                            int Intentos = 3;
                            do {
                                Error = false;
                                ExisteExtension = LeerYComprobarExt(ArchivoB,
                                                                    "Ingrese el nombre del archivo para la matriz B(con o sin '.txt' o '.dat'): ");
                                if (!ExisteExtension) strcat(ArchivoB, Extensiontxt);
                                ifstream matrizB(ArchivoB);
                                if (!matrizB) {
                                    cout << "Error al encontrar el archivo, ingrese el nombre otra vez (Intentos restantes: " << Intentos << " )..." << endl;
                                    Intentos -= 1;
                                    system("pause");
                                    matrizB.close();
                                    Error = true;
                                    continue;
                                }
                                matrizB >> mB >> nB;
                                if (n != mB) { //Verifica que la dimension sea adecuada.
                                    cout << "No se puede multiplicar, ingrese otro archivo (Intentos restantes: " << Intentos << " )..." << endl;
                                    Intentos -= 1;
                                    system("pause");
                                    matrizB.close();
                                    Error = true;
                                    continue;
                                }
                                matrizB.close();
                            }while(Error && Error >= 0);
                            if(Intentos == 0) continue;
                            break;
                        }
                    }

                    float **MatrizB = CrearMatriz(mB, nB);
                    if (CapTecladoB) {
                        cout << "Ingrese la Matriz B:" << endl;
                        CapturarMatriz(MatrizB, mB, nB);
                    } else {
                        ifstream matrizB(ArchivoB);
                        if (!matrizB) {
                            cout << "Error al encontrar el archivo, se te regresar\240 al men\243..." << endl;
                            system("pause");
                            system("cls");
                            matrizB.close();
                            continue;
                        }
                        matrizB >> mB >> nB;
                        for (int i = 0; i < mB; ++i)
                            for (int j = 0; j < nB; ++j) {
                                matrizB >> MatrizB[i][j];
                                if (!matrizB) {
                                    cout << "Error a la lectura de datos, se te regresar\240 al men\243...";
                                    system("pause");
                                    system("cls");
                                    matrizB.close();
                                    continue;
                                }
                            }
                        matrizB.close();
                    }
                    system("cls");
                    float **MatrizR = CrearMatriz(m, nB);
                    int OpMenuGuardar;
                    cout << "Multiplicaci\242n de dos matrices" << endl;
                    cout << "Matriz A:" << endl;
                    ImprimirMatriz(MatrizA, m, n);
                    cout << "Matriz B:" << endl;
                    ImprimirMatriz(MatrizB, mB, nB);
                    MatrizR = MultiMatrices(MatrizA, MatrizB, m, n,nB);
                    cout << "Resultado:" << endl;
                    ImprimirMatriz(MatrizR, m, nB);
                    OpMenuGuardar = MenuGuardar();
                    system("pause");
                    if (OpMenuGuardar == 1) {
                        char NombreArchivoR[50];
                        bool ExisteExtension;

                        ExisteExtension = LeerYComprobarExt(NombreArchivoR,
                                                             "Ingrese el nombre del archivo a crear (con o sin '.txt' o '.dat'): ");

                        if (!ExisteExtension) strcat(NombreArchivoR, Extensiontxt);

                        ofstream NuevoArchivo(NombreArchivoR);
                        NuevoArchivo << m << ' ' << nB << endl;
                        for (int i = 0; i < m; ++i) {
                            for (int j = 0; j < nB; ++j)
                                NuevoArchivo << MatrizR[i][j] << ' ';
                            NuevoArchivo << endl;
                        }
                        NuevoArchivo.close();
                        cout << "El archivo ha sido creado con exito." << endl;
                    }
                    EliminarMatriz(MatrizA);
                    EliminarMatriz(MatrizB);
                    EliminarMatriz(MatrizR);
                    system("pause");
                    system("cls");
                    break;
                }
                case ESCALAR:
                case TRANSPUESTA:
                case INVERSA: {
                    int m, n;
                    char Archivo[50];
                    char Extensiontxt[] = ".txt";
                    bool CapTecladoA = false;

                    OpCapturaA = MenuCaptura("");
                    switch (OpCapturaA) {
                        case 1: {
                            if(OpcionMenu == INVERSA){ //Si la matriz es inversa solo captura "n".
                                cout << "Dimensi\242n de la matriz (n x n): " << endl;
                                CapturaSegura(n,"Ingrese n: ");
                            } else {
                                cout << "Dimensi\242n de la matriz (m x n): " << endl;
                                CapturaSegura(m,"Ingrese m: ");
                                CapturaSegura(n,"Ingrese n: ");
                            }
                            CapTecladoA = true;
                            break;
                        }
                        case 2: {
                            bool ExisteExtension;
                            bool Error;
                            int Intentos = 3;
                            do {
                                Error = false;
                                ExisteExtension = LeerYComprobarExt(Archivo,
                                                                    "Ingrese el nombre del archivo para la matriz (con o sin '.txt' o '.dat'): ");
                                if (!ExisteExtension) strcat(Archivo, Extensiontxt);

                                ifstream matriz(Archivo);
                                if (!matriz) {
                                    cout << "Error al encontrar el archivo, ingrese el nombre otra vez (Intentos restantes: " << Intentos << " )..." << endl;
                                    Intentos -= 1;
                                    system("pause");
                                    matriz.close();
                                    Error = true;
                                    continue;
                                }
                                matriz >> m >> n;
                                if (OpcionMenu == INVERSA)
                                    if (m != n) { //Si la opción es inversa, verifica que sea una matriz cuadrada.
                                        cout << "La Matriz indicada no es cuadrada, ingrese otro archivo (Intentos restantes: " << Intentos << " )..." << endl;
                                        Intentos -= 1;
                                        system("pause");
                                        matriz.close();
                                        Error = true;
                                        continue;
                                    }
                                matriz.close();
                            }while(Error && Intentos >=0 );
                            if(Intentos == 0) continue;
                            break;
                        }
                    }
                    if(OpcionMenu == INVERSA) m = n; // Si la opción es inversa, se iguala m con n para poder realizar
                                                    // el resto de las operaciones.


                    float **Matriz = CrearMatriz(m, n);
                    if (CapTecladoA) {
                        cout << "Ingrese la Matriz:" << endl;
                        if(OpcionMenu == INVERSA) CapturarMatriz(Matriz, n, n); //Si la opcion es inversa captura la matriz
                                                                                // de forma nxn.
                        else CapturarMatriz(Matriz, m, n);
                    } else {
                        ifstream matriz(Archivo);
                        if (!matriz) {
                            cout << "Error al encontrar el archivo, se te regresar\240 al men\243..." << endl;
                            system("pause");
                            system("cls");
                            matriz.close();
                            continue;
                        }
                        matriz >> m >> n;
                        for (int i = 0; i < m; ++i)
                            for (int j = 0; j < n; ++j) {
                                matriz >> Matriz[i][j];
                                if (!matriz) {
                                    cout << "Error a la lectura de datos, se te regresar\240 al men\243...";
                                    system("pause");
                                    system("cls");
                                    matriz.close();
                                    continue;
                                }
                            }
                        matriz.close();
                    }
                    if(OpcionMenu == TRANSPUESTA){ //Si la opción es transpuesta, se intercambia m con n para poder realizar
                                                    // las operaciones siguientes.
                        int Aux = m;
                        m = n;
                        n = Aux;
                    }
                    system("cls");
                    float **MatrizR = CrearMatriz(m,n);
                    int OpMenuGuardar;
                    bool EsInvertible = true;
                    if(OpcionMenu == ESCALAR) {
                        int Escalar;
                        CapturaSegura(Escalar,"Ingrese el valor del escalar: ");
                        cout << "Multiplicaci\242n de una matriz por un escalar" << endl;
                        cout << "Matriz:" << endl;
                        ImprimirMatriz(Matriz, m, n);
                        MatrizR = EscalarPorMatriz(Matriz,m,n,Escalar);
                        cout << "Resultado:" << endl;
                        ImprimirMatriz(MatrizR, m, n);
                    }else if(OpcionMenu == TRANSPUESTA){
                        cout << "Transpuesta de una matriz" << endl;
                        cout << "Matriz:" << endl;
                        ImprimirMatriz(Matriz, n, m);
                        MatrizR = TransPMatriz(Matriz,n,m);
                        cout << "Resultado" << endl;
                        ImprimirMatriz(MatrizR, m, n);
                    }else{
                        if(InversaMatriz(Matriz,n,MatrizR)) {
                            cout << "Inversa de una Matriz" << endl;
                            cout << "Matriz:" << endl;
                            ImprimirMatriz(Matriz, n, n);
                            cout << "Resultado" << endl;
                            ImprimirMatriz(MatrizR, n, n);
                        }
                        else {
                            cout << "Esta matriz no es invertible." << endl;
                            EsInvertible = false;
                        }
                    }
                    system("Pause");
                    if(EsInvertible){
                        OpMenuGuardar = MenuGuardar();
                    }else {
                        system("cls");
                        continue;
                    }
                    if (OpMenuGuardar == 1) {
                        char NombreArchivo[50];
                        bool ExisteExtension;

                        ExisteExtension = LeerYComprobarExt(NombreArchivo,"Ingrese el nombre del archivo a crear (con o sin '.txt' o '.dat'): ");

                        if (!ExisteExtension) strcat(NombreArchivo, Extensiontxt);

                        ofstream NuevoArchivo(NombreArchivo);
                        NuevoArchivo << m << ' ' << n << endl;
                        for (int i = 0; i < m; ++i) {
                            for (int j = 0; j < n; ++j)
                                NuevoArchivo << MatrizR[i][j] << ' ';
                            NuevoArchivo << endl;
                        }
                        NuevoArchivo.close();
                        cout << "El archivo ha sido creado con exito." << endl;
                    }
                    EliminarMatriz(Matriz);
                    EliminarMatriz(MatrizR);
                    system("pause");
                    system("cls");
                    break;
                }
            }

        }catch(bad_alloc &){
            cout << "Error en la asignaci\242n de memoria... " << endl;
            system("cls");
        }catch (...){
            cout << "Ocurri\242 un error inesperado" << endl;
            system("cls");
        }

    }while(OpcionMenu != 0);
}