#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    /*7. (WHILE) A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre o salário e número de filhos. A prefeitura deseja saber:  
    a) média do salário da população;
    b) média do número de filhos;
    c) maior salário;
    d) percentual de pessoas com salário até R$100,00.
    O final da leitura de dados se dará com a entrada de um salário negativo.  */
    
    float salario = 0.0, tlsalario = 0.0, maiorsal = 0.0;
    short filhos = 0, t = 0, ft = 0, sal100 = 0;

    while(1){
    
        printf("Escreva o seu salario: \n");
        scanf("%f", &salario);

        if(salario >= 0){

            printf("Digite o numero de filhos: \n");
            scanf("%hd", &filhos);

            tlsalario += salario;
            t++;
            ft += filhos;
            if(maiorsal < salario){

                maiorsal = salario;

            }
            if(salario < 100){

                sal100++;

            }

        }else{

            break;

        }
    
    }

    printf("A media do salario e: %f\n", (float)(tlsalario/t));

    printf("A media de filhos e: %hd\n", ft / t);

    printf("O maior salario e: %f\n", maiorsal);
    salario = ((float)sal100/(float)t) * 100;
    printf("A porcentagem de pessoas com salario ate 100 reais e: %g%%\n", salario);

}