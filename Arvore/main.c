#include <stdlib.h>
#include <stdio.h>

typedef struct Arvore{
    int valor;
    int altura;
    struct Arvore *esquerda;
    struct Arvore *direita;
} Arvore;

Arvore *Criar(int valor){
    Arvore *Novo = (Arvore*)malloc(sizeof(Arvore));
    Novo->valor = valor;
    Novo->esquerda = NULL;
    Novo->direita = NULL;
    Novo->altura = 1;
    printf("Valor inserido!\n");
    return Novo;
}

int menu(){
    int opcao;
    printf("\nEscolha uma opção:\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Mostrar arvore\n");
    printf("4 - Buscar valor\n");
    printf("5 - Imprimir pre ordem\n");
    printf("6 - Imprimir pos ordem\n");
    printf("7 - Imprimir em ordem\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);
    return opcao;
}

int Altura(Arvore *no){
    if (no == NULL)
        return 0;
    return no->altura;
}

int FatorBalanceamento(Arvore *no){
    if (no == NULL)
        return 0;
    return Altura(no->esquerda) - Altura(no->direita);
}

int maior(int a, int b){
    return (a > b)? a: b;
}

void AtualizarAltura(Arvore *no) {
    if (no != NULL)
        no->altura = 1 + maior(Altura(no->esquerda), Altura(no->direita));
}

Arvore* RotacaoSimplesDireita(Arvore *noY) {
    if (noY == NULL || noY->esquerda == NULL) {
        return noY;
    }
    
    Arvore *noX = noY->esquerda;
    Arvore *temp = noX->direita;

    noX->direita = noY;
    noY->esquerda = temp;

    AtualizarAltura(noY);
    AtualizarAltura(noX);

    return noX;
}

Arvore* RotacaoSimplesEsquerda(Arvore *noX){
    if (noX == NULL || noX->direita == NULL) {
        return noX;
    }
    
    Arvore *noY = noX->direita;
    Arvore *temp = noY->esquerda;

    noY->esquerda = noX;
    noX->direita = temp;

    AtualizarAltura(noX);
    AtualizarAltura(noY);
    return noY;
}

Arvore* RotacaoDuplaEsquerda(Arvore *noX){
    noX->esquerda = RotacaoSimplesDireita(noX->esquerda);
    return RotacaoSimplesEsquerda(noX);
}

Arvore* RotacaoDuplaDireita(Arvore *noX){
    noX->direita = RotacaoSimplesEsquerda(noX->direita);
    return RotacaoSimplesDireita(noX);
}

Arvore* Balancear(Arvore *no) {
    int balanceamento = FatorBalanceamento(no);

    if (balanceamento > 1) {
        if (FatorBalanceamento(no->esquerda) < 0) {
            no->esquerda = RotacaoSimplesEsquerda(no->esquerda);
        }
        return RotacaoSimplesDireita(no);
    }

    if (balanceamento < -1) {
        if (FatorBalanceamento(no->direita) > 0) {
            no->direita = RotacaoSimplesDireita(no->direita);
        }
        return RotacaoSimplesEsquerda(no);
    }

    return no;
}

Arvore* Inserir(Arvore *raiz, int valor) {
    if (raiz == NULL) {
        return Criar(valor);
    } else {
        if (valor > raiz->valor) {
            raiz->direita = Inserir(raiz->direita, valor);
        } else if (valor < raiz->valor) {
            raiz->esquerda = Inserir(raiz->esquerda, valor);
        } else {
            printf("Valor já existe na árvore\n");
            return raiz;
        }
    }

    AtualizarAltura(raiz);
    return Balancear(raiz);
}

void MostrarArvore(Arvore *no, int espaco) {
    if (no == NULL)
        return;

    espaco += 5;

    MostrarArvore(no->direita, espaco);

    for (int i = 5; i < espaco; i++)
        printf(" ");
    printf("%d\n", no->valor);

    MostrarArvore(no->esquerda, espaco);
}

Arvore* Minimo(Arvore* no){
    Arvore *outro = no;
    while(outro->esquerda != NULL)
        outro = outro->esquerda;
    return outro;
}

Arvore* Remover(Arvore *no, int valor) {
    if (no == NULL) {
        return no;
    }

    if (valor < no->valor) {
        no->esquerda = Remover(no->esquerda, valor);
    } else if (valor > no->valor) {
        no->direita = Remover(no->direita, valor);
    } else {
        // Nó encontrado
        if (no->esquerda == NULL || no->direita == NULL) {
            Arvore *temp = no->esquerda ? no->esquerda : no->direita;
            if (temp == NULL) {  // Caso 1: Sem filhos
                temp = no;
                no = NULL;
            } else {  // Caso 2: Um filho
                *no = *temp;  // Copia os dados do nó filho
            }
            free(temp);
        } else {  // Caso 3: Dois filhos
            Arvore *temp = Minimo(no->direita);
            no->valor = temp->valor;
            no->direita = Remover(no->direita, temp->valor);
        }
    }

    if (no == NULL)
        return no;

    AtualizarAltura(no);
    return Balancear(no);
}

void Buscar(Arvore* no, int valor) {
    Arvore* ono = no;
    int achei = 0;
    while (ono != NULL) {
        if (valor > ono->valor) {
            ono = ono->direita;
        } else if (valor < ono->valor) {
            ono = ono->esquerda;
        } else {
            achei = 1;
            break;
        }
    }
    if (achei == 1) {
        printf("Valor encontrado!\n");
    } else {
        printf("O valor não está na Árvore!\n");
    }
}

void PreOrdem(Arvore *no){
    if(no != NULL){
        printf("%d, ", no->valor);
        PreOrdem(no->esquerda);
        PreOrdem(no->direita);
    }
}

void PosOrdem(Arvore *no){
    if(no != NULL){
        PosOrdem(no->esquerda);
        PosOrdem(no->direita);
        printf("%d, ", no->valor);
    }
}

void Ordem(Arvore *no){
    if(no != NULL){
        Ordem(no->esquerda);
        printf("%d, ", no->valor);
        Ordem(no->direita);
    }
}

int main(){
    Arvore *raiz = NULL;

    while(1){
        int opcao = menu();

        if (opcao == 0){
            break;
        }
        else if (opcao == 1){
            // int valor;
            // printf("Digite o valor a ser inserido: ");
            // scanf("%d", &valor);
            // raiz = Inserir(raiz, valor);
            raiz = Inserir(raiz, 10);
            raiz = Inserir(raiz, 150);
            raiz = Inserir(raiz, 30);
            raiz = Inserir(raiz, 60);
            raiz = Inserir(raiz, 70);
            raiz = Inserir(raiz, 3);
            
            raiz = Inserir(raiz, 11);
            raiz = Inserir(raiz, 15);
            raiz = Inserir(raiz, 31);
            raiz = Inserir(raiz, 64);
            raiz = Inserir(raiz, 75);
            raiz = Inserir(raiz, 33);
            MostrarArvore(raiz, 0);
        }
        else if(opcao == 2){
            int valor;
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = Remover(raiz, valor);
            MostrarArvore(raiz, 0);

        }
        else if(opcao == 3){
            MostrarArvore(raiz, 0);
        }
        else if(opcao == 4){
            int valor;
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            Buscar(raiz, valor);
        }
        else if(opcao == 5){
            PreOrdem(raiz);
            printf("\n");
            MostrarArvore(raiz, 0);
        }
        else if(opcao == 6){
            PosOrdem(raiz);
            printf("\n");
            MostrarArvore(raiz, 0);
        }
        else if(opcao == 7){
            Ordem(raiz);
            printf("\n");
            MostrarArvore(raiz, 0);
        }
        else{
            printf("Opcao nao encontrada, tente novamente!\n");
        }
    }
    return 0;
}
