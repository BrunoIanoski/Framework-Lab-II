//libestruturas.c           (libpilha.c e libfila.c)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libestruturas.h"

//Funções Fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

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

void visualizarFila(Fila* fila) {
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

//Função que transforma fila em string

 void filaParaString(Fila* fila, char* saida) {
    saida[0] = '\0';  // inicializa string vazia
    Node* atual = fila->inicio;
    char temp[30];    // string temporária

    while (atual != NULL) {
        sprintf(temp, "%d", atual->valor);
        strcat(saida, temp);  //concatena temp com saída
        if (atual->proximo != NULL)
            strcat(saida, ","); //adiciona vírgula entre os valores e sem espaços
        atual = atual->proximo;
    }
}

//Funções Pilha

//criar pilha
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

//inserir elementos na pilha
void push(Pilha* pilha, int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

//remover elemento no topo da pilha
int pop(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("\n > Pilha vazia! Não é possível desempilhar.\n");
        return -1;
    }
    Node* temp = pilha->topo;
    int valor = temp->valor;
    pilha->topo = pilha->topo->proximo;
    free(temp);
    return valor;
}

//Verificar o elemento no topo da pilha
int top(Pilha* pilha)
{   
    if (pilha->topo == NULL) {
        printf("Erro: pilha vazia\n");
        return -1; 
    }
    return pilha->topo->valor;
}

//Função para a transformar a pilha em uma string

void pilhaParaString(Pilha *pilha, char *saida) //percorre a pilha e cria string, do topo até a base
 {
    saida[0] = '\0'; // inicializa a string
    Node* atual = pilha->topo;
    char temp[30]; //string temporária que guarda a versão em texto do valor atual da pilha.
    while (atual != NULL) {
        sprintf(temp, "%d", atual->valor);
        strcat(saida, temp);//concatena temp na saída principal
        if (atual->proximo != NULL)
            strcat(saida, ",");//acrescenta vírgula entre valores
        atual = atual->proximo;
    }
}

void visualizarPilha(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("\n > Pilha vazia!\n");
        return;
    }

    printf("\n > Elementos na pilha (topo -> base):\n\n");
    Node* atual = pilha->topo;
    while (atual != NULL) {
        printf("  %d\n", atual->valor);
        atual = atual->proximo;
    }
}

