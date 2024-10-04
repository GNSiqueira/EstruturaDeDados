#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    //5. (WHILE) Faça um algoritmo que determine e escreva:   
    // - a maior idade dos habitantes
    // - a quantidade de indivíduos do sexo feminino cuja idade está entre 18 e 35 anos inclusive e que tenham olhos verdes e cabelos louros.
    // O final do conjunto de habitantes é reconhecido pelo valor -1 entrada como idade.

    short id = 0;
    short sexo = 0;
    short olho = 0;
    short cabelo = 0;
    short idpf = ;
    short idade = 0;

    while(id != -1){
    
        printf("Digite a idade: \n");
        scanf("%hd", &id);

        printf("Digite o sexo(1 = Feminino, 2 = Masculino): \n");
        scanf("%hd", &sexo);

        printf("A cor dos olhos(verde = 1, azul = 2, castanho = 3, preto = 4): \n");
        scanf("%hd", &olho);

        printf("A cor dos seus cabelos(Loiros = 1, castanho = 2, pretos = 3, ruivos = 4): \n");
        scanf("%hd", &cabelo);

        if(idade > id) {

            idade = id;

        }

        if (sexo == 1 && id >= 18 || id <=35 && olho == 1 && cabelo == 1) {

            idpf++;

        }
    
    }

    printf("A maior idade e: %hd\n", idade);
    printf("A quantidade de individuos de sexo feminino, idade entre 18 a 35, olhos verdes e cabelos loiros e: %hd", idpf);

}