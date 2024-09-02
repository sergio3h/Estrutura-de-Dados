//Biblioteca funcionario
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct funcionario Funcionario;

Funcionario* criarNo();
void adicionarFuncionario(Funcionario *novoNode);
Funcionario* inserirNoFinal(Funcionario *Lista);
void imprimirLista(Funcionario* Lista);
Funcionario* removerFuncionario(Funcionario* Lista, int matricula);
void buscarFuncionario(Funcionario* Lista, int matricula);

void salvarListaDinamicaCSV(Funcionario* Lista, const char* filename);
Funcionario* lerListaDinamicaCSV(const char* filename);

typedef struct {
    char nome[50], cargo[20], sexo;
    int idade, nMatricula;
} FuncionarioEstatico;

typedef struct {
    FuncionarioEstatico funcionarios[100];
    int tamanho;
} ListaEstatico;

void inicializarListaEstatico(ListaEstatico* lista);
void adicionarFuncionarioEstatico(ListaEstatico* lista);
void imprimirListaEstatico(ListaEstatico* lista);
void removerFuncionarioEstatico(ListaEstatico* lista, int matricula);
void buscarFuncionarioEstatico(ListaEstatico* lista, int matricula);

void salvarListaEstaticoCSV(ListaEstatico* lista, const char* filename);
void lerListaEstaticoCSV(ListaEstatico* lista, const char* filename);

#endif
