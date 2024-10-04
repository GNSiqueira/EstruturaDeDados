#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main(void){
    srand((unsigned int)time(NULL));
    int vetor[N];
    for (int i = 0; i < N; i++){
        vetor[i] = rand()%101;
        printf("%d ",vetor[i]);
        int c2 = i;
        for (int j = i -1; j > -1; j--){
            if (vetor[c2]>vetor[j]){
                int c = vetor[c2];
                vetor[c2] = vetor[j];
                vetor[j] = c;
                c2--;
            }else{break;}   
        }  
    }
    printf("\n");
    for (int i = 0; i < N; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
} 