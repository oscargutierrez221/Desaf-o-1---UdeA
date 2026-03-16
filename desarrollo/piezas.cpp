#include "piezas.h"
#include <iostream>
using namespace std;

// Definición de las piezas clásicas de Tetris usando números hexadecimales
unsigned short piezas[] = {
    0x0F00, // I: 0000 1111 0000 0000
    0x0660, // O: 0000 0110 0110 0000
    0x0720, // T: 0000 0111 0010 0000
    0x0360, // S: 0000 0011 0110 0000
    0x0630, // Z: 0000 0110 0011 0000
    0x0710, // J: 0000 0111 0001 0000
    0x0740  // L: 0000 0111 0100 0000
};

// Función para imprimir la pieza en consola
void imprimir(unsigned short pieza) {
  string salida = "";
  for (int i = 0; i < 16; i++) {
    if (pieza & (1 << (15 - i)))
      salida += "#";
    else
      salida += ".";
    if ((i + 1) % 4 == 0)
      salida += "\n";
  }
  cout << salida << endl;
}
