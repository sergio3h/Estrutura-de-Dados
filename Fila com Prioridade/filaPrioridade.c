#include <stdio.h>
#include <stdlib.h>
#include "filaPrioridade.h"
#include <string.h>
//Funcao para criar a fila
void CriarFila(FilaCircular *fila)
{
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}
//Funcao para calcular a prioridade
void CriarFilaCircularPrioridade(FilaCircularPrioridade *filaPrioridade)
{
    for (int i = 0; i < PRIORIDADE; i++)
    {
        CriarFila(&(filaPrioridade->vetFilaPrioridade[i]));
    }
}
//Retorna o tamanho da fila
int FilaCheia(FilaCircular *fila)
{
    return fila->tamanho == TAMANHO;
}
//Retorna se a fila esta vazia
int FilaVazia(FilaCircular *fila)
{
    return fila->tamanho == 0;
}

void Enfileirar(FilaCircularPrioridade *filaPrioridade, FuncionarioEmpresa funcionario)
{
    FilaCircular *auxFila = &filaPrioridade->vetFilaPrioridade[funcionario.cargo];

    if (FilaCheia(auxFila))
    {
        printf("Fila já está cheia!!!");
        exit(1);
    }

    auxFila->fim = (auxFila->fim + 1) % TAMANHO;
    auxFila->fila[auxFila->fim] = funcionario;
    auxFila->tamanho++;
}

FuncionarioEmpresa Desenfileirar(FilaCircularPrioridade *filaPrioridade)
{
    for (int i = 0; i < PRIORIDADE; i++)
    {
        FilaCircular *auxFila = &filaPrioridade->vetFilaPrioridade[i];
        if (!FilaVazia(auxFila))
        {
            FuncionarioEmpresa funcionario = auxFila->fila[auxFila->inicio];
            auxFila->inicio = (auxFila->inicio + 1) % TAMANHO;
            auxFila->tamanho--;
            return funcionario;
        }
    }
}
//Imprime a prioridaed da fila
void ImprimirFilaPrioridade(FilaCircularPrioridade *filaPrioridade)
{
    for (int i = 0; i < PRIORIDADE; i++)
    {
        FilaCircular *auxFila = &filaPrioridade->vetFilaPrioridade[i];

        if (!FilaVazia(auxFila))
        {
            int iterador = auxFila->inicio;
            char cargoString[50];
            for (int i = 0; i < auxFila->tamanho; i++)
            {
                switch (auxFila->fila[iterador].cargo)
                {
                case 0:
                    strcpy(cargoString, "Diretor");
                    break;
                case 1:
                    strcpy(cargoString, "Coordenador");
                    break;
                default:
                    strcpy(cargoString, "Funcionario");
                    break;
                }

                printf("Nome: %s, Idade: %d, Cargo: %s\n",
                       auxFila->fila[iterador].nome,
                       auxFila->fila[iterador].idade,
                       cargoString);
                iterador = (iterador + 1) % TAMANHO;
            }
            printf("\n");
        }
    }
}