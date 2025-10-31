#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila, aquilo que guarda a 
// informação que se deseja e também o endereço do próximo da fila.
typedef struct No { // Precisa colocar o nome antes da chave
    int dado; // guardar o dado inteiro
    struct No* proximo; // variável do tipo {struct No*}. Ex: {struct No*} var. Variável do tipo que aponta para a estrutura, no caso da variável 'proximo', armazena o proximo dado.
} No;

// Estrutura da fila, ela precisa ter ponteiros guardar o endereço 
// de memória do início e fim da fila, que são do tipo No.
typedef struct {
    No* inicio; 
    No* fim;
} Fila;

// ----- INÍCIO DA ÁREA DE DECLARAÇÃO DAS FUNÇÕES ----- //
Fila* criarFila();
void inserir(Fila* fila, int valor);
int remover(Fila* fila);
void visualizar(Fila* fila);
//void liberarFila(Fila* fila);
int mostrarMenu();
void esperarEnter();
// ----- FIM DA ÁREA DE DECLARAÇÃO DAS FUNÇÕES ----- //


// ===== INÍCIO DO PROGRAMA PRINCIPAL ===== //
int main() {
    Fila* minhaFila = criarFila(); // variável do tipo struct Fila* 'minhaFila' chama a função (criarFila)
    int escolha, valor;

    do {
        escolha = mostrarMenu(); // Função basica de menu
        switch (escolha) {
            case 1: // Caso digite 1
                printf("\n > Digite um valor para inserir: ");
                scanf("%d", &valor); // Guarda o valor
                inserir(minhaFila, valor); // Chama a função para inserior o valor na vila, 
                break;
            case 2:
                valor = remover(minhaFila);
                if (valor != -1) {
                    printf("\n > Removido: %d\n", valor);
                    esperarEnter();
                }
                break;
            case 3:
                visualizar(minhaFila);
                break;
            case 4:
                
                // liberarFila(minhaFila);
                
                printf("\n > Saindo...\n\n");
                break;
            default:
                printf("\n > Opção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 4);

    return 0;
}
// ===== FIM DO PROGRAMA PRINCIPAL ===== //


// ----- INÍCIO DA ÁREA DE DEFINÇÃO DAS FUNÇÕES ----- //
/**
 * @brief: Função para criar uma nova fila, encontra espaço na memória e aloca.
 * @return Fila*: retorna um ponteiro do tipo Fila com o endereço de memória alocado.
 */
Fila* criarFila() { // Cria função do tipo Fila* para retornar o ponteiro
    Fila* fila = (Fila*)malloc(sizeof(Fila)); // Cria a variavel fila do tipo Fila* e armazena espaço (malloc)
    fila->inicio = NULL; // Define o inicio da fila como NULL
    fila->fim = NULL; // Define o fim da fila como NULL
    return fila;
}

/**
 * @brief: Função para inserir um elemento na fila, aloca memória para o novo nó,
 * guarda o valor dentro do nó e ajusta a fila.
 * 
 * @param fila: deve conter o endereço de memória do tipo Fila já alocado.
 * @param valor: deve conter um valor do tipo inteiro.
 * @return void: sen retorno
 */
void inserir(Fila* fila, int valor) { // Argumentos Fila* fila (onde foi criado na função criarFila com NULL), int valor é o dado inserido
    No* novoNo = (No*)malloc(sizeof(No)); // Função novoNo do tipo No*, onde é armazenado memória (malloc)
    novoNo->dado = valor; // o dado recebe o valor inserido 
    novoNo->proximo = NULL; // e o proximo valor do nó recebe NULL (não foi inserido nada(um valor por vez))
    if (fila->fim == NULL) { // Se o fim da fila for NULL o inicio e o fim irá receber o novo valor inserido
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else { // Senão, o proximo se torna o valor 
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

/**
 * @brief Função para remover um elemento da fila.
 * 
 * @param fila: deve conter o endereço de memória do tipo Fila já alocado.
 * @return int: retorna o valor inteiro da informação removida.
 */
int remover(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("\n > Fila vazia! Não é possível remover.\n");
        esperarEnter();
        return -1;
    }
    No* temp = fila->inicio;
    int valor = temp->dado;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return valor;
}

/**
 * @brief Função para visualizar os elementos da Fila.
 * 
 * @param fila: deve conter o endereço de memória do tipo Fila já alocado.
 * @return void: sem retorno.
 */
void visualizar(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("\n > Fila vazia!\n");
    }else{
        No* atual = fila->inicio;
        printf("\n > Elementos na fila: \n\n\t");
        while (atual != NULL) {
            printf("%d -> ", atual->dado);
            atual = atual->proximo;
        }
    }
    esperarEnter();
}

/**
 * @brief Função para liberar toda a memória alocada para a fila e cada nó
 * 
 * @param fila: deve conter o endereço de memória da do tipo Fila.
 * @return void: sem retorno
 */
//void liberarFila(Fila* fila) {
    // codificar aqui!
//}

/**
 * @brief Função para mostrar o menu e obter a escolha do usuário.
 * 
 * @return int: retorna um inteiro contendo a opção escolhida pelo usuário
 */
int mostrarMenu() { // Função básica de menu
    int escolha;
    system("clear || cls");
    printf("\n### FILA ###\n");
    printf("\n### Menu de Opções ###\n\n");
    printf("\t1. Inserir na fila\n");
    printf("\t2. Remover da fila\n");
    printf("\t3. Visualizar a fila\n");
    printf("\t4. Sair\n\n");
    printf("\tEscolha uma opção: ");
    scanf("%d", &escolha);
    return escolha;
}

/**
 * @brief Função para limpar '\n' indesejados e parar o programa até que
 * o usuário tecle 'enter' para continuar.
 *
 * return void: sem retorno.
 */
void esperarEnter() {
    while (getchar() != '\n'); // limpa buffer
    printf("\n\n Tecle [enter] para continuar...");
    getchar();
}
// ----- FIM DA ÁREA DE DEFINÇÃO DAS FUNÇÕES ----- //