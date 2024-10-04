#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

int main(void){

    /* 9. Faça um programa em C que encontre e imprima o maior elemento de uma matriz 3x3 de inteiros. */

    srand((unsigned int)time(NULL));

    int matriz[N][N], maior = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz[i][j] = rand()%100;
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }
            
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("O maior numero na matriz é: %d\n", maior);
}