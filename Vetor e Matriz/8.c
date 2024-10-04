#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

int main(void){

    /* 8. Escreva um programa em C que calcule e imprima a soma de todos os elementos de uma matriz 3x3 de inteiros. */    

    srand((unsigned int)time(NULL));

    int matriz[N][N], soma = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz[i][j] = rand()%100;
            soma += matriz[i][j];
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("A soma dos elementos da matriz é: %d\n ", soma);

}