#include "piezas.h"
#include <iostream>

using namespace std;

// Definimos las piezas como enteros de 16 bits (4x4)

// Ejemplo de piezas clásicas
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
        if (pieza & (1 << (15 - i))) salida += "#";
        else salida += ".";
        if ((i+1) % 4 == 0) salida += "\n";
    }
    cout << salida << endl;
}


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

int sentido() {
    // Selección de la primera pieza del arreglo
    int idx = 0;
    unsigned short pieza = piezas[idx];

    cout << "Pieza seleccionada:\n";
    imprimir(pieza);

    cout << "Rotada a la derecha:\n";
    imprimir(rotarDerecha(pieza));

    return 0;
}




