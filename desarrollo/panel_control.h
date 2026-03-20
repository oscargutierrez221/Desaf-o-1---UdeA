#ifndef PANEL_CONTROL_H
#define PANEL_CONTROL_H

// Variables globales del tablero
extern int ancho;
extern int alto;
extern bool **tablero;

// Variables de la pieza activa (definidas en piezas.cpp)
extern unsigned short pieza_actual;
extern int pieza_col;
extern int pieza_fila;

void validar_dimensiones();
void imprimir_tablero();
void destruir_tablero();

#endif // PANEL_CONTROL_H
