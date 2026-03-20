#include "panel_control.h"
#include <iostream>
using namespace std;


// Variables globales del tablero
int ancho = 0;
int alto = 0;
bool **tablero = nullptr;

void validar_dimensiones() {
  // Pedir el ancho del tablero, que segun la guia deben ser multiplos de 8
  cout << "Ingrese el ancho del tablero (minimo 8, multiplo de 8): ";
  cin >> ancho;
  while (ancho < 8 || ancho % 8 != 0) {
    cout << "Invalido. Debe ser multiplo de 8: ";
    cin >> ancho;
  }

  // Lo mismo pero con la altura
  cout << "Ingrese el alto del tablero (minimo 8, multiplo de 8): ";
  cin >> alto;
  while (alto < 8 || alto % 8 != 0) {
    cout << "Invalido. Debe ser multiplo de 8: ";
    cin >> alto;
  }

  // Crear el tablero con un puntero por cada fila
  tablero = new bool *[alto];
  for (int fila = 0; fila < alto; fila++) {
    tablero[fila] = new bool[ancho]; // cada fila tiene 'ancho' celdas
    for (int columna = 0; columna < ancho; columna++) {
      tablero[fila][columna] = false;
    }
  }

  cout << "Tablero de " << ancho << " x " << alto << " creado.\n";
}

void imprimir_tablero() {
  for (int fila = 0; fila < alto; fila++) {
    for (int columna = 0; columna < ancho; columna++) {

      // Verificar si la pieza activa ocupa esta celda
      int fila_relativa = fila - pieza_fila;
      int columna_relativa = columna - pieza_col;
      bool en_pieza = (fila_relativa >= 0 && fila_relativa < 4 && columna_relativa >= 0 && columna_relativa < 4) &&
                      (pieza_actual & (1 << (15 - (fila_relativa * 4 + columna_relativa))));

      if (tablero[fila][columna] || en_pieza)
        cout << '#';
      else
        cout << '.';
    }
    cout << '\n';
  }
}

void destruir_tablero() {
  if (tablero != nullptr) {
    for (int fila = 0; fila < alto; fila++) {
      delete[] tablero[fila]; // liberar cada fila
    }
    delete[] tablero; // liberar el arreglo de punteros
    tablero = nullptr;
  }
}