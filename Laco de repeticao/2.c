#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //(WHILE) Escreva um algoritmo que calcule a média dos números digitados pelo usuário, se eles forem pares. Termine a leitura se o usuário digitar zero (0).
    float total = 0;
    short contador = 0;
    while(1){
        short controle = 0;
        printf("Digite o numero: \n");
        scanf("%hd", &controle);
        if (controle != 0)
        {
            if(controle % 2 == 0){
                total = total + controle;
                contador = contador + 1;
            }
        }else{
            break;
        }
    
    }
    total = total / contador;
    printf("O total dos numeros pares em media e: %f, %hd", total, contador);
}