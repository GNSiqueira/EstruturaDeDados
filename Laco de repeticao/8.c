#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    /*8. Escrever um algoritmo que calcule e mostre a média aritmética dos números lidos entre 13 e 73.*/

    int cont = 0, numfinal = 0;


    for(int i = 12; i < 74; i++){

        numfinal += i;
        cont++;

    }
    printf("A media aritimetica dos numeros de 13 a 73 e: %g", (float)numfinal/(float)cont);

}