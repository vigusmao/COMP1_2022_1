/* 
   Um vestiário possui n armários numerados de 1 a n.
   Existem n crianças que farão a seguinte brincadeira.
   Com os armários inicialmente fechados, a primeira criança
   (criança 1) entrará no vestiário e abrirá todos os armários,
   saindo do vestiário em seguida.
   Depois a segunda criança (criança 2) entrará no vestiário e
   mudará o estado (ou seja, se estiver aberto, fecha; se estiver
   fechado, abre) de todos os armários pares.
   A criança número 3 mudará o estado de todos os armários cujo número
   é múltiplo de 3.
   E assim por diante: a criança j, para todo j de 1 a n, 
   entrará no vestiário e mudará o estado de todos os armários
   que são múltiplos de n.
   
   PERGUNTA: no final, que armários estarão abertos?

   1) Crie uma função "void armarios(int n)" para imprimir os armários
      abertos no final.

   2) No main(), peça o valor de n para o usuário e chame a função.
*/

#include <stdio.h>
#include <stdlib.h>

void armarios(int n) {
    //char estados[n+1];
    
    char* estados = (char*) malloc ((n+1) * sizeof(char));
        
    // 0 é FECHADO; 1 é ABERTO
    
    // inicializa os armários todos (tudo fechado)
    int a;
    for (a=1; a<=n; a++) {
        estados[a] = 0;
    }

    // agora, para cada criança...
    int crianca;
    for (crianca=1; crianca<=n; crianca++) {
        // ...altere os armários que são múltiplos
        for (a=1; a<=n; a++) {
            if (a%crianca==0) {
                // é múltiplo, então altera o estado
                estados[a] = 1 - estados[a];
            }             
        }
    }

    // verifique agora que armários estão abertos
    for (a=1; a<=n; a++) {
        if (estados[a]) {
            printf("\n%d", a);
        }
    }

    free(estados);
}

int main() {
    printf("\nQuantos armários? ");
    int n;
    scanf("%d", &n);
    armarios(n);
    printf("\n\n"); 
    return 0;
}




