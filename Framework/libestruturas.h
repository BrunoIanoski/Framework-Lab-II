#ifndef LIBESTRUTURAS_H
#define LIBESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int valor;
  struct Node* proximo;
} Node;

typedef struct Fila { 
  Node* inicio;
  Node* fim;
} Fila;

void inserir(Fila* fila, int valor);
int remover(Fila* fila);
void visualizar(Fila* fila);
void liberar_fila(Fila* fila);

#endif