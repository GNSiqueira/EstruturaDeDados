#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main(void){

    /* 5. Desenvolva um programa em C que receba um vetor de inteiros e substitua todos os valores negativos por zero.*/

    int vetor[N];

    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++)
    {
        vetor[i] = rand()%201 - 100;
        printf("%d ", vetor[i]);
    }
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        if (vetor[i] < 0)
        {
            vetor[i] = 0;
        }
        
    }
    
    for (int i = 0; i < N; i++)
    {
        printf("%d ", vetor[i]);
    }

} 