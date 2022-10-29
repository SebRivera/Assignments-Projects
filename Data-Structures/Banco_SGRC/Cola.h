/*
Nombre: Cola.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 03/03/2021
Descripción: Cabecera de la Cola. Clase que permite crear colas enlazadas.
*/

#ifndef COLAENLAZADA_SGRC_COLA_H
#define COLAENLAZADA_SGRC_COLA_H


#include <iostream>

/** @class Cola Clase que crea una estructura de cola y permite realizar todas sus modificaciones.
 *          Crea la cola en memoria din&aacute;mica mediante enlaces de forma circular.
 * @tparam T Tipo de los elementos a guardar en la cola
 */
template<typename T = double>
class Cola {
public:
    //******************************************************************************************************************
    /** @brief Constructor por default de la clase.
     */
    Cola();
    //******************************************************************************************************************
    /** @brief Constructor de copias de la clase.
     *
     * @param c Cola a copiar.
     */
    Cola(const Cola<T> &c);
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador de asignaci&oacute;n "=".
     *
     * @param c Cola que se asignar&aacute; a la otra cola.
     * @return Cola a asignar.
     */
    Cola <T> & operator=(const Cola<T> &c);
    //******************************************************************************************************************
    /** @brief destructor de la clase.
    */
    ~Cola();
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que agrega un nuevo elemento a la cola.
     *
     * @param val Valor del elemento a agregar.
     */
    void encolar(const T &val);
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que elimina al primer elemento de la cola.
     *
     * @throws Excepci&oacute;n "ColaVacia" si la cola no cuenta con elementos.
     */
    void desencolar();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que obtiene el tamaño de la cola.
     *
     * @return Tamaño de la cp;a.
     */
    unsigned obtenerTam() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que verifica si la cola esta vacia o no.
     *
     * @return True si la cola esta vacia, False si no lo esta.
     */
    bool estaVacia() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener el primer elemento de la cola.
     *
     * @throws Excepci&oacute;n "ColaVacia" si la cola no cuenta con elementos.
     * @return Primer elemento en la cola.
     */
    const T & obtenerPrimero() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener el &uacute;ltimo elemento de la cola.
     *
     * @throws Excepci&oacute;n "ColaVacia" si la cola no cuenta con elementos.
     * @return &Uacute;ltimo elemento en la cola.
     */
    const T & obtenerUltimo() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que vac&iacute; a la cola.
   */
    void vaciar();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que imprime a la cola.
     */
    void imprimir() const;
    //******************************************************************************************************************
    /** @class Clase utilizada para lanzar la excepci&oacute; colaVacia en caso de que la pila
     *          no tenga elementos.
     */
    class ColaVacia : public std::exception {
    public:
        virtual const char * what() const throw();
    };
    //******************************************************************************************************************
private:
    unsigned tam; /** Tamaño de la cola */
    struct Nodo{
        Nodo(T val, Nodo *sig = NULL);
        T valor;
        Nodo *siguiente;
    } *ultimo; /** Puntero al ultimo elemento de la cola (Valor y referencia del siguiente elemento */
};

#include "Cola.tpp"


#endif //COLAENLAZADA_SGRC_COLA_H
