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
    
    FILE *out = fopen(filename_out, "a");
    if (!out) {
        perror("Erro ao abrir arquivo de saída");
        fclose(f);
        return;
    }

    char buffer[256];
    char comando[20];
    char esperado[100];
    char valor_str[20];
    while (fgets(buffer, sizeof(buffer), f)) {
        if (sscanf(buffer, "%19s %19s %99[^\n]", comando, valor_str, esperado) != 3){
            continue;
        }
        esperado[strcspn(esperado, "\r\n")] = '\0';
        strcpy(t->operacao, comando);
        strcpy(t->esperado, esperado);
        if (strcmp(valor_str, "_") != 0)
            t->valor = atoi(valor_str);
        else
            t->valor = 0; 
        char resultado[256] = "";
        int sucesso = executarTeste(t, fila, pilha, resultado);
        registrarResultado(out, t, sucesso, resultado);
    }
    
    fclose(out);

    if (ferror(f)) {
        perror("Erro durante a leitura");
    }

    fclose(f);
}


int main(int argc, char *argv[]) {
    Fila* fila = criarFila();
    Pilha* pilha = criarPilha();
    
    Teste t;
    
    char *filename_out = "resultado.txt";
    
    // Validação dos argumentos
    if (argc < 2) {
        write_text_overwrite(filename_out);
        append_text(filename_out, "ARQUIVO DE ENTRADA NÃO ENCONTRADO");
        return 1;
    }
    if (argc >= 3) {
        filename_out = argv[2];
    }
    
    write_text_overwrite(filename_out);

    // Manipulação das funções

    read_text(argv[1], &t, fila, filename_out, pilha);
    
    liberar_pilha(pilha);
    free(pilha);

    liberar_fila(fila);    
    free(fila);

    return 0;
}