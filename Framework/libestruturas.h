#ifndef LIBESTRUTURAS_H
#define LIBESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>

// Struct Fila
typedef struct Node {
  int valor;
  struct Node* proximo;
} Node;

typedef struct Fila { 
  Node* inicio;
  Node* fim;
} Fila;

// Struct Pilha
typedef struct NodeP {
  int dado;
  struct NodeP* prox;
} NodeP;

typedef struct {
  NodeP* topo;
} Pilha;


// Funções Fila
Fila* criarFila();
void inserir(Fila* fila, int valor);
int remover(Fila* fila);
void visualizar(Fila* fila);
void liberar_fila(Fila* fila);
void filaParaString(Fila *fila, char *saida);

// Funções Pilha
Pilha* criarPilha();
void push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
int top(Pilha* pilha);
void pilhaParaString(Pilha *pilha, char *saida);
void liberar_pilha(Pilha* pilha);

#endif