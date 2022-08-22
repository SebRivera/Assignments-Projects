/*
Nombre: Cartas_SGRC.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 2/28/2020
Descripción: Prototipos de las funciones de utilierias.
*/

#ifndef CARTAS_SGRC_UTILERIAS_H
#define CARTAS_SGRC_UTILERIAS_H

#endif //CARTAS_SGRC_UTILERIAS_H
#define ALTO 13
#define ANCHO 13

enum Color{
    NEGRO, /**< Color negro */
    AZUL, /**< Color azul fuerte */
    VERDE, /**< Color verde oscuro */
    AGUAMARINA, /**< Color azul verde */
    ROJO, /**< Color rojo oscuro */
    PURPURA, /**< Color morado */
    AMARILLO, /**< Color amarillo */
    GRISCLARO, /**< Color gris claro */
    GRIS, /**< Color gris oscuro */
    AZULCLARO, /**< Color azul cielo */
    VERDECLARO, /**< Color verde claro */
    AGUAMARINACLARO, /**< Color azul verde claro */
    ROJOCLARO, /**< Color rojo claro */
    MAGENTA, /**< Color rosa fuerte */
    AMARILLOCLARO, /**< Color amarillo claro */
    BLANCO /**< Color blanco */
};

enum estadoCursor{APAGADO, ENCENDIDO};

enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};

enum Marco {BARRAV=179, ESQUINASUPD=191, ESQUINAINFI, BARRAH=196, ESQUINAINFD=217, ESQUINASUPI};

/** \brief Función que Imprime un Marco Simple
 *
 * \param Ancho Ancho del Marco
 * \param Alto Altura del Marco
 * \param x Porsición en x
 * \param y Posición en y
 *
 */
void Marco(int Ancho, int Alto, int x, int y);

/** \brief Función que Establece el Color del Texto y de Fondo
 *
 * \param colorFondo Color del Fondo del Texto basandose en "enum Color"
 * \param colorTexto Color del Texto basandose en "enum Color"
 *
 */
void EstablecerColor(Color colorFondo, Color colorTexto);

/** \brief Funcion que mueve al Cursor a la Coordenada (x,y)
 *
 * \param x Posición en x
 * \param y Posición en y
 */
void gotoxy(short x,short y);

 /** \brief Función que Determina el tamaño de la Ventana de la Consola
  *
  * \param Ancho Ancho de la Ventana
  * \param Alto Altura de la Ventana
  */
void TamVentana(int Ancho, int Alto);

/** \brief Función que Determina el estado y el modo del Cursor
 *
 * \param estado Establece el Cursor a Apagado o Encendido
 * \param modo Establece el grosor del Cursor
 */
void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);
