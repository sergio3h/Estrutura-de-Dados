#include <stdio.h>
#include "ponto.h"


int main() {
  ponto *p =CriarPonto(2, 5);

  ponto *q =CriarPonto(3, 4);

  Atribui(p, 3, 6);
  printf("A disntancia entre os pontos é: %f\n", Distancia(p, q));
  
  LiberaPonto(p);
  LiberaPonto(q);
  return 0;
}