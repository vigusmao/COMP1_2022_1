#include<stdio.h>
#include<stdlib.h>

/* Escreva uma função que receba como parametros um array de inteiros 
   e um inteiro n, e que reverte as posições dos n primeiros elementos
   desse array. 

   No main(), peça para o usuário digitar o tamanho do array,
   depois cada elemento do array, e finalmente o tamanho do prefixo
   que deseja inverter. Chame então a função que inverte,
   e apresente o array já modificado.
*/

//void inverter(int* array, int n) {
//    // copia as n primeiras posições para um array auxiliar
//    int* aux = (int*) malloc(n * sizeof(int));
//    int pos;
//    for (pos=0; pos<n; pos++) {
//        aux[pos] = array[pos];
//    }
//    
//    // agora sobrescreve as n primeiras posições do array original,
//    // a partir do array auxiliar, sendo lido de trás pra frente
//    for (pos=0; pos<n; pos++) {         // ex.: n = 4
//        array[pos] = aux[n-1-pos];      // array[0] = aux[3]
//                                        // array[1] = aux[2]
//    }                                   // array[2] = aux[1]
//                                        // array[3] = aux[0]
//}

void inverter(int* array, int n) {

    // agora sobrescreve as n primeiras posições do array original,
    // a partir do array auxiliar, sendo lido de trás pra frente
    int pos;
    for (pos=0; pos<n/2; pos++) {
        int temp = array[pos]; 
        array[pos] = array[n-1-pos];
        array[n-1-pos] = temp;  
    }                              
}

void imprimir_array(int* array, int tamanho) {
    int pos;
    for (pos=0; pos<tamanho; pos++) {
        printf("%d", array[pos]);
        if (pos < tamanho-1) {
            printf(", ");
        }
    } 
}


int main() {

    printf("\nQual o tamanho do array? ");
    int tamanho;              
    scanf("%d", &tamanho);    

    // vamos inicializar o array
    int* numeros = (int*) malloc(tamanho * sizeof(int));    

    // vamos agora popular o array via teclado

    int pos;
    for (pos=0; pos<tamanho; pos++) {
        printf("\n Elemento da posição %d: ", pos);
        scanf("%d", &numeros[pos]); 
    }

    printf("\nQuantas posições iniciais deseja inverter? ");
    int tamanho_prefixo;
    scanf("%d", &tamanho_prefixo);

    inverter(numeros, tamanho_prefixo);

    printf("\nArray com prefixo invertido: "); 
    imprimir_array(numeros, tamanho); 

    printf("\n\n");

    return 0;
}





 
   
