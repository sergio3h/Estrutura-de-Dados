#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

Circulo* cria_circulo(float x, float y, float raio) {
    Circulo *c = (Circulo*) malloc(sizeof(Circulo));
    if (c == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    c->x = x;
    c->y = y;
    c->raio = raio;
    return c;
}

void libera_circulo(Circulo *c) {
    free(c);
}

int ponto_dentro_circulo(Circulo *c, float px, float py) {
    float dx = px - c->x;
    float dy = py - c->y;
    float distancia = dx*dx + dy*dy;
    return distancia <= c->raio*c->raio;
}
