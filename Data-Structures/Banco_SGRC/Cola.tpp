/*
Nombre: Cola.tpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 03/03/2021
Descripción: Implementacion template de la clase Cola.
*/

#include "Cola.h"
//******************************************************************************************************************
template<typename T>
Cola<T>::Cola():tam(0), ultimo(NULL) {}
//******************************************************************************************************************
template<typename T>
Cola<T>::Cola(const Cola<T> &c): tam(0), ultimo(NULL)
{
    *this = c;
}
//******************************************************************************************************************
template<typename T>
Cola<T> &Cola<T>::operator=(const Cola<T> &c)
{
    if(this == &c) return *this;
    vaciar();
    if(!c.estaVacia()) {
        Nodo *aux = (c.ultimo)->siguiente;
        do {
            encolar(aux->valor);
            aux = aux->siguiente;
        } while (aux != (c.ultimo)->siguiente);
    }
    return *this;
}
//******************************************************************************************************************
template<typename T>
Cola<T>::~Cola()
{
    vaciar();
}
//******************************************************************************************************************
template<typename T>
void Cola<T>::encolar(const T &val)
{
    Nodo *nuevo = new Nodo(val);
    if(estaVacia()) {
        ultimo = nuevo;
        ultimo -> siguiente = nuevo;
    }
    else {
        nuevo -> siguiente = ultimo -> siguiente;
        ultimo -> siguiente = nuevo;
        ultimo = nuevo;
    }
    tam++;
}
//******************************************************************************************************************
template<typename T>
void Cola<T>::desencolar()
{
    if(estaVacia()) throw ColaVacia();
    Nodo *auxSalir = ultimo -> siguiente;
    ultimo -> siguiente = ultimo -> siguiente -> siguiente;
    if (ultimo -> siguiente == NULL) ultimo = NULL;
    delete auxSalir;
    tam--;
}
//******************************************************************************************************************
template<typename T>
unsigned Cola<T>::obtenerTam() const
{
    return tam;
}
//******************************************************************************************************************
template<typename T>
bool Cola<T>::estaVacia() const
{
    return tam == 0;
}
//******************************************************************************************************************
template<typename T>
const T &Cola<T>::obtenerPrimero() const
{
    if(estaVacia()) throw ColaVacia();
    return ultimo -> siguiente -> valor;
}
//******************************************************************************************************************
template<typename T>
const T &Cola<T>::obtenerUltimo() const
{
    if(estaVacia()) throw ColaVacia();
    return ultimo -> valor;
}
//******************************************************************************************************************
template<typename T>
void Cola<T>::vaciar()
{
    while(!estaVacia()) desencolar();
}
//******************************************************************************************************************
template<typename T>
void Cola<T>::imprimir() const
{
    if(estaVacia()) {
        std::cout << "Cola Vac\241a" << std::endl;
        return;
    }
    Nodo *aux = ultimo -> siguiente;
    do {
        std::cout << aux -> valor << std::endl;
        aux = aux -> siguiente;
    } while (aux != ultimo -> siguiente);
    std::cout << "\b\b \b" <<std::endl;
}
//******************************************************************************************************************
template<typename T>
Cola<T>::Nodo::Nodo(T val, Nodo *sig /* = NULL */):valor(val), siguiente(sig){}
//******************************************************************************************************************
template <typename T>
const char *Cola<T>::ColaVacia::what() const throw() {
    return "Error: Cola vac\241a";
}
//******************************************************************************************************************