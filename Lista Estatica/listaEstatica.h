#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100

typedef struct {
    char nome[50];
    int id;
    float salario;
} Funcionario;

typedef struct {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int tamanho;
} ListaFuncionarios;

// Função para inicializar a lista
void inicializa_lista(ListaFuncionarios *lista) ;

// Função para inserir um funcionário
void inserir_funcionario(ListaFuncionarios *lista, Funcionario funcionario) ;

// Função para buscar um funcionário pelo ID
Funcionario* buscar_funcionario(ListaFuncionarios *lista, int id) ;

// Função para remover um funcionário pelo ID (simplificada, sem reordenar)
void remover_funcionario(ListaFuncionarios *lista, int id) ;
    
// Função para imprimir a lista de funcionários
void imprimir_lista(ListaFuncionarios *lista);