
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilhaEstatica.h"

int main()
{
    PilhaEstatica minhaPilha;
    IniciaPilhaEstatica(&minhaPilha);

    int opcao = 1;
    //Todas as opçoes de teste
    do
    {
        int opcaoNPI;

        ImprimirPilha(&minhaPilha);

        printf("Escolha o que inserir na NPI: EX - (2 3 4 + -)\n1. Numero\n2. Operador\n3.Sair e exibir resultado\n");
        scanf("%d", &opcaoNPI);

        while (opcaoNPI < 1 || opcaoNPI > 3)
        {
            printf("Escolha o que inserir na NPI: EX - (2 3 4 + -)\n1. Numero\n2. Operador\n\n");
            scanf("%d", &opcaoNPI);
        }

        system("clear");

        if (opcaoNPI == 1)
        {
            int numero;
            printf("Digite o numero:");
            scanf("%d", &numero);
            while (isdigit(numero))
            {

                printf("Digite um numero:");
                scanf("%d", &numero);
            }
            EmpilharNumeros(&minhaPilha, numero);
            continue;
        }
        else if (opcaoNPI == 2)
        {
            char operador;
            printf("Digite o operador:");
            scanf(" %c", &operador);
            FazerCalculo(&minhaPilha, operador);
            continue;
        }
        opcao = 0;

    } while (opcao != 0);

    printf("Resultado:\n");
    ImprimirPilha(&minhaPilha);

    return 0;
}
