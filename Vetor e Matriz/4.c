#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main(void){

    /* 4. Faça um programa em C que verifique se um vetor de inteiros contém um determinado valor digitado pelo usuário.*/

    srand((unsigned int)time(NULL));

    int vetor[N];

    for (int i = 0; i < N; i++)
    {
        vetor[i] = rand()%11;
        printf("%d ", vetor[i]);
    }

    

    int c = 0; 
    printf("\nDigite o numero de preferencia: \n");
    scanf("%d", &c);

    for (int i = 0; i < N; i++)
    {
        if (vetor[i] == c)
        {
            c = -1;
            break;
        }
        
    }
    
    if (c == -1 )
    {
        printf("O seu numero esta no vetor!\n\n");
    }else{
        printf("O numero não esta no vetor!\n\n");
    }
    
}