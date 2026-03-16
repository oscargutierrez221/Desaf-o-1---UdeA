#include "movimiento.h"

// Rotación a la derecha (90°) usando operaciones de bits
unsigned short rotarDerecha(unsigned short pieza) {
    unsigned short resultado = 0;
    for (int fila = 0; fila < 4; fila++) {
        for (int col = 0; col < 4; col++) {
            int bitOriginal = (pieza >> (15 - (fila*4 + col))) & 1;
            int nuevaFila = col;
            int nuevaCol = 3 - fila;
            int nuevaPos = nuevaFila*4 + nuevaCol;
            resultado |= (bitOriginal << (15 - nuevaPos));
        }
    }
    return resultado;
}
