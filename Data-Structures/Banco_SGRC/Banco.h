/*
Nombre: Banco.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 06/03/2021
Descripción: Cabecera de la clase Banco.
*/

#ifndef BANCO_SGRC_BANCO_H
#define BANCO_SGRC_BANCO_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Persona.h"
#include "Cola.h"

/** @class Banco Clase que permite crear un banco dado archivos de nombres y apellidos para crear los clientes a ser atendidos.
 *          Permite gestionar los timepo de atencion y el manejo de colas para atender a los clientes.
 */
class Banco {
public:
    //******************************************************************************************************************
    /** @brief Constructor de la clase Banco que recibe los archivos de los nombres y appelidos de
     *          los posibles clientes.
     *
     * @param archivoNombre Direcci&oacute;n del archivo que continene a los nombres.
     * @param archivoApellido Direcci&oacute;n del archivo que continene a los apellidos.
     */
    Banco(const std::string &archivoNombre, const std::string &archivoApellido);
    //******************************************************************************************************************
    /** @brief M&eacute;todo que se encarga de agregar un cliente tipo Persona con nombre y apellido aleaotrio.
     */
    void agregarCliente();
    //**********************************************************************************************************************
    /** @brief M&eacute;todo que mueve al primer cliente de la cola a ser atendido (se asigna a clienteActual).
     */
    void atenderCliente();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que deja de atender a un cliente y lo agrega a la cola de atendidos.
     */
    void terminarCliente();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que abre a la caja (asigna a cajaCerrada = fasle).
     */
    void abrirCaja();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que verifica si la caja se encuentra ocupada.
     *
     * @return True si est&aacute; ocupada, Fasle si no.
     */
    bool estaOcupado() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que imprime todos los aspectos del banco.
     */
    void imprimirBanco();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que imprime el estado final del banco.
     */
    void imprimirReporteBanco();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que imprime el logo del banco.
     */
    void imprimirLogo();
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener el timepo total de la jornada.
     *
     * @return Valor del tiempo total(tiempoTotal).
     */
    unsigned int obtenerTiempoTotal() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para establecer el tiempo total de la jornada.
     *
     * @param tiempoTotal tiempo a establecer.
     */
    void asignarTiempoTotal(unsigned int tiempoTotal);
    //******************************************************************************************************************
    /** @brief M&eacute;todo para decrementar el tiempo de la jornada.
     */
    void decrementarTiempoTotal();
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener el timepo de atenc&oacute;n del cliente actual.
     *
     * @return Retorna el timepo de atenc&oacute;n.
     */
    unsigned int obtenerTiempoAsignadoClienteActual() const;
    //******************************************************************************************************************
    /**@brief M&eacute;todo para asignar el timepo de atenc&oacute;n del cliente actual.
     *
     * @param tiempoAsignadoClienteActual Valor del tiempo a asignar.
     */
    void asignarTiempoAsignadoClienteActual(unsigned int tiempoAsignadoClienteActual);
    //******************************************************************************************************************
    /** @param M&eacute;todo para decrementar el tiempo de atenc&oacute;n del cliente actual.
     *
     */
    void decrementarTiempoAsignadoClienteActual();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que aumenta el timepo que lleva siendo atendido un cliente.
     */
    void aumentarTiempoEnAtencion();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que reinicia el tiempo que lleva siento atendido un cliente (tiempoEnAtencion = 0)
     *
     */
    void reiniciarTiempoEnAtencion();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que verifica si la caja se encuentra cerrada.
     *
     * @return True si cajaCerrada = true, False si cajaCerrada = false.
     */
    bool estaCajaCerrada() const;
    //******************************************************************************************************************
private:
    unsigned tiempoTotal;                       /** Unsigned que determina el timepo total de la jornada **/
    unsigned tiempoAsignadoClienteActual;       /** Unsigned que determina el tiempo total de atenci&oacute;n de un cliente **/
    unsigned tiempoEnAtencion;                  /** Unsigned que determina el tiempo en que lleva siendo atendido un cliente **/
    bool cajaOcupada;                           /** Booleano que determina si la caja se encuentra ocupada **/
    bool cajaCerrada;                           /** Booleano que determina si la caja se encuentra cerrada **/
    Persona clienteActual;                      /** Persona que guarda al cliente que se esta atendiendo **/
    Cola<Persona> clientesEspera;               /** Cola tipo Persona que guarda a los clientes que se encuentran haciendo fila* */
    Cola<Persona> clientesAtendidos;            /** Cola tipo Persona que guerda el registro de personas que fueron atendidas **/
    std::vector<std::string> listaNombres;      /** Vector tipo string que guarda la lista de todos los posibles nombres de los clientes **/
    std::vector<std::string> listaApellidos;    /** Vector tipo string que guarda la lista de todos los posibles apellidos de los clientes **/

    //******************************************************************************************************************
    /** @brief M&eacute;todo auxiliar que sirve para leer los archivos de nombres y apellidos de los clientes y guardarlos
     *          en listas (vectores) para despues poder crear clientes.
     *
     * @param archivoNombre Direcci&oacute;n del archivo que continene a los nombres.
     * @param archivoApellido Direcci&oacute;n del archivo que continene a los apellidos.
     */
    void leerArchivos(const std::string &archivoNombre, const std::string &archivoApellido);
    //******************************************************************************************************************
};


#endif //BANCO_SGRC_BANCO_H
