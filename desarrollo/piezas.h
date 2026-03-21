#ifndef PIEZAS_H
#define PIEZAS_H

extern unsigned short piezas[];

bool hay_colision(unsigned short pieza, int col, int fila);
void fijar_pieza();
void nueva_pieza(int indice);

#endif // PIEZAS_H
