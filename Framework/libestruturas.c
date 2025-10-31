#include "libestruturas.h"

typedef struct Node {
  int valor;
  struct Node* proximo;
} Node;

typedef struct {
  Node* inicio;
  Node* fim;
} Fila;

void inserir(Fila* fila, int valor) {
  Node* novoNode = (Node*)malloc(sizeof(Node));
  novoNode->valor = valor;
    novoNode->proximo = NULL;
    if (fila->fim == NULL) {
      fila->inicio = novoNode;
      fila->fim = novoNode;
    }
    else {
      fila->fim->proximo = novoNode;
      fila->fim = novoNode;
    }
}

void visualizar(Fila* fila) {
  if (fila->inicio == NULL) {
    printf("\n > Fila vazia!\n");
  }
  else {
    Node* atual = fila->inicio;
    printf("\n > Elementos inseridos na fila: \n\n\t");
    while (atual != NULL) {
      printf(" -> %d", atual->valor);
      atual = atual->proximo;
    }
  }
}

int remover(Fila* fila) {
  if (fila->inicio == NULL) {
    printf("\n > Fila vazia! Nao e possivel remover.\n");
    return -1;
  }
  Node* temp = fila->inicio;
  int valor = temp->valor;
  fila->inicio = fila->inicio->proximo;
  if (fila->inicio == NULL){
    fila->fim = NULL;
  } 
  free(temp);
  return valor;
}