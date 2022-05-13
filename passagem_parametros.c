#include<stdio.h>

void faca_algo(int x) {  // passagem por VALOR
    x = 500;
    x++;
    x /= 3;
    printf("\n x = %d", x);
}

void faca_outra_coisa(int* ref) {  // passagem por REFERENCIA
    printf("\n ponteiro ref = %ld", (long) ref);
    printf("\n valor apontado por ref = %d", *ref);
    *ref = 12345;  
}

int main() {

   int numero = 10;
   faca_algo(numero);
   printf("\n numero = %d", numero);

   faca_outra_coisa(&numero);
   printf("\n endereco do numero = %ld", (long) &numero);
   printf("\n numero = %d", numero);

   printf("\n\n");

   return 0;
}





 
   
