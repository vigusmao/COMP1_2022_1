/* Vamos pedir ao usuário para digitar
   sua senha para acessar um sistema.
   Se a senha estiver errada, pedimos novamente,
   por no máximo 3 tentativas. Após 3 erros
   consecutivos, vamos desistir e dizer que a 
   conta estará bloqueada. */

#include<stdio.h>
#include<stdlib.h>

int main() {
    int senha_correta = 1234;  // senha fake

    int senha_digitada;

    printf("\nDigite a senha: ");

    int n_tentativas = 0;

    while (n_tentativas < 3) {
        n_tentativas = n_tentativas + 1;

        scanf("%d", &senha_digitada); 

        if (senha_digitada == senha_correta) {
            // senha digitada corretamente!
            printf("\nOk, usuário logado!\n");
            break;
        
        } else {           
            // senha digitada INcorretamente!
            printf("\nSenha incorreta!\n");
            
	    if (n_tentativas < 3) {
                printf("Digite novamente: ");
            } else {
                printf("Conta bloqueada!!!!");
            } 
        }
    }

    printf("\nFim!\n\n"); 
    
    return 0;
}
        

