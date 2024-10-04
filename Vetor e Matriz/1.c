#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main(void){

    //1. Faça um programa em C que conte quantos elementos pares existem em um vetor de inteiros.

    srand((unsigned int)time(NULL));

    int vetor[N], pares = 0;

    for (int i = 0; i < N; i++)
    {
        if(vetor[i] % 2 == 0)
            pares++;
        
    }

    printf("A quantidade de numeros pares e: %d\n", pares);
    
}