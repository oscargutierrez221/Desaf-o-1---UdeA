#include "fin_juego.h"
#include "panel_control.h"
#include "piezas.h"

// El juego termina cuando la nueva pieza que acaba de aparecer ya colisiona en
// su posicion inicial
bool juego_terminado() {
  return hay_colision(pieza_actual, pieza_col, pieza_fila);
}

void eliminar_filas_llenas() {
  // Recorrer el tablero de abajo hacia arriba
  for (int fila = alto - 1; fila >= 0; fila--) {

    bool fila_llena = true;
    for (int columna = 0; columna < ancho; columna++) {
      if (!tablero[fila][columna]) { // si hay una celda libre, la fila no esta llena
        fila_llena = false;
        break;
      }
    }

    if (fila_llena) {
      for (int fila_desplazada = fila; fila_desplazada > 0; fila_desplazada--) {
        for (int columna = 0; columna < ancho; columna++) {
          tablero[fila_desplazada][columna] = tablero[fila_desplazada - 1][columna]; // copiar la fila de arriba
        }
      }
      // La fila 0 queda completamente vacia
      for (int columna = 0; columna < ancho; columna++) {
        tablero[0][columna] = false;
      }
      // Volver a revisar la misma fila 'fila' porque ahora tiene el contenido de
      // la de arriba
      fila++;
    }
  }
}
