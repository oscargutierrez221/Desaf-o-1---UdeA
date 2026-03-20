#ifndef PIEZAS_H
#define PIEZAS_H

#include "panel_control.h" // trae: ancho, alto, tablero, pieza_actual, pieza_col, pieza_fila

extern unsigned short piezas[];

bool hay_colision(unsigned short pieza, int col, int fila);
void fijar_pieza();
void nueva_pieza(int indice);

#endif // PIEZAS_H
