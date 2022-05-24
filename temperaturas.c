/* Escreva uma função que recebe uma matriz bidimensional 
   (isto é, array de arrays) de floats como parâmetro,
   e dois inteiros n_linhas, n_colunas indicando os tamanhos
   das dimensões da matriz.

   A matriz terá, portanto, "linhas" e "colunas", indicando
   temperaturas medidas ao longo de um período.
   Cada linha representa um dia, e, em cada linha, cada valor 
   representa uma medição ao longo daquele dia.

   Queremos que a função compute:
   - a temperatura mínima no período;
   - a temperatura máxima no período;
   - a temperatura média no período.
   - o número da linha correspondendo ao dia com a maior variação térmica

   Agora... como fazer para RECEBER esses resultados computados
   pela função? Quem CHAMAR a função precisará depois SABER quais
   foram esses valores, para fazer ALGO com eles (ou seja, não
   adiantaria a função apenas IMPRIMIR na tela aqueles valores;
   ela precisa entregá-los ao chamador da função). Poderíamos
   pedir para a função RETORNAR algo, mas a função retorna UMA coisa,
   e não três ou quatro...

   Como fazer?

   Uma possibilidade é passar parâmetros POR REFERÊNCIA,
   para que a função possa escrever neles.
   Então o chamador criaria, digamos, variáveis max, min, media,
   e passaria os ENDEREÇOS dessas variáveis para a função.
   A função calcularia o que ela precisaria calcular e escreveria
   os valores obtidos naqueles ENDEREÇOS passados, ficando
   portanto visíveis para o chamador.
*/

#include <stdio.h>
#include <stdlib.h>

void analisar_temperaturas(float array_temps[], int n, 
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

void imprimir_array(float array[3][2], int n_linhas, n_colunas) {
    int i, j;
    
    for (i=0; i<n_linhas; i++) {

        for (j=0; j<n_colunas; j++) {
            printf("%.2f", array[i][j]);
            if (j<n_colunas-1) {
                printf("  ");
            }
        }
        
        printf("\n");
    }
}


int main() {

    // float* temperaturas = (float*) malloc(4 * sizeof(float));

   
    float temperaturas[3][2];  // array estático bidimensional
    temperaturas[0][0] = 40.3;
    temperaturas[0][1] = 20.9;    

    temperaturas[1][0] = 12.5;
    temperaturas[1][1] = 9.4;

    temperaturas[2][0] = 31.9;
    temperaturas[2][1] = 5.2;

    
    /*
       Logicamente, estamos vendo:
                
                  40.3  20.9
                  12.5  9.4
                  31.9  5.2
     
       Fisicamente, em memória, os valores estarão armazenados assim:
    
       temperaturas ---->  |_40.3_|_20.9_|_12.5_|_9.4_|_31.9_|_5.2_|


       Note que essa mesma representação física serviria tb para a
       matriz abaixo:

                 40.3  20.9  12.5
                 9.4   31.9  5.2  
       ou seja, um array de dimensões [3][2]
    
       
       Se eu peço array[1][0], qual o valor desejado? 12.5 ou 9.4???
       Se o compilador sabe apenas que é bidimensional, "temperaturas[][]",
       como ele vai conseguir saber se eu quero o 12.5 ou o 9.4? 
    */



    float min, max, media;

    imprimir_array(temperaturas, 3, 2);
 
    analisar_temperaturas(temperaturas, 6, &min, &max, &media);

    printf("\nmin=%.2f, max=%.2f, media=%.2f", min, max, media);

    printf("\n");
    imprimir_array(temperaturas, 3, 2);
    
    printf("\n\n");
    return 0;
}

                            
    
 

 






