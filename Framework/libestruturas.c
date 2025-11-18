#include "libestruturas.h"
#include <string.h>

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

void liberar_fila(Fila* fila) {
  Node* atual = fila->inicio;
  Node* proximo;
  while (atual != NULL) {
      proximo = atual->proximo;
      free(atual); // Libera o nó atual
      atual = proximo;
  }
  fila->inicio = NULL;
  fila->fim = NULL;
}

Fila* criarFila() {
  Fila* fila = (Fila*)malloc(sizeof(Fila)); 
  fila->inicio = NULL; 
  fila->fim = NULL; 
  return fila;
}

void filaParaString(Fila* fila, char* saida) {
    saida[0] = '\0';
    Node* atual = fila->inicio;
    char temp[30];

    while (atual != NULL) {
        sprintf(temp, "%d", atual->valor);
        strcat(saida, temp);
        if (atual->proximo != NULL) {
            strcat(saida, ",");
        }
        atual = atual->proximo;
    }
}

// Funções de Pilha
Pilha* criarPilha() {
  Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
  pilha->topo = NULL;
  return pilha;
}

void push(Pilha* pilha, int valor) {
  NodeP* novoNo = (NodeP*)malloc(sizeof(NodeP));
  novoNo->dado = valor;
  novoNo->prox = pilha->topo;
  pilha->topo = novoNo;
}


int pop(Pilha* pilha) {
  if (pilha->topo == NULL) {
      printf("\n > Pilha vazia! Não é possível desempilhar.\n");
      return -1;
  }
  NodeP* temp = pilha->topo;
  int valor = temp->dado;
  pilha->topo = pilha->topo->prox;
  free(temp);
  return valor;
}


int top(Pilha* pilha) {   
  if (pilha->topo == NULL) {
      printf("Erro: pilha vazia\n");
      return -1; 
  }
  return pilha->topo->dado;
}


void liberar_pilha(Pilha* pilha) {
  NodeP* atual = pilha->topo;
  NodeP* proximo;
  while (atual != NULL) {
    proximo = atual->prox;
    free(atual); // Libera o nó atual
    atual = proximo;
  }
  pilha->topo = NULL;
}

void pilhaParaString(Pilha *pilha, char *saida) {
  saida[0] = '\0';
    NodeP* atual = pilha->topo;
    char temp[30];

    while (atual != NULL) {
        sprintf(temp, "%d", atual->dado);
        strcat(saida, temp);
        if (atual->prox != NULL) {
            strcat(saida, ",");
        }
        atual = atual->prox;
    }
}