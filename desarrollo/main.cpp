#include "fin_juego.h"
#include "movimiento.h"
#include "panel_control.h"
#include "piezas.h"
#include <iostream>
using namespace std;

int main() {

  validar_dimensiones();

  int indice = 0;
  nueva_pieza(indice); // Nueva pieza

  cout << "\nControles: A = izquierda  D = derecha  S = bajar  Q = salir\n\n";
  imprimir_tablero();

  char tecla;
  while (true) {
    cout << "Tecla: ";
    cin >> tecla;

    int fila_antes = pieza_fila; // guardar posicion antes de mover

    switch (tecla) {
    case 'a':
    case 'A':
      moverIzquierda(pieza_actual);
      break;
    case 'd':
    case 'D':
      moverDerecha(pieza_actual);
      break;
    case 's':
    case 'S':
      moverAbajo(pieza_actual);
      if (pieza_fila == fila_antes) {
        fijar_pieza();
        eliminar_filas_llenas(); // eliminar filas completas antes de la
                                 // siguiente pieza
        indice++;
        nueva_pieza(indice);
        cout << "[Nueva pieza!]\n";
        if (juego_terminado()) {
          destruir_tablero();
          cout << "\n=== FIN DEL JUEGO ===\n"; // Si termino
          return 0;
        }
      }
      break;
    case 'q':
    case 'Q':
      cout << "Saliendo...\n";
      destruir_tablero();
      return 0;
    default:
      cout << "Tecla no reconocida.\n";
      continue;
    }

    imprimir_tablero();
  }

  destruir_tablero();
  return 0;
}
