#include <stdio.h>
#include "minhalib.h"

int main() {
    printf("==== TESTE ====\n\n");

    printf("Matematica:\n");
    printf("5 + 3 = %d\n", soma(5,3));
    printf("10 - 4 = %d\n", subtracao(10,4));
    printf("6 * 7 = %d\n", multiplicacao(6,7));
    printf("15 / 3 = %.2f\n", divisao(15,3));

    return 0;
}