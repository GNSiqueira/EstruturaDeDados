#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct Arvore {
    int chave;
    int altura;
    struct Arvore *esquerda;
    struct Arvore *direita;
} Arvore;

// Função para criar um novo nó
Arvore* CriarNo(int chave) {
    Arvore *NovoNo = (Arvore*)malloc(sizeof(Arvore));
    NovoNo->chave = chave;
    NovoNo->esquerda = NULL;
    NovoNo->direita = NULL;
    NovoNo->altura = 1;
    return NovoNo;
}

// Função para obter a altura de um nó
int Altura(Arvore *no) {
    if (no == NULL) 
        return 0;
    return no->altura;
}

// Função para obter o fator de balanceamento de um nó
int FatorDeBalanceamento(Arvore *no) {
    if (no == NULL)
        return 0;
    return Altura(no->esquerda) - Altura(no->direita);
}

// Função para atualizar a altura de um nó
void AtualizarAltura(Arvore *no) {
    if (no != NULL)
        no->altura = 1 + (Altura(no->esquerda) > Altura(no->direita) ? Altura(no->esquerda) : Altura(no->direita));
}

// Função para realizar uma rotação simples à direita
Arvore* RotacaoSimplesDireita(Arvore *noY) {
    Arvore *noX = noY->esquerda;
    Arvore *temp = noX->direita;

    noX->direita = noY;
    noY->esquerda = temp;

    AtualizarAltura(noY);
    AtualizarAltura(noX);

    return noX;
}

// Função para realizar uma rotação simples à esquerda
Arvore* RotacaoSimplesEsquerda(Arvore *noX) {
    Arvore *noY = noX->direita;
    Arvore *temp = noY->esquerda;

    noY->esquerda = noX;
    noX->direita = temp;

    AtualizarAltura(noX);
    AtualizarAltura(noY);

    return noY;
}

// Função para realizar uma rotação dupla à direita
Arvore* RotacaoDuplaDireita(Arvore *no) {
    no->direita = RotacaoSimplesEsquerda(no->direita);
    return RotacaoSimplesDireita(no);
}

// Função para realizar uma rotação dupla à esquerda
Arvore* RotacaoDuplaEsquerda(Arvore *no) {
    no->esquerda = RotacaoSimplesDireita(no->esquerda);
    return RotacaoSimplesEsquerda(no);
}

// Função para balancear um nó
Arvore* Balancear(Arvore *no) {
    int balanceamento = FatorDeBalanceamento(no);

    if (balanceamento > 1) {
        if (FatorDeBalanceamento(no->esquerda) <= 0) {
            return RotacaoSimplesDireita(no);
        } else {
            return RotacaoDuplaDireita(no);
        }
    }

    if (balanceamento < -1) {
        if (FatorDeBalanceamento(no->direita) <= 0) {
            return RotacaoSimplesEsquerda(no);
        } else {
            return RotacaoDuplaDireita(no);
        }
    }

    return no;
}

// Função para inserir um nó na árvore
Arvore* Inserir(Arvore *no, int chave) {
    if (no == NULL)
        return CriarNo(chave);

    if (chave < no->chave)
        no->esquerda = Inserir(no->esquerda, chave);
    else if (chave > no->chave)
        no->direita = Inserir(no->direita, chave);
    else
        return no;  // Chave duplicada

    AtualizarAltura(no);
    return Balancear(no);
}

// Função para encontrar o valor mínimo de uma árvore
Arvore* ValorMinimo(Arvore *no) {
    Arvore *noAtual = no;
    while (noAtual->esquerda != NULL)
        noAtual = noAtual->esquerda;
    return noAtual;
}

// Função para apagar um nó da árvore
Arvore* Apagar(Arvore *no, int chave) {
    if (no == NULL)
        return no;

    if (chave < no->chave)
        no->esquerda = Apagar(no->esquerda, chave);
    else if (chave > no->chave)
        no->direita = Apagar(no->direita, chave);
    else {
        if (no->esquerda == NULL || no->direita == NULL) {
            Arvore *temp = no->esquerda ? no->esquerda : no->direita;
            if (temp == NULL) {
                temp = no;
                no = NULL;
            } else
                *no = *temp;
            free(temp);
        } else {
            Arvore *temp = ValorMinimo(no->direita);
            no->chave = temp->chave;
            no->direita = Apagar(no->direita, temp->chave);
        }
    }

    if (no == NULL)
        return no;

    AtualizarAltura(no);
    return Balancear(no);
}

// Função para buscar um nó na árvore
Arvore* Buscar(Arvore *no, int chave) {
    if (no == NULL || no->chave == chave)
        return no;

    if (chave < no->chave)
        return Buscar(no->esquerda, chave);
    return Buscar(no->direita, chave);
}

// Função para imprimir a árvore em pré-ordem
void PercursoPreOrdem(Arvore *no) {
    if (no != NULL) {
        printf("%d ", no->chave);
        PercursoPreOrdem(no->esquerda);
        PercursoPreOrdem(no->direita);
    }
}

// Função para imprimir a árvore em ordem
void PercursoEmOrdem(Arvore *no) {
    if (no != NULL) {
        PercursoEmOrdem(no->esquerda);
        printf("%d ", no->chave);
        PercursoEmOrdem(no->direita);
    }
}

// Função para imprimir a árvore em pós-ordem
void PercursoPosOrdem(Arvore *no) {
    if (no != NULL) {
        PercursoPosOrdem(no->esquerda);
        PercursoPosOrdem(no->direita);
        printf("%d ", no->chave);
    }
}

// Função para mostrar a árvore de forma gráfica
void MostrarArvore(Arvore *no, int espaco) {
    if (no == NULL)
        return;

    espaco += 5;

    MostrarArvore(no->direita, espaco);

    for (int i = 5; i < espaco; i++)
        printf(" ");
    printf("%d\n", no->chave);

    MostrarArvore(no->esquerda, espaco);
}

// Função principal
int main() {
    Arvore *raiz = NULL;

    raiz = Inserir(raiz, 10);
    raiz = Inserir(raiz, 20);
    raiz = Inserir(raiz, 30);
    raiz = Inserir(raiz, 40);
    raiz = Inserir(raiz, 50);
    raiz = Inserir(raiz, 25);

    printf("Pré-Ordem: ");
    PercursoPreOrdem(raiz);
    printf("\n");

    printf("Em-Ordem: ");
    PercursoEmOrdem(raiz);
    printf("\n");

    printf("Pós-Ordem: ");
    PercursoPosOrdem(raiz);
    printf("\n");

    printf("Estrutura da Árvore:\n");
    MostrarArvore(raiz, 0);

    raiz = Apagar(raiz, 20);

    printf("Após apagar 20:\n");
    MostrarArvore(raiz, 0);

    return 0;
}
