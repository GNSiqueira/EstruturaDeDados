#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    //6. (FOR) Escreva um algoritmo que gere o números de 1000 a 1999 e escreva aqueles que dividido por 11 dão resto igual a 5.

    for(int i = 999; i < 2001; i++){
   
        if(i%11==5){

            printf("%i ", i);
        
        }
    }

}