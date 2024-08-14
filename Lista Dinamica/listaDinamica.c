#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDinamica.h"


void inicializa_lista(Lista *lista) {
  lista->inicio = NULL;
}

void inserir_funcionario(Lista *lista, char *nome, int id, float salario) {
  Funcionario *novo = (Funcionario*) malloc(sizeof(Funcionario));
  strcpy(novo->nome, nome);
  novo->id = id;
  novo->salario = salario;
  novo->prox = lista->inicio;
  lista->inicio = novo;
}

Funcionario* buscar_funcionario(Lista *lista, int id) {
  Funcionario *aux = lista->inicio;
  while (aux != NULL && aux->id != id) {
      aux = aux->prox;
  }
  return aux;
}

void remover_funcionario(Lista *lista, int id) {
  Funcionario *aux = lista->inicio, *ant = NULL;
  while (aux != NULL && aux->id != id) {
      ant = aux;
      aux = aux->prox;
  }
  if (aux != NULL) {
      if (ant == NULL) {
          lista->inicio = aux->prox;
      } else {
          ant->prox = aux->prox;
      }
      free(aux);
  }
}

void imprimir_lista(Lista *lista) {
  Funcionario *aux = lista->inicio;
  while (aux != NULL) {
      printf("Nome: %s, ID: %d, Salário: %.2f\n", aux->nome, aux->id, aux->salario);
      aux = aux->prox;
  }
}
