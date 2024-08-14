#include <stdio.h>
#include <string.h>
#include "listaEstatica.h"

// Função para inicializar a lista
void inicializa_lista(ListaFuncionarios *lista) {
    lista->tamanho = 0;
}

// Função para inserir um funcionário
void inserir_funcionario(ListaFuncionarios *lista, Funcionario funcionario) {
    if (lista->tamanho < MAX_FUNCIONARIOS) {
        lista->funcionarios[lista->tamanho] = funcionario;
        lista->tamanho++;
    } else {
        printf("Lista cheia!\n");
    }
}

// Função para buscar um funcionário pelo ID
Funcionario* buscar_funcionario(ListaFuncionarios *lista, int id) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].id == id) {
            return &lista->funcionarios[i];
        }
    }
    return NULL; // Funcionário não encontrado
}

// Função para remover um funcionário pelo ID (simplificada, sem reordenar)
void remover_funcionario(ListaFuncionarios *lista, int id) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].id == id) {
            // Desloca os elementos subsequentes uma posição para a esquerda
            for (int j = i; j < lista->tamanho - 1; j++) {
                lista->funcionarios[j] = lista->funcionarios[j + 1];
            }
            lista->tamanho--;
            return;
        }
    }
    printf("Funcionário não encontrado!\n");
}

// Função para imprimir a lista de funcionários
void imprimir_lista(ListaFuncionarios *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Nome: %s, ID: %d, Salário: %.2f\n",
               lista->funcionarios[i].nome, lista->funcionarios[i].id, lista->funcionarios[i].salario);
    }
}