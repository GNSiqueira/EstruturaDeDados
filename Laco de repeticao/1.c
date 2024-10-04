#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //1. (WHILE) Escreva um algoritmo que calcule a média aritmética das 3 notas dos alunos de uma classe. O algoritmo deverá ler, além das notas, o código do aluno e deverá ser encerrado quando o código for igual a zero.

    int codigo = 1;

    printf("Calcular a media de cada aluno: \n");

    while(1){
        printf("Digite o codigo do aluno: \n");
        scanf("%d", &codigo);
        float total = 0;
        if (codigo == 0)
        {
            break;
        }else{
            float controle = 0;
            
            int i = 1;
            while(i < 4){
        
                printf("Digite a %d nota: \n", i);
                scanf("%f", &controle);
                total = total + controle;
                i++;
            }    
            total = total / 3;
            printf("A media do aluno portador do (%d) e: %f\n", codigo, total);
        }
        
    }

}