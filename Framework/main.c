#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void read_text(const char *filename, Fila* fila, char *filename_out) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Erro ao abrir arquivo para leitura");
        return;
    }

    char buffer[256];
    char comando[256];
    char saida[256];
    int valor, i = 1;
    while (fgets(buffer, sizeof(buffer), f)) {
        sscanf(buffer, "%19s %d", comando, &valor);
        if (strcmp(comando, "inserir") == 0){
            inserir(fila, valor);
            sprintf(saida, "Teste %d: inserir(%d) -> OK", i, valor);
        }
        else if (strcmp(comando, "remover") == 0){
            int valor_removido = remover(fila);
            sprintf(saida, "Teste %d: remover() = %d -> OK", i, valor_removido);
        }
        else if (strcmp(comando, "visualizar") == 0){
            visualizar(fila);
            sprintf(saida, "Teste %d: visualizar -> OK", i);
        }
        
    append_text(filename_out, saida);
    i++;
    }

    if (ferror(f)) {
        perror("Erro durante a leitura");
    }

    fclose(f);
}


int main(int argc, char *argv[]) {
    Fila* fila = (Fila*)malloc(sizeof(Fila)); 
    fila->inicio = NULL; 
    fila->fim = NULL; 

    if (fila == NULL) {
        perror("Erro ao alocar memoria para Fila");
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

    read_text(argv[1], fila, filename_out);

    liberar_fila(fila);    
    free(fila);

    return 0;
}