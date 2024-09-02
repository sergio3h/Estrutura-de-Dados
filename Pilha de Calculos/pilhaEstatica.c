#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "pilhaEstatica.h"
//Funcaoo para iniciar a pilha
int PilhaVazia(PilhaEstatica *pilha)
{
    return pilha->fim == -1;
}
//Funcao que retorna 1 se a pilha estiver vazia e 0 se nao estiver
int PilhaCheia(PilhaEstatica *pilha)
{
    return pilha->fim == TAMANHO - 1;
}
//Funcao para iniciar pilha
void IniciaPilhaEstatica(PilhaEstatica *pilha)
{
    pilha->fim = -1;
}
//Funcao para empilhar numeros de forma estatica
void EmpilharNumeros(PilhaEstatica *pilha, int numero)
{
    if (PilhaCheia(pilha))
    {
        printf("Pilha esta cheia!!");
        return;
    }

    pilha->fim++;
    pilha->vet[pilha->fim] = numero;
}
//Funcao para desempilhar os numeros
int DesempilhaNumeros(PilhaEstatica *pilha)
{
    if (PilhaVazia(pilha))
    {
        printf("Pilha esta Vazia!!!");
        return -1;
    }
    return pilha->vet[(pilha->fim)--];
}
//Funcao para fazer o calculo
void FazerCalculo(PilhaEstatica *pilha, char caractere)
{
    int operando2 = DesempilhaNumeros(pilha);
    int operando1 = DesempilhaNumeros(pilha);
    int resultado;

    if (operando1 != -1 && operando2 != -1)
    {
        switch (caractere)
        {
        case '*':
            resultado = operando1 * operando2;
            break;
        case '+':
            resultado = operando1 + operando2;
            break;
        case '-':
            resultado = operando1 - operando2;
            break;
        case '/':
            if (operando2 == 0)
            {
                printf("Divisor é zero, resultado indefinido!!!");
                return;
            }
            resultado = operando1 / operando2;
            break;
        default:
            printf("Operador desconhecido: %c\n", caractere);
            return;
        }

        EmpilharNumeros(pilha, resultado);
    }
}
//Funcao Imprimir
void ImprimirPilha(PilhaEstatica *pilha)
{
    if (!PilhaVazia(pilha))
    {
        for (int i = 0; i <= pilha->fim; i++)
        {
            printf("%d ", pilha->vet[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Pilha vazia!!");
    }
}