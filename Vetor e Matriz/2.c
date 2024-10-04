#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(void){

    /* 2. Desenvolva um programa em C que receba dois vetores de inteiros de mesmo tamanho e calcule o produto escalar entre eles. */
    short tamanho = 0;
    printf("\nDigite o tamanho dos vetores: ");
    scanf("%hd", &tamanho);

    int vetor[tamanho], vetor2[tamanho];

    printf("\nPreencha o vetor 1:\n");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printf("\nPreencha o vetor 2:\n");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor2[i]);
    }

    int produtof = 0;

    for (int i = 0; i < tamanho; i++)
    {
        produtof += vetor[i] * vetor2[i];
    }

    printf("O produto final dos vetores e: %d\n\n\n", produtof);

}