#include <stdio.h>
#include <stdlib.h>
#include "listaDinamica.h" // Assumindo que suas funções estão em um arquivo chamado lista_funcionarios.h

int main() {
    Lista lista;
    inicializa_lista(&lista);

    int opcao;
    char nome[50];
    int id;
    float salario;
    Funcionario *func;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir funcionário\n");
        printf("2. Buscar funcionário\n");
        printf("3. Remover funcionário\n");
        printf("4. Imprimir lista\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome: ");
                scanf("%s", nome);
                printf("ID: ");
                scanf("%d", &id);
                printf("Salário: ");
                scanf("%f", &salario);
                inserir_funcionario(&lista, nome, id, salario);
                break;
            case 2:
                printf("Digite o ID do funcionário a ser buscado: ");
                scanf("%d", &id);
                func = buscar_funcionario(&lista, id);
                if (func != NULL) {
                    printf("Funcionário encontrado:\n");
                    printf("Nome: %s, ID: %d, Salário: %.2f\n", func->nome, func->id, func->salario);
                } else {
                    printf("Funcionário não encontrado.\n");
                }
                break;
            case 3:
                printf("Digite o ID do funcionário a ser removido: ");
                scanf("%d", &id);
                remover_funcionario(&lista, id);
                break;
            case 4:
                imprimir_lista(&lista);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    // Liberar a memória alocada (importante!)
    // ... (implementar a função para liberar a memória da lista)

    return 0;
}
