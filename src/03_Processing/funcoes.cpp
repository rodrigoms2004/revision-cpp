#include "funcoes.h"

int fatorial(int n) {
  int result;
  for (result = 1; n > 1; n--) {
    result *= n;
  }
  return result;
}

int fatorial_recursivo(int n) {
  return (n <= 1) ? 1 : n * fatorial_recursivo(n - 1);
}