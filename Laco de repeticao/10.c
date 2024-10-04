#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    /*10. Escrever um algoritmo que lê 10 valores, um de cada vez, e conta quantos deles estão no intervalo [10,20] e quantos deles estão fora do intervalo, escrevendo estas informações.*/

    short dentro = 0, fora = 0;
    
    for(int i = 0; i < 10; i++){

        float controle = 0;

        printf("Escreva um numero: \n");
        scanf("%f", &controle);

        if(controle >= 10 && controle <= 20){

            dentro++;

        }else{

            fora++;

        }

    }

    printf("Quantidade de numeros que estao entre 10 e 20: %i\n", dentro);
    printf("Quantidade de numeros que estao fora do internalo de 10 e 20: %i\n", fora);

}