#include <stdio.h>
#include <stdlib.h>

char eh_primo(int x) {
    if (x < 2) {
        return 0;  // nao eh primo!
    }

    int div;
    for (div = 2; div <= x-1; div++) {
        if (x % div == 0) {  // encontrei divisor!
            return 0;  // nao eh primo!!!
        }
    }
    
    return 1;  // eh primo!!!
}


int main() {
    printf("\nDigite um inteiro positivo: ");
    int limite;
    scanf("%d", &limite);

    int numero;
    for (numero = 2; numero <= limite; numero++) {
        if (eh_primo(numero)) {
            printf("\n%d", numero); 
        }
    }
   
    printf("\n\n");

    return 0;
}
