#include<stdio.h>
#include<stdlib.h>

int main() {

    printf("\nQual o tamanho do array? ");
    int tamanho;              // tamanho: ___?#?#?#?#___
    scanf("%d", &tamanho);    // tamanho: ______20______

    // vamos inicializar o array
    int* numeros;             //  numeros:  _NULL_ 

    // três possibilidades de atribuição para ponteiros

    // (1) anotar o endereço de uma variável que já existe
    numeros = &tamanho;      //   numeros:  __324652376452376__
    printf("\n(1) Copiei o endereço da variável tamanho.");
    printf("\n    numeros = %ld", (long) numeros);
    printf("\n    *numeros = %d", *numeros);

    // (2) alocar memória para ele
    numeros = (int*) malloc(tamanho * sizeof(int));               
                //   numeros: __------> __|__|__|__|__|__|__|__     
                //  *numeros == numeros[0]  primeira posição do array
                //              numeros[1]  segunda posição do array
    
    printf("\n\n(2) Chamei o malloc.");
    printf("  \n    *numeros = %d", *numeros);
    printf("  \n    numeros[0] = %d", numeros[0]);
    printf("\nVou atribuir numeros às posições do array.");
    numeros[0] = 17;
    numeros[1] = 18;
    // não vamos escrever nada na posição 2
    numeros[3] = 66;
    printf("  \n    *numeros = %d", *numeros);
    printf("  \n    numeros[0] = %d", numeros[0]);
    printf("  \n    numeros[1] = %d", numeros[1]);
    printf("  \n    numeros[2] = %d", numeros[2]);
    printf("  \n    numeros[3] = %d", numeros[3]);    
                        

    // (3) copiar outro ponteiro
    int* ponteiro_pre_existente;
  
    // assumindo que ponteiro_pre_existente já tenha sido atribuído, 
    // por exemplo via malloc()
    ponteiro_pre_existente = malloc(5 * sizeof(int));
    ponteiro_pre_existente[1] = 8;
           //    ponteiro_pre_existente: __------>  __|_8_|__|__|__  
           //                                 /                    
    numeros = ponteiro_pre_existente; //     /
           //                               /                
           //    numeros:  __--------------/

        
    printf("\n\n(3) Copiei de outro ponteiro.");
    printf("  \n    ponteiro_pre_existente[1] = %d",
                    ponteiro_pre_existente[1]);
    printf("  \n    numeros[1] = %d",
                    numeros[1]);


    printf("\n\n");

    return 0;
}





 
   
