#include <stdio.h>
#include "circulo.h"

int main() {
    Circulo *c = cria_circulo(0, 0, 5);
    if (ponto_dentro_circulo(c, 3, 4)) {
        printf("O ponto está dentro do círculo.\n");
    }
    libera_circulo(c);
    return 0;
}
