/* Vamos pedir ao usuário para cadastrar uma nova senha
   numérica. A senha precisa ter 6 dígitos, e o primeiro
   dígito não pode ser 0. Se a senha não atender aos  
   critérios acima, devemos avisar ao usuário sobre isto e
   pedir para ele digitar outra senha.
   Tendo digitado uma senha aceitável, o usuário precisará
   confirmar a senha digitada. Se a senha digitada não
   casar com a primeira, devemos começar tudo de novo.
 */

#include<stdio.h>
#include<stdlib.h>

void cadastrar_senha() {
    while (1) {  // loop infinito

        printf("\nDigite sua nova senha: ");
        int nova_senha;
        scanf("%d", &nova_senha);

        if (nova_senha < 100000) {
            printf("\nA senha não pode ter menos do que 6 caracteres e não pode começar com 0.");
            continue;  // interrompe a iteração corrente, voltando à condição do while 
        } 

        if (nova_senha > 999999) {
            printf("\nA senha não pode ter mais do que 6 caracteres!");
            continue; 
        }

        // senha boa!
        
        printf("\nDigite novamente a senha: ");
        int repeticao_senha;
        scanf("%d", &repeticao_senha);

        if (repeticao_senha != nova_senha) {
            printf("\nAs senham não casam!");
            continue; 
        }

        printf("\nSenha cadastrada com sucesso!!!");
        break;
    }
}


int main() {
    cadastrar_senha();

    printf("\nFim!\n\n");
  
    return 0;
}

