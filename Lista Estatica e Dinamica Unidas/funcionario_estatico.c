#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Init lista estatica
void inicializarListaEstatico(ListaEstatico* lista) {
    lista->tamanho = 0;
}
//Add funcionario estatico
void adicionarFuncionarioEstatico(ListaEstatico* lista) {
    if (lista->tamanho < 100) {
        printf("Informe o nome: ");
        scanf(" %49[^\n]", lista->funcionarios[lista->tamanho].nome);
        printf("Informe o cargo: ");
        scanf(" %19[^\n]", lista->funcionarios[lista->tamanho].cargo);
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &lista->funcionarios[lista->tamanho].sexo);
        printf("Informe a idade: ");
        scanf(" %d", &lista->funcionarios[lista->tamanho].idade);
        printf("Informe a matricula: ");
        scanf(" %d", &lista->funcionarios[lista->tamanho].nMatricula);
        lista->tamanho++;
    } else {
        printf("Lista cheia!\n");
    }
}
//Imprime estatico
void imprimirListaEstatico(ListaEstatico* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("\nNome: %s\n", lista->funcionarios[i].nome);
        printf("Cargo: %s\n", lista->funcionarios[i].cargo);
        printf("Sexo: %c\n", lista->funcionarios[i].sexo);
        printf("Idade: %d\n", lista->funcionarios[i].idade);
        printf("Matricula: %d\n", lista->funcionarios[i].nMatricula);
    }
}
//Remove funcionario estatico
void removerFuncionarioEstatico(ListaEstatico* lista, int matricula) {
    int index = -1;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].nMatricula == matricula) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < lista->tamanho - 1; i++) {
            lista->funcionarios[i] = lista->funcionarios[i + 1];
        }
        lista->tamanho--;
        printf("Funcionario removido com sucesso!\n");
    } else {
        printf("Funcionario com matricula %d nao encontrado!\n", matricula);
    }
}
//Func buscar funcionario
void buscarFuncionarioEstatico(ListaEstatico* lista, int matricula) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].nMatricula == matricula) {
            printf("\nNome: %s\n", lista->funcionarios[i].nome);
            printf("Cargo: %s\n", lista->funcionarios[i].cargo);
            printf("Sexo: %c\n", lista->funcionarios[i].sexo);
            printf("Idade: %d\n", lista->funcionarios[i].idade);
            printf("Matricula: %d\n", lista->funcionarios[i].nMatricula);
            return;
        }
    }
    printf("Funcionario com matricula %d nao encontrado!\n", matricula);
}
//Salar 
void salvarListaEstaticoCSV(ListaEstatico* lista, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < lista->tamanho; i++) {
        fprintf(file, "%s,%s,%c,%d,%d\n",
                lista->funcionarios[i].nome,
                lista->funcionarios[i].cargo,
                lista->funcionarios[i].sexo,
                lista->funcionarios[i].idade,
                lista->funcionarios[i].nMatricula);
    }

    fclose(file);
}
//Read lista estatico no arquivo
void lerListaEstaticoCSV(ListaEstatico* lista, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo para leitura.\n");
        return;
    }

    lista->tamanho = 0;
    while (fscanf(file, "%49[^,],%19[^,],%c,%d,%d\n",
                  lista->funcionarios[lista->tamanho].nome,
                  lista->funcionarios[lista->tamanho].cargo,
                  &lista->funcionarios[lista->tamanho].sexo,
                  &lista->funcionarios[lista->tamanho].idade,
                  &lista->funcionarios[lista->tamanho].nMatricula) == 5) {
        lista->tamanho++;
        if (lista->tamanho >= 100) {
            printf("Lista estaticos atingiu o limite de 100 funcionarios.\n");
            break;
        }
    }

    fclose(file);
}
