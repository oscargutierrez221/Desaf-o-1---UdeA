#include "movimiento.h"
#include "piezas.h"
#include "panel_control.h"

// Mueve la pieza una columna a la izquierda (tecla A)
unsigned short moverIzquierda(unsigned short pieza) {
  if (!hay_colision(pieza, pieza_col - 1, pieza_fila))
    pieza_col--;
  return pieza;
}

// Mueve la pieza una columna a la derecha (tecla D)
unsigned short moverDerecha(unsigned short pieza) {
  if (!hay_colision(pieza, pieza_col + 1, pieza_fila))
    pieza_col++;
  return pieza;
}

// Mueve la pieza una fila hacia abajo (tecla S)
// Devuelve pieza sin cambios; el caller detecta si pieza_fila cambio o no
unsigned short moverAbajo(unsigned short pieza) {
  if (!hay_colision(pieza, pieza_col, pieza_fila + 1))
    pieza_fila++;
  return pieza;
}
