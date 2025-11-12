#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libestruturas.h"
#include "libtest.h"

void write_text_overwrite(char *filename) {
    FILE *f = fopen(filename, "w"); // "w" cria ou sobrescreve
    if (!f) {
        perror("Erro ao abrir arquivo para escrita");
        return;
    }
    fclose(f);
}

/* Adiciona texto no final do arquivo */
void append_text(char *filename, char *text) {
    FILE *f = fopen(filename, "a"); // "a" abre para append
    if (!f) {
        perror("Erro ao abrir arquivo para append");
        return;
    }
    fprintf(f, "%s\n", text);
    fclose(f);
}

/* Lê todo o arquivo de texto e imprime na tela */
void read_text(const char *filename, Teste* t, Fila* fila, char *filename_out, Pilha* pilha) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Erro ao abrir arquivo para leitura");
        return;
    }

    char buffer[256];
    char comando[256];
    char saida[256];
    int valor;
    while (fgets(buffer, sizeof(buffer), f)) {
        sscanf(buffer, "%19s %d %s", comando, &valor, &saida);
        t.operacao = comando;
        t.valor = valor;
        t.resultado = saida;
        char* resultado[0] = "\0";
        executarTeste(t ,fila, pilha, resultado);
        printf(resultado);
    }
        
    append_text(filename_out, saida);

    if (ferror(f)) {
        perror("Erro durante a leitura");
    }

    fclose(f);
}


int main(int argc, char *argv[]) {
    Fila* fila = criarFila();
    Pilha* pilha = criarPilha();
    Teste* t;

    if (fila == NULL) {
        perror("Erro ao alocar memoria para Fila");
        return 1;
    }
    
    if (pilha == NULL) {
        perror("Erro ao alocar memoria para pilha");
        return 1;
    }

    char *filename_out = "resultado.txt";
    
    // Validação dos argumentos
    if (argc < 2) {
        write_text_overwrite(filename_out);
        append_text(filename_out, "ARQUIVO DE ENTRADA NÃO ENCONTRADO");
        free(fila);
        return 1;
    }
    if (argc >= 3) {
        filename_out = argv[2];
    }
    
    write_text_overwrite(filename_out);

    // Manipulação das funções

    read_text(argv[1], t, fila, filename_out, pilha);
    
    liberar_pilha(pilha);
    free(pilha);

    liberar_fila(fila);    
    free(fila);

    return 0;
}