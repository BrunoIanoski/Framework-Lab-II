#include <stdio.h>
#include <stdlib.h>
#include "libestruturas.h"

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
void read_text(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Erro ao abrir arquivo para leitura");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f)) {
        printf("%s", buffer); // fgets já traz o '\n' se houver
    }

    if (ferror(f)) {
        perror("Erro durante a leitura");
    }

    fclose(f);
}


int main(int argc, char *argv[]) {
    char *filename = "resultado.txt";
    
    if (argv[1] == NULL) {
        append_text(filename, "ARQUIVO DE ENTRADA NÃO ENCONTRADO");
        return 1;
    }

    if (argv[2] == NULL) {
        write_text_overwrite(filename);
    }

    else {
        filename = argv[2];
    }

    return 0;
}