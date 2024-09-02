#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
//Funcao Insere Funcionario
void InserirFuncionario(FilaCircularPrioridade *minhaFila)
{
    FuncionarioEmpresa funcionario;
    printf("Digite o nome do funcionario: ");
    scanf("%s", funcionario.nome);
    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionario.idade);
    printf("Digite o cargo do funcionario (0: Diretor, 1: Coordenador, 2: Funcionario): ");
    scanf("%d", &funcionario.cargo);

    Enfileirar(minhaFila, funcionario);
    printf("Funcionario enfileirado com sucesso!\n");
}
//Funcao remove funcionario
void RemoverFuncionario(FilaCircularPrioridade *minhaFila)
{
    FuncionarioEmpresa funcionario = Desenfileirar(minhaFila);
    if (funcionario.idade != 0 || funcionario.cargo != 0 || funcionario.nome[0] != '\0')
    {
        printf("Funcionario desenfileirado: Nome: %s, Idade: %d, Cargo: %d\n",
               funcionario.nome, funcionario.idade, funcionario.cargo);
    }
}