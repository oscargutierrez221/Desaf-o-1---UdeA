#ifndef PANEL_CONTROL_H
#define PANEL_CONTROL_H

#include <cstdint>

// Variables globales del tablero
extern uint8_t** filas;
extern int ancho;
extern int alto;
extern int bytes_x_fila;

int panel_control();
void validar_dimensiones();
void imprimir_tablero();

#endif // PANEL_CONTROL_H
