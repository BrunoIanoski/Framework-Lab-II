#include "libestruturas.h"
#include "libtest.h"

//função executar teste. Retorna 1 (sucesso)  ou 0 (falha).

int executarTeste(Teste* t, Fila* fila, Pilha* pilha, char* resultado) {
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

    else if (strcmp(t->operacao, "INSERIR") == 0) {
        inserir(fila, t->valor);
        filaParaString(fila, resultado);
        sucesso = (strcmp(resultado, t->esperado) == 0);
    }

    else if (strcmp(t->operacao, "REMOVER") == 0) {
        int removido = remover(fila); // remove o primeiro

        if (fila->inicio == NULL) {
            strcpy(resultado, "null");
            sucesso = (strcmp(resultado, t->esperado) == 0);
        }
        else {
            filaParaString(fila, resultado);// gera string da fila após a remoção
            sucesso = (strcmp(resultado, t->esperado) == 0);
        }
    }

    else {
        strcpy(resultado, "operacao_invalida");
        sucesso = 0;
    }
    return sucesso;
}

//Função  que registra resultado em arquivo de saída.

void registrarResultado(FILE* out, Teste* t, int sucesso, const char* resultado) {
    if (strcmp(t->operacao, "PUSH") == 0 || strcmp(t->operacao, "INSERIR") == 0) {
        fprintf(out, "%s %d ", t->operacao, t->valor);
    }
    else {
        fprintf(out, "%s _ ", t->operacao);
    }
    fprintf(out, "(esperado=%s, obtido=%s) -> %s\n",
        t->esperado,
        resultado,
        sucesso ? "SUCESSO" : "FALHA");
}

