#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Funcionario {
    char nome[50];
    int id;
    float salario;
    struct Funcionario *prox;
} Funcionario;

typedef struct Lista {
    Funcionario *inicio;
} Lista;

void inicializa_lista(Lista *lista);

void inserir_funcionario(Lista *lista, char *nome, int id, float salario);

Funcionario* buscar_funcionario(Lista *lista, int id) ;
void remover_funcionario(Lista *lista, int id) ;

void imprimir_lista(Lista *lista) ;

