#include <stdio.h>

int main () {
  int resultado = 0, entrada;

  while((scanf("%d", &entrada)) != -1) {
     resultado += 1;
  }

  printf("%d\n", resultado);

  return 0;
}