#include "panel_control.h"
#include <iostream>

using namespace std;

// Definicion de las variables globales del tablero
uint8_t** filas      = nullptr;
int ancho            = 0;
int alto             = 0;
int bytes_x_fila     = 0;

int panel_control() {
  cout << "\n -- Panel de control -- \n";
  cout << "1. Nuevo juego\n";
  cout << "2. Salir\n";
  cout << "Seleccione una opción: ";
  int opcion;
  cin >> opcion;
  do {
    switch (opcion) {
    case 1:
      cout << "Iniciando juego...\n";
      break;
    case 2:
      cout << "Saliendo...\n";
      break;
    default:
      cout << "Opción inválida.\n";
      break;
    }
  } while (opcion != 2);

  return opcion;
}

void validar_dimensiones() {
  cout << "Ingrese el ancho del tablero (Minimo 8, multiplo de 8): ";
  cin >> ancho;
  while (ancho < 8 || ancho % 8 != 0) {
    cout << "Ancho invalido. Debe ser multiplo de 8 y mayor o igual a 8: ";
    cin >> ancho;
  }
  cout << "Ingrese el alto del tablero (Minimo 8, multiplo de 8): ";
  cin >> alto;
  while (alto < 8 || alto % 8 != 0) {
    cout << "Alto invalido. Debe ser multiplo de 8 y mayor o igual a 8: ";
    cin >> alto;
  }
  cout << "Dimensiones del tablero: " << ancho << " x " << alto << endl;

  // --- Creacion del tablero ---

  bytes_x_fila = ancho >> 3;  // ancho / 8 usando bits

  // 1) Reservar un puntero por cada fila
  filas = new uint8_t*[alto];

  // 2) Para cada fila, reservar los bytes e inicializar en 0
  for (int f = 0; f < alto; f++) {
    filas[f] = new uint8_t[bytes_x_fila];  // espacio para las piezas

    for (int b = 0; b < bytes_x_fila; b++) {
      filas[f][b] = filas[f][b] & 0x00;  // celda vacia
    }
  }
}

void imprimir_tablero() {
  for (int f = 0; f < alto; f++) {
    for (int b = 0; b < bytes_x_fila; b++) {
      // Recorrer los 8 bits del byte, del mas significativo al menos
      for (int bit = 7; bit >= 0; bit--) {
        // Aislar el bit: shift derecho y AND con 1
        if ((filas[f][b] >> bit) & 1) {
          cout << '#';  // celda ocupada por una pieza
        } else {
          cout << '.';  // celda vacia
        }
      }
    }
    cout << '\n';  // nueva linea al terminar la fila
  }
}