/*
Nombre: main.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 4/19/2020
Descripción: Programa que realiza operaciones con polinomios.
*/
#include <iostream>
#include <cstdlib>

#include "Utilerias.h"
#include "Polinomios.h"

using namespace std;

int main() {
    int Opcion;
    cout << "Programa que permite realizar las operaci\242nes basicas de funciones." << endl;
    do {
        Opcion = Menu();
        if (Opcion == 0) {
            system("pause");
            return 0;
        }
        if(Opcion >= 1 && Opcion <=4){
            int GradoA, GradoB, GradoR;
            cout << "Primero: Ingrese el grado del polinomio A... " << endl;
            GradoA = CapGrado();
            cout << endl;
            float *PolinomioA = CrearPoli(GradoA);
            cout << "Ahora ingrese los coeficientes del polinomio A." << endl;
            CapturarPoli(PolinomioA, GradoA);
            cout << endl;
            cout << "Segundo: Ingrese el grado del polinomio B... " << endl;
            GradoB = CapGrado();
            cout << endl;

            float *PolinomioB = CrearPoli(GradoB);
            cout << "Ahora ingrese los coeficientes del polinomio A." << endl;
            CapturarPoli(PolinomioB, GradoB);
            cout << endl;
            switch(Opcion){
                case SUMA: {
                    float *PolinomioR = SumaPoli(PolinomioA, PolinomioB, GradoA, GradoB, GradoR);
                    ImprimirPoli(PolinomioA, GradoA);
                    ImprimirPoli(PolinomioB, GradoB);
                    cout << "El resultado de la suma es: "<<endl;
                    ImprimirPoli(PolinomioR, GradoR);

                    EliminarPoli(PolinomioR);
                    break;
                }
                case RESTA: {
                    float *PolinomioR = RestaPoli(PolinomioA, PolinomioB, GradoA, GradoB, GradoR);
                    ImprimirPoli(PolinomioA, GradoA);
                    ImprimirPoli(PolinomioB, GradoB);
                    cout << "El resultado de la resta es: "<<endl;
                    ImprimirPoli(PolinomioR, GradoR);
                    EliminarPoli(PolinomioR);
                    break;
                }
                case MULTIPLICACION: {
                    GradoR = GradoA + GradoB;
                    float *PolinomioR = MultiPoli(PolinomioA, PolinomioB, GradoA, GradoB, GradoR);
                    ImprimirPoli(PolinomioA, GradoA);
                    ImprimirPoli(PolinomioB, GradoB);
                    cout << "El producto es: "<<endl;
                    ImprimirPoli(PolinomioR, GradoR);
                    EliminarPoli(PolinomioR);
                    break;
                }
            }
            EliminarPoli(PolinomioA);
            EliminarPoli(PolinomioB);
        }else{
            int GradoA, GradoR;
            cout << "Ingrese el grado del polinomio... " << endl;
            GradoA = CapGrado();
            cout << endl;

            float *PolinomioA = CrearPoli(GradoA);
            cout << "Ahora ingrese los coeficientes del polinomio." << endl;
            CapturarPoli(PolinomioA, GradoA);
            cout << endl;

            switch (Opcion){
                case DERIVADA:{
                    float *PolinomioR = DerivadaPoli(PolinomioA, GradoA, GradoR);
                    ImprimirPoli(PolinomioA, GradoA);
                    cout << "La derivada del polinomio es: "<<endl;
                    ImprimirPoli(PolinomioR, GradoR);
                    EliminarPoli(PolinomioR);
                    break;
                }
                case EVALUACION:{
                    float x, Resultado;
                    CapturaSegura(x,"Ingrese el valor de X ");
                    Resultado = EvaluarPoli(PolinomioA, GradoA, x);
                    cout <<"El resultado de evaluar el polinomio es: "<<  Resultado <<endl << endl;
                }
            }
            EliminarPoli(PolinomioA);
        }
        system("pause");

    }while(Opcion !=0);
}





