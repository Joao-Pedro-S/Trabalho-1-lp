#include <stdio.h>
#include <stdlib.h>

/*como char possui tamanho de 1 byte,
isto é usado para navegar entre o endereço usado para o contador
e o dado guardado na variável.
Talvez não seja necessário, mas evitou um bug que ocorria com void*/

void *malloc2(int tamanho) {
  char *aux = (char *)malloc(sizeof(int) + tamanho);
  int *count = (int *)aux;
  *count = 1;
  void *ret; // retorno
  ret = aux + sizeof(int);
  return ret;
}
///* pra teste
int quant(void *x) {
  void *end = (char *)x - sizeof(int);
  int *cont = (int *)end;
  return *cont;
}
//*/
void atrib2(void **x, void *y) {
  if (y == NULL) {
    int *aux = (int *)*x - 1;
    *aux = *aux - 1;
    *x = NULL;
    if (*aux == 0) {
      free(*x);
      free(aux);
    }
    return;
  }
  int *aux = (int *)*x - 1;
  void *aux2 = *x;
  int *aux3 = (int *)y - 1;
  *aux = *aux - 1;
  *x = y;
  *aux3 = *aux3 + 1;
  if (*aux == 0) {
    free(aux2);
    free(aux);
  }
}