//libtest.h          (libtestfila.h e libtestpilha.h)
#ifndef LIBTEST_H
#define LIBTEST_H

#include <stdio.h>
#include <string.h>
#include "libestruturas.h"

// Estrutura de uma linha de teste
typedef struct {
    char operacao[20];  // "PUSH", "POP", "TOP", "INSERIR" e "REMOVER"
    int valor;          // valor usado na operação
    char esperado[100]; // estado esperado (lido na linha de testes)
} Teste;

// Executa teste individual. Retorna 1 se passou, 0 se falhou
int executarTesteFila(Teste* t, Fila* fila, char* resultado);
int executarTestePilha(Teste* t, Pilha* pilha, char* resultado);

void registrarResultado(FILE* out, Teste* t, int sucesso, const char* resultado);


// (opcional) Roda todos os testes de um arquivo de entrada
void rodarTestes(const char* nomeArquivoEntrada, const char* nomeArquivoSaida);

#endif
