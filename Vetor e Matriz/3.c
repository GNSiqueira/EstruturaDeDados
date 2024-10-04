#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main(void){

    /* 3. Crie um programa em C que verifique se um vetor de inteiros está ordenado de forma crescente.*/

    srand((unsigned int)time(NULL));

    int vetor[N], c = 0;

    /* for (int i = 0; i < N; i++)
    {
        vetor[i] = rand()%101;
    } */
    printf("\nPrenecha o vetor: \n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < N - 1; i++)
    {
        int t = i + 1;
        if (vetor[i] >= vetor[t])
        {
            c++;
            break;
        }
    }
    if (c == 0 )
    {
        printf("\nO vetor esta na sequencia!\n");
    }else
    {
        printf("\nO vetor não esta na sequencia!\n ");
    }
    
}