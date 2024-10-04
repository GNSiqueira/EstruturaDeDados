#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    //4. (FOR) Foi feita uma pesquisa entre os habitantes de uma região. Foram coletados os dados de idade, sexo (M/F) e salário. Faça um algoritmo que informe de 15 pessoas: 
    /*a) a média de salário do grupo;

    b) maior e menor idade do grupo;

    c) quantidade de mulheres com salário até R$100,00.*/
    int fg = 0;
    float sal = 0;
    float salario = 0;
    int imenor = 9999;
    int imaior = 0;
    int salmu = 0;  
    
      
    
    for (int i = 0; i < 15; i++)
    {
        char genero;
        
        

        printf("Digite a idade: \n");
        scanf("%i", &fg);        
        printf("Genero: \n");
        scanf("%s", &genero);
        
        printf("Digite a o salario: \n");
        scanf("%f", &sal);

        salario += sal;
        // Atualização da menor idade
        if (fg < imenor) {
          imenor = fg;
        }

        // Atualização da maior idade
        if (fg > imaior) {
          imaior = fg;
        }

        if (genero == 'F' && sal <=100.0)
        {
            salmu++;
        }
    }
    printf("A media do salario e: %f\n", salario / 15);
    printf("A menor idade do grupo e: %i\n", imenor);
    printf("A maior idade do grupo e: %i\n", imaior);
    printf("A quantidade de mulheres com salario menor ou igual a 100 reais e: %i", salmu);
}