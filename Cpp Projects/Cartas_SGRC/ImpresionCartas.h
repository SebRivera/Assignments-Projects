/*
Nombre: ImpresionCartas.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 2/28/2020
Descripción: Prototipos de las funciones para imprimir el marco y el relleno de ls cartas.
*/

#ifndef CARTAS_SGRC_IMPRESION_CARTAS_H
#define CARTAS_SGRC_IMPRESION_CARTAS_H

#endif //CARTAS_SGRC_IMPRESION_CARTAS_H

enum NombreCartas {AS=1, JACK=11, REINA, REY};
enum Palos {CORAZON=3, DIAMANTE, TREBOL, PICAS};

/** \brief Función que Imprime el interior de la Carta
 *
 * \param Denominación (1-13) Denominación de la Carta (Inglesa)
 * \param Palo (1-4) Palo de la Carta (♥,♦,♣,♠)
 * \param x Porsición en x
 * \param y Posición en y
 *
 */
void Carta(int Denominacion, int Palo, int x, int y);
