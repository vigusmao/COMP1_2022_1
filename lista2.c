#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

typedef struct _pessoa {
    char nome[50];
    int rg;
    int ano_nasc;
} PESSOA;

void imprimir_pessoa(PESSOA* p) {
    printf("\nNome: %s, RG: %d, Ano: %d", 
        p->nome, p->rg, p->ano_nasc);
}

int calcular_idade(PESSOA pessoa, int ano) {
    return ano - pessoa.ano_nasc;
}

/*
Outra forma seria usar passagem por referencia:
int calcular_idade(PESSOA* p, int ano) {
    return ano - p->ano_nasc;
}
*/

PESSOA* encontrar_mais_velha(PESSOA* pessoas,
                             int quant_pessoas) {
    int min_ano_nasc;
    PESSOA* mais_velha = NULL;

    int i;
    for (i=0; i<quant_pessoas; i++) {
        if (mais_velha == NULL ||
               pessoas[i].ano_nasc < min_ano_nasc) {
            min_ano_nasc = pessoas[i].ano_nasc;
            mais_velha = &pessoas[i];
        }
    }

    return mais_velha;
}

int** criar_matriz(int n_linhas, int n_colunas) {
    int** matriz_dinamica = (int**) malloc(
        n_linhas * sizeof(int*));
    int i;
    for(i=0; i<n_linhas; i++) {
        matriz_dinamica[i] = (int*) malloc(
            n_colunas * sizeof(int));
    }
    return matriz_dinamica;
}

void imprimir_matriz(int** matriz, 
                     int n_linhas,
                     int n_colunas) {
    int i,j;
    for (i=0; i<n_linhas; i++) {
        printf("\n");
        for (j=0; j<n_colunas; j++) {
            printf("%3d ", matriz[i][j]);
        }
    }
}

int** calcular_soma(int** matriz1, 
                    int** matriz2,
                    int n_linhas, int n_colunas) {

    int** resultado = criar_matriz(
        n_linhas, n_colunas);

    int i,j;
    for (i=0; i<n_linhas; i++) {
        for (j=0; j<n_colunas; j++) {
            resultado[i][j] = matriz1[i][j] +
                              matriz2[i][j];
        }
    }

    return resultado;
}


int main() {
    int n, i;

    printf("\nQuantos funcionarios? ");
    scanf("%d", &n);
    
    PESSOA* funcionarios = (PESSOA*) malloc(
                           n * sizeof(PESSOA));
    
    for (i=0; i<n; i++) {
        // consome o \n deixado no buffer do teclado
        getchar();

        printf("\n\nCadastrando funcionario %d...",
            i+1);        
        printf("\nNome: ");
        fgets(funcionarios[i].nome, 50, stdin);
        
        // descarta o \n final do nome
        funcionarios[i].nome[
            strlen(funcionarios[i].nome)-1] = 0;

        printf("RG: ");
        scanf("%d", &funcionarios[i].rg);

        printf("Ano de nascimento: ");
        scanf("%d", &funcionarios[i].ano_nasc);
    }

    /*
    printf("\nVerificando cadastros...");
    for (i=0; i<n; i++) {
        imprimir_pessoa(&funcionarios[i]);
        printf("\n");
    }
    */

    // Calculando media de idade dos funcionarios...
    int soma_idades = 0; 
    for (i=0; i<n; i++) {
        soma_idades += calcular_idade(
            funcionarios[i], 2022);
    }
    printf("\nMedia de idade: %d", soma_idades/n); 
 
    PESSOA* anciao_ptr = encontrar_mais_velha(
        funcionarios, n);
    printf("\nFuncionario mais antigo: ");
    imprimir_pessoa(anciao_ptr);

    int matriz_estatica[2][3] = {1,  2,  3,
                                 10, 20, 30};

    int** matriz_dinamica_1 = criar_matriz(2,3);
    matriz_dinamica_1[0][0] = 1;
    matriz_dinamica_1[0][1] = 2;
    matriz_dinamica_1[0][2] = 3;
    matriz_dinamica_1[1][0] = 10;
    matriz_dinamica_1[1][1] = 20;
    matriz_dinamica_1[1][2] = 30;

    int** matriz_dinamica_2 = criar_matriz(2,3);
    matriz_dinamica_2[0][0] = -1;
    matriz_dinamica_2[0][1] = -2;
    matriz_dinamica_2[0][2] = -3;
    matriz_dinamica_2[1][0] = -10;
    matriz_dinamica_2[1][1] = -20;
    matriz_dinamica_2[1][2] = -30;

    int** soma = calcular_soma(
        matriz_dinamica_1,
        matriz_dinamica_2,
        2, 3);

    printf("\n\n");
    printf("\nMatriz 1:");
    imprimir_matriz(matriz_dinamica_1, 2, 3);

    printf("\n\n");
    printf("\nMatriz 2:");
    imprimir_matriz(matriz_dinamica_2, 2, 3);    
    
    printf("\n\n");
    printf("\nSoma:");
    imprimir_matriz(soma, 2, 3);
 

    printf("\n\n");
    return 0;
}
 
    






