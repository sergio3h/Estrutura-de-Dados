#include <stdio.h>
#include <string.h>
#include "listaEstatica.h"

int main() {
    ListaFuncionarios lista;
    inicializa_lista(&lista);

    Funcionario func1 = {"João", 123, 2500.0};
    inserir_funcionario(&lista, func1);

    // ... outras inserções, buscas e remoções ...

    imprimir_lista(&lista);

    return 0;
}
