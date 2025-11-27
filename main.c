#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Sala {
    char nome[50];         
    struct Sala *esquerda; 
    struct Sala *direita;   
} Sala;


Sala* criarSala(char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    
    if (novaSala == NULL) {
        printf("Erro: Falha ao alocar memória!\n");
        exit(1);
    }

    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;

    return novaSala;
}

void explorarSalas(Sala* salaAtual) {
    char escolha;

    printf("\n=== INICIANDO A EXPLORAÇÃO ===\n");

    while (salaAtual != NULL) {
        printf("\nVocê está em: [ %s ]\n", salaAtual->nome);

        if (salaAtual->esquerda == NULL && salaAtual->direita == NULL) {
            printf("Esta sala não tem mais saídas. Você encontrou uma pista final!\n");
            printf("Fim da exploração.\n");
            break; 
        }

        
        printf("Para onde deseja ir? (e = esquerda, d = direita, s = sair): ");
        scanf(" %c", &escolha); // O espaço antes de %c consome quebras de linha pendentes

        if (escolha == 'e' || escolha == 'E') {
            if (salaAtual->esquerda != NULL) {
                salaAtual = salaAtual->esquerda; 
                printf("A porta da esquerda está trancada ou não existe.\n");
            }
        } 
        else if (escolha == 'd' || escolha == 'D') {
            if (salaAtual->direita != NULL) {
                salaAtual = salaAtual->direita; 
            } else {
                printf("A porta da direita está trancada ou não existe.\n");
            }
        } 
        else if (escolha == 's' || escolha == 'S') {
            printf("Saindo da mansão...\n");
            break;
        } 
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}


int main() {

    Sala* raiz = criarSala("Hall de Entrada");


    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* biblioteca = criarSala("Biblioteca");


    Sala* cozinha = criarSala("Cozinha");
    Sala* jardim = criarSala("Jardim Secreto");

    raiz->esquerda = salaEstar;
    raiz->direita = biblioteca;

    salaEstar->esquerda = cozinha; 

    biblioteca->direita = jardim;  


    printf("Bem-vindo ao Detective Quest!\n");
    printf("Sua missão é encontrar pistas explorando a mansão.\n");
    
    explorarSalas(raiz);

    return 0;
}