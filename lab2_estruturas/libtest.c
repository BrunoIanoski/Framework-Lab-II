//libtest.c                   (libtestfila.c e libtestpilha)
#include <stdio.h>
#include <string.h>
#include "libestruturas.h"
#include "libtest.h"

//função executar teste. Retorna 1 (sucesso)  ou 0 (falha).

int executarTestePilha(Teste* t, Pilha* pilha, char* resultado){  
    int sucesso = 0;
    
    if (strcmp(t->operacao, "PUSH") == 0) {
        push(pilha, t->valor);
        pilhaParaString(pilha, resultado);
        sucesso = (strcmp(resultado, t->esperado) == 0);
    }

    else if (strcmp(t->operacao, "POP") == 0) {
        pop(pilha);
        if (pilha->topo == NULL)
            strcpy(resultado, "null");
        else
            pilhaParaString(pilha, resultado);

        sucesso = (strcmp(resultado, t->esperado) == 0);
    }

    else if (strcmp(t->operacao, "TOP") == 0) {
        if (pilha->topo == NULL)
            strcpy(resultado, "null");
        else
            sprintf(resultado, "%d", top(pilha));  // resultado só o valor do topo

        sucesso = (strcmp(resultado, t->esperado) == 0);
    }
    else {
        strcpy(resultado, "operacao_invalida");
        sucesso = 0;
    }
}
int executarTesteFila(Teste* t, Fila* fila, char* resultado) {

      int sucesso = 0;
     if (strcmp(t->operacao, "INSERIR") == 0) {
        inserir(fila, t->valor);
        filaParaString(fila, resultado);
        sucesso = (strcmp(resultado, t->esperado) == 0);
    }

    else if (strcmp(t->operacao, "REMOVER") == 0) {
         int removido = remover(fila); // remove o primeiro

         if (fila->inicio == NULL)
            strcpy(resultado, "null");
         else
            filaParaString(fila, resultado);// gera string da fila após a remoção

        sucesso = (strcmp(resultado, t->esperado) == 0);

        }
    else {
        strcpy(resultado, "operacao_invalida");
        sucesso = 0;
    }
    return sucesso;
}

//Função  que registra resultado em arquivo de saída.

void registrarResultado(FILE* out, Teste* t, int sucesso, const char* resultado) 
{
    fprintf(out, "%s ", t->operacao);
    
    if (strcmp(t->operacao, "PUSH") == 0)  // Para PUSH mostra o valor empilhado
        fprintf(out, "%d ", t->valor);
    else if (strcmp(t->operacao, "TOP") == 0)
        fprintf(out, "_ ");
    else if (strcmp(t->operacao, "POP") == 0) {
        fprintf(out, "_ ");  // POP não recebe valor, só remove o topo
        }
    else if (strcmp(t->operacao, "inserir") == 0) // Para inserir, mostra o valor inserido
        fprintf(out, "%d ", t->valor);
   
    else if (strcmp(t->operacao, "remover") == 0) // para remover ou ver inicio não há valor
        fprintf(out, "_ ");
     else {
        fprintf(out, "_ ");  // operações desconhecidas
    }
    // Mostra o esperado e o obtido
    fprintf(out, "(esperado=%s, obtido=%s) -> %s\n",
            t->esperado,
            resultado,
            sucesso ? "SUCESSO" : "FALHA");
}

// Função que roda o teste com os argumentos de comando
void rodarTestes(const char* nomeArquivoEntrada, const char* nomeArquivoSaida) {
    FILE* in = fopen(nomeArquivoEntrada, "r");
    if (!in) {
        printf("Erro ao abrir arquivo de testes.\n");
        return;
    }

    FILE* out = fopen(nomeArquivoSaida, "a"); // usa "a" para append
    if (!out) {
        printf("Erro ao criar arquivo de resultados.\n");
        fclose(in);
        return;
    }

   Fila* fila = criarFila();
    if (!fila) {
        printf("Erro ao criar a fila.\n");
        fclose(in);
        fclose(out);
        return; }

    Pilha* pilha=criarPilha();
    if (!pilha) {
        printf("Erro ao criar pilha.\n");
        fclose(in);
        fclose(out);
        return; }
    
    Teste t;
  while (!feof(in)) 
{
    int lidos = fscanf(in, "%s", t.operacao);  // operações:PUSH POP TOP  INSERIR  REMOVER,
    if (lidos != 1) break; // fim do arquivo ou erro
    
    if (strcmp(t.operacao, "PUSH") == 0) {    // PUSH tem valor inteiro e estado esperado
        fscanf(in, "%d %s", &t.valor, t.esperado); } 
   else {
        fscanf(in, "%s", t.esperado);  // POP ou TOP  só têm estado esperado
        t.valor = 0; // para manter o campo limpo

    if (strcmp(t.operacao, "INSERIR") == 0) {    
        fscanf(in, "%d %s", &t.valor, t.esperado);//tem um valor inteiro e o estado esperado
    } 
    else {  
        fscanf(in, "%s", t.esperado); // remoção só tem estado esperado
        t.valor = 0; // mantém campo limpo
        }
}
    char resultado[100];

    int sucesso;  
    
    if (strcmp(t.operacao, "PUSH") == 0 || strcmp(t.operacao, "POP") == 0 || strcmp(t.operacao, "TOP") == 0) 
    {sucesso = executarTestePilha(&t, pilha, resultado);}
    else if (strcmp(t.operacao, "INSERIR") == 0 || strcmp(t.operacao, "REMOVER") == 0)
    {
    sucesso = executarTesteFila(&t, fila, resultado);}
    else {
    printf("Operação desconhecida: %s\n", t.operacao);
    sucesso = 0;}

    registrarResultado(out, &t, sucesso, resultado);
}


    fclose(in);
    fclose(out);
}
