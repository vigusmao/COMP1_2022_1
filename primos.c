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
    while (1) {
        printf("\nDigite um inteiro positivo: ");
        int numero;
        scanf("%d", &numero);

        if (numero < 1) {
            break;         
        }
 
        char resultado = eh_primo(numero);
        if (resultado == 1) {
            printf("\nO numero %d eh primo!\n", 
                numero);
        } else {
            printf("\nO numero %d NAO eh primo!\n",
                numero);  
        }
    }
   
    return 0;
}
