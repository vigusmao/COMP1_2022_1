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
   os valores obtidos naqueles ESDEREÇOS passados, ficando
   portanto visíveis para o chamador.
*/

#include <stdio.h>




