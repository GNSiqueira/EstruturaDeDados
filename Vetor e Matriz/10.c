#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

int main(void){

    /* 10. Desenvolva um programa em C que verifique se uma matriz 3x3 de inteiros é uma matriz identidade. */

    srand((unsigned int)time(NULL));

    int matriz[N][N], c = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz[i][j] = rand()%2;
            //scanf("%d", &matriz[i][j]);
            printf("%d ", matriz[i][j]);
            if( i == j ){
                matriz[i][j] == 1? c: c++;
            }else{
                matriz[i][j] == 0? c: c++;
            }
        }
    printf("\n"); 
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    printf("\n");    
    }
    

    printf("A matriz %s identidade.", c == 0? "é": "não é");

} 