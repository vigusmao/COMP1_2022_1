/*
LAB 6

No main(), crie três arrays "paralelos", inicialmente com tamanho 1000:
    - cpfs (long)        |___|___|___|___|___|___|___|___|...
    - saldos (float)     |___|___|___|___|___|___|___|___|...
    - senhas (int)       |___|___|___|___|___|___|___|___|...
                           0   1   2   3   4   5   6   7
   
    Inicialize também uma variável quant_contas, que monitorará
    a quantidade de contas correntes já cadastradas.

    Tanto os arrays quanto a variável quant_contas podem ser
    variáveis globais. Assim serão visíveis a todas as funções.

    Você deverá entrar num loop infinito, onde será apresentado um
    menu de opções:

    1: cadastrar conta
    2: sacar
    3: depositar
    4: consultar saldo
    5: sair

    Após a apresentação do menu, devemos ler a opção escolhida
    pelo usuário, e chamar a função correspondente. 

    Precisaremos, então, criar uma função para cada uma dessas
    possíveis operações (exceto sair, que simplesmente sai do loop,
    encerrando o programa).

    Cada uma dessas funções deverá perguntar para o usuário qual 
    o cpf associado à conta desejada, e, dependendo do caso, qual
    o calor desejado (para saque ou depósito) e a senha (para saque
    ou consulta).

    Cada uma dessas funções deverá retornar um int, que será 0,
    sempre que ela for bem-sucedida (não houve erro), e retornará
    um código de erro qualquer, maior do que zero, se houver algum
    erro.

    No main(), ao receber o valor de retorno da função chamada,
    se houve erro deve ser impressa uma mensagem dizendo
    "Erro! Tente novamente!", ou coisa parecida.
*/


#include <stdio.h>
#include <stdlib.h>

long* cpfs;
float* saldos;
int *senhas;
int quant_contas;

long perguntar_cpf() {
    printf("\nDigite o CPF desejado: ");
    long numero_digitado;
    scanf("%ld", &numero_digitado);
    return numero_digitado;
}

int perguntar_senha() {
    printf("\nDigite a senha: ");
    int senha;
    scanf("%d", &senha);
    return senha;
}

float perguntar_valor() {
    printf("\nDigite o valor desejado: ");
    float valor;
    scanf("%f", &valor);
    return valor;
}

int buscar_cpf(long cpf) {
    int indice;
    for (indice=0; indice<quant_contas; indice++) {
        if (cpfs[indice] == cpf) {
            return indice;
        }
    }
    return -1; // indica que o cpf desejado não existe
}

int cadastrar() {
    long cpf = perguntar_cpf();

    int indice_no_array = buscar_cpf(cpf);
    if (indice_no_array >= 0) {
        return 54;  // código de erro para CPF já cadastrado
    }

    int senha = perguntar_senha();
     
    cpfs[quant_contas] = cpf;
    saldos[quant_contas] = 0;  // saldo inicial zerado
    senhas[quant_contas] = senha;   

    quant_contas++;
    return 0;
}

int sacar() {
    long cpf = perguntar_cpf();

    int indice_no_array = buscar_cpf(cpf);
    if (indice_no_array == -1) {
        return 51;  // código de erro para CPF não encontrado
    }

    int senha = perguntar_senha();
    if (senhas[indice_no_array] != senha) {
        return 52;  // código de erro para senha incorreta
    }

    float valor = perguntar_valor();
  
    if (saldos[indice_no_array] < valor) {
        return 53;  // código de erro para saldo insuficiente
    }

    saldos[indice_no_array] -= valor;
    return 0;
}

int depositar() {
    long cpf = perguntar_cpf();

    int indice_no_array = buscar_cpf(cpf);
    if (indice_no_array == -1) {
        return 51;  // código de erro para CPF não encontrado
    }

    float valor = perguntar_valor();
    
    saldos[indice_no_array] += valor;
    return 0;
}

int consultar() {
    long cpf = perguntar_cpf();

    int indice_no_array = buscar_cpf(cpf);
    if (indice_no_array == -1) {
        return 51;  // código de erro para CPF não encontrado
    }

    int senha = perguntar_senha();
    if (senhas[indice_no_array] != senha) {
        return 52;  // código de erro para senha incorreta
    }
 
    printf("\nSaldo em conta: R$%.2f\n", saldos[indice_no_array]);
    return 0; 
}


int apresentar_menu() {
    printf("\n-------- MENU --------\n");
    printf("\n1: cadastrar conta");
    printf("\n2: sacar");
    printf("\n3: depositar"); 
    printf("\n4: consultar saldo");
    printf("\n5: sair");
    int opcao;
    printf("\n\nDigite a opção desejada: "); 
    scanf("%d", &opcao);
    return opcao;
}

void imprimir_mensagem_erro(int codigo) {
    if (codigo == 51) {
        printf("\nCPF não encontrado!\n");
    } else if (codigo == 52) {
        printf("\nSenha incorreta!\n");
    } else if (codigo == 53) {
        printf("\nSaldo insuficiente!\n");
    } else if (codigo == 54) {
        printf("\nCPF já cadastrado!\n");
    } else if (codigo == -1) {
        printf("\nOpção inválida!\n");
    } else {
        printf("\nErro! Tente mais tarde!");
    } 
}

int main() {
    
    cpfs = (long*) malloc(1000 * sizeof(long));
    saldos = (float*) malloc(1000 * sizeof(float));
    senhas = (int*) malloc(1000 * sizeof(int));

    quant_contas = 0;

    while (1) {
        int opcao = apresentar_menu();

        int codigo_erro = -1;  // irá sinalizar opção inválida

        if (opcao == 1) {
            codigo_erro = cadastrar();

        } else if (opcao == 2) {
            codigo_erro = sacar();

        } else if (opcao == 3) {
            codigo_erro = depositar();

        } else if (opcao == 4) {
            codigo_erro = consultar();

        } else if (opcao == 5) {
            break;
        }

        if (codigo_erro != 0) {
            imprimir_mensagem_erro(codigo_erro);
        }
    }

    printf("\nTchau!\n\n");

    return 0;   
}





    







