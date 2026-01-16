#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//nó da árvore
struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
};

//protótipos das funções
struct Sala* criarSala(const char *nome);
void explorarSalas(struct Sala *raiz);

int main() {

    //mapa da mansão
    struct Sala *hall = criarSala("Hall de Entrada");

    hall->esquerda = criarSala("Sala de Estar");
    hall->direita  = criarSala("Escritorio");

    hall->esquerda->esquerda = criarSala("Cozinha");
    hall->esquerda->direita  = criarSala("Sala de Jantar");

    hall->direita->esquerda = criarSala("Biblioteca");
    hall->direita->direita  = criarSala("Jardim");

    //exploração
    explorarSalas(hall);

    return 0;
}

//cria uma nova sala dinamicamente
struct Sala* criarSala(const char *nome) {
    struct Sala *novaSala = (struct Sala*) malloc(sizeof(struct Sala));

    if (novaSala == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;

    return novaSala;
}

//exploração da mansão
void explorarSalas(struct Sala *raiz) {
    struct Sala *atual = raiz;
    char opcao;

    while (atual != NULL) {
        printf("\nVoce esta na sala: %s\n", atual->nome);

        
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Nao ha mais caminhos. Exploracao finalizada.\n");
            break;
        }

        printf("Opcoes:\n");

        if (atual->esquerda != NULL)
            printf("e - Ir para a esquerda (%s)\n", atual->esquerda->nome);

        if (atual->direita != NULL)
            printf("d - Ir para a direita (%s)\n", atual->direita->nome);

        printf("s - Sair\n");
        printf("Escolha: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        }
        else if (opcao == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        }
        else if (opcao == 's') {
            printf("Exploracao encerrada pelo jogador.\n");
            break;
        }
        else {
            printf("Opcao invalida!\n");
        }
    }
}
