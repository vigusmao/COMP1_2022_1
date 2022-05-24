/* Escreva uma função que recebe um array de floats como parâmetro,
   e um inteiro n indicando a quantidade de elementos nesse array.

   O array indicará temperaturas medidas ao longo de um período.

   Queremos que a função compute:
   - a temperatura mínima no período;
   - a temperatura máxima no período;
   - a temperatura média no período.

   Agora... como fazer para RECEBER esses resultados computados
   pela função? Quem CHAMAR a função precisará depois SABER quais
   foram esses valores, para fazer ALGO com eles (ou seja, não
   adiantaria a função apenas IMPRIMIR na tela aqueles valores;
   ela precisa entregá-los ao chamador da função). Poderíamos
   pedir para a função RETORNAR algo, mas a função retorna UMA coisa,
   e não três...

   Como fazer?

   Uma possibilidade é passar três parâmetros POR REFERÊNCIA,
   para que a função possa escrever neles.
   Então o chamador criaria, digamos, variáveis max, min, media,
   e passaria os ENDEREÇOS dessas variáveis para a função.
   A função calcularia o que ela precisaria calcular e escreveria
   os valores obtidos naqueles ENDEREÇOS passados, ficando
   portanto visíveis para o chamador.
*/

#include <stdio.h>
#include <stdlib.h>

void analisar_temperaturas(float* array_temps, int n, 
                           float* min, float* max, float* media) {

    float maior = array_temps[0];
    float menor = array_temps[0];
    float soma = 0;

    int i;
    for (i=0; i<n; i++) {
        float temp = array_temps[i];
        if (temp > maior) {
            maior = temp;
        }
        if (temp < menor) {
            menor = temp;
        }
        soma += temp;
    }
    
    *media = soma / n;
    *min = menor;
    *max = maior; 

    array_temps[1] = 88888.8;
}

void imprimir_array(float array[], int n) {
    int i;
    printf("%.2f ", array[0]);
    for (i=1; i<n; i++) {
        printf("%.2f", array[i]);
        if (i<n-1) {
            printf(", ");
        }
    }
}


int main() {

    float* temperaturas = (float*) malloc(4 * sizeof(float));
    temperaturas[0] = 40.3;
    temperaturas[1] = 12.5;
    temperaturas[2] = 31.9;
    temperaturas[3] = 5.2;

    float min, max, media;

    imprimir_array(temperaturas, 4);
 
    analisar_temperaturas(temperaturas, 4, &min, &max, &media);

    printf("\nmin=%.2f, max=%.2f, media=%.2f", min, max, media);

    printf("\n");
    imprimir_array(temperaturas, 4);
    
    printf("\n\n");
    return 0;
}

                            
    
 

 






