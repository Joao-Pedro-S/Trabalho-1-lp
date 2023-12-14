#include "Coletor.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *v = malloc2(sizeof(int));
  *v = 10;
  printf("%d %d\n", *v, quant(v));
  int *w = malloc2(sizeof(int));
  *w = 20;
  printf("%d %d\n", *w, quant(w));
  atrib2((void**)&v, (void *)w);
  printf("%d %d\n", *w, quant(w));
  printf("%d %d\n", *v, quant(v));
  atrib2((void **)&w, NULL);
  printf("%d %d\n", *v, quant(v));
  char *s = (char *)malloc2(sizeof(char) * 4);
  *s = 'B';
  printf("%c %d", *s, quant(s));
  atrib2((void **)&s, NULL);
  /* //teste de NULL, funciona.
  if (s == NULL)
    printf("a");
  */
  return 0;
}
