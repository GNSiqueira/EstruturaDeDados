#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    //3. (DO WHILE) Escrever um algoritmo que leia uma quantidade desconhecida de números e conte quantos deles estão nos seguintes intervalos: [0,25], [26,50], [51,75] e [76,100]. A entrada de dados deve terminar quando for lido um número negativo.
    short c = 0;
    short fx1 = 0;
    short fx2 = 0;
    short fx3 = 0;
    short fx4 = 0;
    do {
        printf("Escreva um número: \n");
        scanf("%hd", &c);
        if( c < 26){
            fx1++;
        }else if (c<51)
        {
            fx2++;
        }
        else if (c<76)
        {
            fx3++;
        }
        else if (c<101)
        {
            fx4++;
        }else
        {
            printf("Nao esta entre as faixas.");
        }
    }while(c > 0);
    printf("Entre(0 - 25): %hd\n", fx1);
    printf("Entre(26 - 50): %hd\n", fx2);
    printf("Entre(51 - 75): %hd\n", fx3);
    printf("Entre(76 - 100): %hd\n", fx4);
}