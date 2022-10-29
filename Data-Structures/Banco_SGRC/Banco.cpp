/*
Nombre: Banco.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 06/03/2021
Descripción: Archivo de implementación de "Banco.h"
*/

#include "Banco.h"
//**********************************************************************************************************************
Banco::Banco(const std::string &archivoNombre, const std::string &archivoApellido):
        cajaOcupada(false), cajaCerrada(true), clienteActual("",""), tiempoTotal(120),
        tiempoAsignadoClienteActual(0), tiempoEnAtencion(0)
{
    leerArchivos(archivoNombre,archivoApellido);
}
//**********************************************************************************************************************
void Banco::agregarCliente()
{
    int iNombre = rand() % listaNombres.size();
    int iApellido = rand() % listaApellidos.size();
    clientesEspera.encolar(Persona(listaNombres[iNombre], listaApellidos[iApellido]));
}
//**********************************************************************************************************************
void Banco::atenderCliente()
{
    if (!estaOcupado() && !clientesEspera.estaVacia()) {
        clienteActual = clientesEspera.obtenerPrimero();
        clientesEspera.desencolar();
        cajaOcupada = true;
    }
}
//**********************************************************************************************************************
void Banco::terminarCliente()
{
    if(estaOcupado()) {
        clientesAtendidos.encolar(clienteActual);
        clienteActual.asignarPersona(" ", " ");
        cajaOcupada = false;
    }
}
//**********************************************************************************************************************
void Banco::abrirCaja() {
    cajaCerrada = false;
}
//**********************************************************************************************************************
bool Banco::estaOcupado() const
{
    return cajaOcupada;
}
//**********************************************************************************************************************
void Banco::imprimirBanco()
{
    imprimirLogo();
    std::cout << std::endl;

    std::cout << "Tiempo Restante: " << tiempoTotal << std::endl;
    std::cout << std::endl;

    if(estaCajaCerrada()) std::cout << "Caja Cerrada" << std::endl;
    else std::cout << "Caja Abierta" << std::endl;
    std::cout << std::endl;
    
    //std::cout << "Cliente Actual: " << clienteActual << "   Tiempo siendo atendido: " << tiempoEnAtencion << std::endl;
    std::cout << "Cliente Actual: ";
    if(estaOcupado()) std::cout << clienteActual;
    std::cout << "      Tiempo siendo atendido: " << tiempoEnAtencion << std::endl;
    std::cout << std::endl;

    std::cout << "Clientes en Espera:" << std::endl;
    if(!clientesEspera.estaVacia()) clientesEspera.imprimir();
}
//**********************************************************************************************************************
void Banco::imprimirReporteBanco()
{
    imprimirLogo();
    std::cout << "La jornada ha terminado" << std::endl;
    std::cout << std::endl;

    std::cout << "El banco terminar\240 de atender a " << clientesAtendidos.obtenerUltimo() << std::endl;
    std::cout << std::endl;

    std::cout << "Faltaron por atender: " << std::endl;
    clientesEspera.imprimir();

    std::cout << "Se atendieron a " << clientesAtendidos.obtenerTam() << " Clientes:"  << std::endl;
    clientesAtendidos.imprimir();
}
//**********************************************************************************************************************
void Banco::imprimirLogo()
{
    std::cout << " _______   __             __                                     _______                       __       \n";
    std::cout << "|       \\ |  \\           |  \\                                   |       \\                     |  \\      \n";
    std::cout << "| $$$$$$$\\ \\$$ __     __  \\$$  ______    ______   ______        | $$$$$$$\\  ______   _______  | $$   __ \n";
    std::cout << "| $$__| $$|  \\|  \\   /  \\|  \\ /      \\  /      \\ |      \\       | $$__/ $$ |      \\ |       \\ | $$  /  \\\n";
    std::cout << "| $$    $$| $$ \\$$\\ /  $$| $$|  $$$$$$\\|  $$$$$$\\ \\$$$$$$\\      | $$    $$  \\$$$$$$\\| $$$$$$$\\| $$_/  $$\n";
    std::cout << "| $$$$$$$\\| $$  \\$$\\  $$ | $$| $$    $$| $$   \\$$/      $$      | $$$$$$$\\ /      $$| $$  | $$| $$   $$ \n";
    std::cout << "| $$  | $$| $$   \\$$ $$  | $$| $$$$$$$$| $$     |  $$$$$$$      | $$__/ $$|  $$$$$$$| $$  | $$| $$$$$$\\ \n";
    std::cout <<  "| $$  | $$| $$    \\$$$   | $$ \\$$     \\| $$      \\$$    $$      | $$    $$ \\$$    $$| $$  | $$| $$  \\$$\\\n";
    std::cout << " \\$$   \\$$ \\$$     \\$     \\$$  \\$$$$$$$ \\$$       \\$$$$$$$       \\$$$$$$$   \\$$$$$$$ \\$$   \\$$ \\$$   \\$$\n";
    std::cout << "       ";
}
//**********************************************************************************************************************
unsigned int Banco::obtenerTiempoTotal() const {
    return tiempoTotal;
}
//**********************************************************************************************************************
void Banco::asignarTiempoTotal(unsigned int tiempoTotal) {
    Banco::tiempoTotal = tiempoTotal;
}
//**********************************************************************************************************************
void Banco::decrementarTiempoTotal()
{
    tiempoTotal--;
}
//**********************************************************************************************************************
unsigned int Banco::obtenerTiempoAsignadoClienteActual() const
{
    return tiempoAsignadoClienteActual;
}
//**********************************************************************************************************************
void Banco::asignarTiempoAsignadoClienteActual(unsigned int tiempoAsignadoClienteActual)
{
    Banco::tiempoAsignadoClienteActual = tiempoAsignadoClienteActual;
}
//**********************************************************************************************************************
void Banco::decrementarTiempoAsignadoClienteActual()
{
    tiempoAsignadoClienteActual--;
}
//**********************************************************************************************************************
void Banco::aumentarTiempoEnAtencion()
{
    tiempoEnAtencion++;
}
//**********************************************************************************************************************
void Banco::reiniciarTiempoEnAtencion()
{
    tiempoEnAtencion = 0;
}
//**********************************************************************************************************************
bool Banco::estaCajaCerrada() const {
    return cajaCerrada;
}
//**********************************************************************************************************************
void Banco::leerArchivos(const std::string &archivoNombre, const std::string &archivoApellido)
{
    const char* aNom = archivoNombre.c_str();
    const char* aAp = archivoApellido.c_str();
    std::string aux;
    std::ifstream archivoNom(aNom);
    if(archivoNom.is_open()) {
        while (!archivoNom.eof()) {
            getline(archivoNom, aux);
            listaNombres.push_back(aux);
        }
    }
    archivoNom.close();

    std::ifstream archivoAp(aAp);
    if(archivoAp.is_open()) {
        while (!archivoAp.eof()) {
            getline(archivoAp, aux);
            listaApellidos.push_back(aux);
        }
    }
    archivoNom.close();
}
//**********************************************************************************************************************