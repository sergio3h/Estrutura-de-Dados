#define TAMANHO 50

typedef struct pilhaEstatica
{
    int vet[TAMANHO];
    int fim;
} PilhaEstatica;

int PilhaVazia(PilhaEstatica *pilha);
int PilhaCheia(PilhaEstatica *pilha);
void IniciaPilhaEstatica(PilhaEstatica *pilha);
void EmpilharNumeros(PilhaEstatica *pilha, int numero);
int DesempilhaNumeros(PilhaEstatica *pilha);
void FazerCalculo(PilhaEstatica *pilha, char caractere);
void ImprimirPilha(PilhaEstatica *pilha);
