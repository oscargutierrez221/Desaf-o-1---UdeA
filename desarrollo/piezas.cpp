#include "piezas.h"
#include "panel_control.h"

unsigned short piezas[] = {
    0x0F00, // I: 0000 1111 0000 0000
    0x0660, // O: 0000 0110 0110 0000
    0x0720, // T: 0000 0111 0010 0000
    0x0360, // S: 0000 0011 0110 0000
    0x0630, // Z: 0000 0110 0011 0000
    0x0710, // J: 0000 0111 0001 0000
    0x0740  // L: 0000 0111 0100 0000
};

unsigned short pieza_actual = 0;
int pieza_col = 0;
int pieza_fila = 0;

bool hay_colision(unsigned short pieza, int col, int fila) {
  for (int fila_local = 0; fila_local < 4; fila_local++) {
    for (int columna = 0; columna < 4; columna++) {
      if (pieza & (1 << (15 - (fila_local * 4 + columna)))) {
        int fila_tablero = fila + fila_local;
        int columna_tablero = col + columna;

        // Choca con borde izquierdo, derecho o fondo
        if (columna_tablero < 0 || columna_tablero >= ancho || fila_tablero >= alto)
          return true;

        // Choca con una celda ya ocupada del tablero
        if (fila_tablero >= 0 && tablero[fila_tablero][columna_tablero])
          return true;
      }
    }
  }
  return false;
}

void fijar_pieza() {
  for (int fila_local = 0; fila_local < 4; fila_local++) {
    for (int columna = 0; columna < 4; columna++) {
      if (pieza_actual & (1 << (15 - (fila_local * 4 + columna)))) {
        int fila_tablero = pieza_fila + fila_local;
        int columna_tablero = pieza_col + columna;
        if (fila_tablero >= 0 && fila_tablero < alto && columna_tablero >= 0 && columna_tablero < ancho)
          tablero[fila_tablero][columna_tablero] = true; // marcar celda como ocupada
      }
    }
  }
}

void nueva_pieza(int indice) {
  pieza_actual = piezas[indice % 7];
  pieza_col = (ancho / 2) - 2; // Centrada
  pieza_fila = 0;              // EMpieza arriba
}
