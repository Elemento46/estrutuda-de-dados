#include <stdio.h>
#include <stdlib.h>

// Estrutura do no da arvore binaria
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Funcao para criar um novo no
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Funcao para inserir um no na arvore
No* incluirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = incluirNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = incluirNo(raiz->direita, valor);
    } else {
        printf("Valor ja existe na arvore\n");
    }
    return raiz;
}

// Funcao para encontrar o menor valor em uma arvore (necessaria para remocao)
No* encontrarMinimo(No* raiz) {
    while (raiz && raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

// Funcao para remover um no da arvore
No* removerNo(No* raiz, int valor) {
    if (raiz == NULL) {
        printf("Valor nao encontrado\n");
        return raiz;
    }
    if (valor < raiz->valor) {
        raiz->esquerda = removerNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = removerNo(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        No* temp = encontrarMinimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = removerNo(raiz->direita, temp->valor);
    }
    return raiz;
}

// Funcoes de busca em profundidade
void buscarPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        buscarPreOrdem(raiz->esquerda);
        buscarPreOrdem(raiz->direita);
    }
}

void buscarEmOrdem(No* raiz) {
    if (raiz != NULL) {
        buscarEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        buscarEmOrdem(raiz->direita);
    }
}

void buscarPosOrdem(No* raiz) {
    if (raiz != NULL) {
        buscarPosOrdem(raiz->esquerda);
        buscarPosOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// Funcao principal
int main() {
    No* raiz = NULL;
    int opcao, valor;

    do {
        printf("\nMENU DE OPCOES:\n");
        printf("1 - Incluir no\n");
        printf("2 - Remover no\n");
        printf("3 - Buscar pre-ordem\n");
        printf("4 - Buscar em ordem\n");
        printf("5 - Buscar pos-ordem\n");
        printf("0 - Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser incluido: ");
                scanf("%d", &valor);
                raiz = incluirNo(raiz, valor);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                raiz = removerNo(raiz, valor);
                break;
            case 3:
                printf("Busca em pre-ordem: ");
                buscarPreOrdem(raiz);
                printf("\n");
                break;
            case 4:
                printf("Busca em ordem: ");
                buscarEmOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("Busca em pos-ordem: ");
                buscarPosOrdem(raiz);
                printf("\n");
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    return 0;
}
