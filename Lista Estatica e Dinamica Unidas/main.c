#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"
//Sergio
#define LISTA_DINAMICA 1
#define LISTA_ESTATICA 2

void salvarDados(Funcionario* listaDinamica, ListaEstatico* listaEstatica, int tipoLista) {
    if (tipoLista == LISTA_DINAMICA) {
        salvarListaDinamicaCSV(listaDinamica, "funcionarios_dinamicos.csv");
    } else {
        salvarListaEstaticoCSV(listaEstatica, "funcionarios_estaticos.csv");
    }
}

void carregarDados(Funcionario** listaDinamica, ListaEstatico* listaEstatica, int tipoLista) {
    if (tipoLista == LISTA_DINAMICA) {
        *listaDinamica = lerListaDinamicaCSV("funcionarios_dinamicos.csv");
    } else {
        lerListaEstaticoCSV(listaEstatica, "funcionarios_estaticos.csv");
    }
}

int main() {
    int escolha, tipoLista, matricula;
    Funcionario *ListaDinamica = NULL;
    ListaEstatico listaEstatica;
    inicializarListaEstatico(&listaEstatica);

    printf("Escolha o tipo de lista:\n");
    printf("1- Lista Dinâmica\n");
    printf("2- Lista Estática\n");
    printf("Informe sua escolha: ");
    scanf("%d", &tipoLista);
    system("clear");

    if (tipoLista != LISTA_DINAMICA && tipoLista != LISTA_ESTATICA) {
        printf("Tipo de lista inválido! Encerrando programa.\n");
        return 1;
    }

    // Carregar listas de arquivos CSV ao iniciar o programa
    carregarDados(&ListaDinamica, &listaEstatica, tipoLista);

    do {
        printf("---------------MENU---------------\n");
        printf("0- Encerrar operacao\n");
        printf("1- Adicionar funcionario\n");
        printf("2- Remover funcionario\n");
        printf("3- Imprimir funcionarios\n");
        printf("4- Buscar funcionario\n");
        printf("\nInforme o que voce deseja: ");
        scanf("%d", &escolha);
        system("clear");

        switch (escolha) {
            case 1:
                if (tipoLista == LISTA_DINAMICA) {
                    ListaDinamica = inserirNoFinal(ListaDinamica);
                } else {
                    adicionarFuncionarioEstatico(&listaEstatica);
                }
                salvarDados(ListaDinamica, &listaEstatica, tipoLista);
                break;
            case 2:
                printf("Informe a matricula do funcionario a ser removido: ");
                scanf("%d", &matricula);
                if (tipoLista == LISTA_DINAMICA) {
                    ListaDinamica = removerFuncionario(ListaDinamica, matricula);
                } else {
                    removerFuncionarioEstatico(&listaEstatica, matricula);
                }
                salvarDados(ListaDinamica, &listaEstatica, tipoLista);
                break;
            case 3:
                if (tipoLista == LISTA_DINAMICA) {
                    imprimirLista(ListaDinamica);
                } else {
                    imprimirListaEstatico(&listaEstatica);
                }
                break;
            case 4:
                printf("Informe a matricula do funcionario a ser buscado: ");
                scanf("%d", &matricula);
                if (tipoLista == LISTA_DINAMICA) {
                    buscarFuncionario(ListaDinamica, matricula);
                } else {
                    buscarFuncionarioEstatico(&listaEstatica, matricula);
                }
                break;
            case 0:
                printf("Operacao encerrada!\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (escolha != 0);

    salvarDados(ListaDinamica, &listaEstatica, tipoLista);

    return 0;
}
