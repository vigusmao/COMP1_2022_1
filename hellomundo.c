#include <stdlib.h>
#include <stdio.h>

void escrever_algo() {
    printf("Oi outra vez!\n");
} 

int calcular_dobro(int numero) {
    return 2*numero;    
}

float obter_imc(float peso_kg,
                float altura_m) {

    float quad_altura = 
        altura_m * altura_m;

    return peso_kg / quad_altura;
}

int main() {
    printf("Oi mundo!!");
    printf("\n\n");
    escrever_algo();

    int idade = 20;

    int dobro = calcular_dobro(
                idade);

    printf("A idade eh %d hoje\n", 
           idade);
    printf("Seu dobro eh: %d\n",
           dobro);

    float peso = 70.5;
    float alt = 1.7; 
    
    float imc = obter_imc(
        peso, alt);
    printf("imc ---> %f\n", imc); 
    

    return 0;
}







