#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#define TAMANHO 50
#define PRIORIDADE 3

typedef struct funcionarioEmpresa
{
    int idade, cargo;
    char nome[50];
} FuncionarioEmpresa;

typedef struct filaCircular
{
    FuncionarioEmpresa fila[TAMANHO];
    int inicio, fim, tamanho;
} FilaCircular;

typedef struct filaCircularPrioridade
{
    FilaCircular vetFilaPrioridade[PRIORIDADE];

} FilaCircularPrioridade;

void CriarFila(FilaCircular *fila);
void CriarFilaCircularPrioridade(FilaCircularPrioridade *filaPrioridade);
int FilaCheia(FilaCircular *fila);
int FilaVazia(FilaCircular *fila);
void Enfileirar(FilaCircularPrioridade *filaPrioridade, FuncionarioEmpresa funcionario);
FuncionarioEmpresa Desenfileirar(FilaCircularPrioridade *filaPrioridade);
void ImprimirFilaPrioridade(FilaCircularPrioridade *filaPrioridade);

#endif // FILA_PRIORIDADE_H
