//libestruturas.h        (libfila.h  e libpilha.h)

#ifndef LIBESTRUTURAS_H
#define LIBESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//Estrutura do nó
typedef struct Node {
  int valor;
  struct Node* proximo;
} Node;

//Estrutura Fila
typedef struct Fila { 
  Node* inicio;
  Node* fim;
} Fila;

//Funções FILA
Fila* criarFila();
void inserir(Fila* fila, int valor);
int remover(Fila* fila);
void filaParaString(Fila *fila, char *saida); //transforma a fila em string

//Estrutura Pilha
typedef struct {
    Node* topo;
} Pilha;

//Funções PILHA
//Função criar a pilha
Pilha* criarPilha();

//Função inserir valor int na Pilha
void push(Pilha* pilha, int valor);

//Função remover o topo da pilha
int pop(Pilha* pilha);

//Função verificar o topo da pilha
int top(Pilha* pilha);

//Função que transforma a pilha em string
void pilhaParaString(Pilha *pilha, char *saida); 

#endif