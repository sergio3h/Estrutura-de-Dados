#include <stdlib.h>
#include <stdio.h>
#include "filaPrioridade.h"
#include "funcionario.h"
//Sergio
int main()
{
    FilaCircularPrioridade minhaFila;

    CriarFilaCircularPrioridade(&minhaFila);

    int opcao;

    do
    {
        printf("\nMenu de Operações:\n");
        printf("1. Enfileirar Funcionario\n");
        printf("2. Desenfileirar Funcionario\n");
        printf("3. Imprimir Fila de Prioridade\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            InserirFuncionario(&minhaFila);
            break;
        }
        case 2:
        {
            RemoverFuncionario(&minhaFila);
            break;
        }
        case 3:
        {
            printf("Imprimindo fila de prioridade:\n");
            ImprimirFilaPrioridade(&minhaFila);
            break;
        }
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
