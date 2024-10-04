#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main(void){

    /* 6. Escreva um programa em C que determine se um vetor de inteiros é simétrico, ou seja, se ele é igual ao seu vetor invertido. */

    srand((unsigned int)time(NULL));

    int vet[N];

    /* for (int i = 0; i < N; i++)
    {
        vet[i] = rand()%101;
    } */
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vet[i]);
    }

    int c = N / 2;
    if (N % 2 != 0 ){
        c +=1;
    }

    for (int i = 0, j = N-1; i < c; i++, j--)
    {
        if (vet[i] != vet[j])
        {
            c = 0; 
        }
        
    }

    if (c == 0)
    {
        printf("O vetor não é simétrico!");
    }else{
        printf("O vetor é simétrico!");
    }
    
    
    

}