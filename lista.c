#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int data;                
    struct Node *next;       
} Node;


Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertNode(Node **head, int data) {#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct No {
    int valor;                 
    struct No* proximo;        
} No;


void incluir(No** inicio, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo->valor = valor;
    novo->proximo = *inicio;
    *inicio = novo;
    printf("Valor %d incluído com sucesso.\n", valor);
}

void listar(No* inicio) {
    if (inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("Elementos da lista: ");
    while (inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n");
}

No* buscar(No* inicio, int valor) {
    while (inicio != NULL) {
        if (inicio->valor == valor) {
            return inicio;
        }
        inicio = inicio->proximo;
    }
    return NULL;
}

void alterar(No* inicio, int valor_antigo, int valor_novo) {
    No* no = buscar(inicio, valor_antigo);
    if (no != NULL) {
        no->valor = valor_novo;
        printf("Valor %d alterado para %d.\n", valor_antigo, valor_novo);
    } else {
        printf("Valor %d não encontrado.\n", valor_antigo);
    }
}

void remover(No** inicio, int valor) {
    No* atual = *inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Valor %d não encontrado na lista.\n", valor);
        return;
    }

    if (anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Valor %d removido com sucesso.\n", valor);
}

void liberar_lista(No** inicio) {
    No* atual = *inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    *inicio = NULL;
}

int main() {
    No* inicio = NULL;
    int opcao, valor, valor_antigo, valor_novo;

    do {
        printf("\nMenu:\n");
        printf("1 - Incluir\n");
        printf("2 - Listar\n");
        printf("3 - Alterar\n");
        printf("4 - Remover\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser incluído: ");
                scanf("%d", &valor);
                incluir(&inicio, valor);
                break;
            case 2:
                listar(inicio);
                break;
            case 3:
                printf("Digite o valor a ser alterado: ");
                scanf("%d", &valor_antigo);
                printf("Digite o novo valor: ");
                scanf("%d", &valor_novo);
                alterar(inicio, valor_antigo, valor_novo);
                break;
            case 4:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                remover(&inicio, valor);
                break;
            case 5:
                liberar_lista(&inicio);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    return 0;
}

    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; 
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
    }
}
