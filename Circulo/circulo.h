#ifndef CIRCULO_H
#define CIRCULO_H

typedef struct {
    float x;   // Coordenada x do centro
    float y;   // Coordenada y do centro
    float raio; // Raio do círculo
} Circulo;

// Funções protótipos
Circulo* cria_circulo(float x, float y, float raio);
void libera_circulo(Circulo *c);
int ponto_dentro_circulo(Circulo *c, float px, float py);

#endif // CIRCULO_H
