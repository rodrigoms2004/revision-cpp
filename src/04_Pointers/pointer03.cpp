#include <iostream>

using namespace std;

int main() {
  double x = 5;
  // int *p = &x; // não funciona porque o ponteiro é int, e a variável é double
  double *p = &x;

  cout << "conteúdo de 'x' = " << x << endl; // 5
  cout << "endereço de 'x' = " << &x << endl; // 0x7fff1b548448
  cout << "conteúdo de 'p' = " << p << endl; // endereço de x 0x7fff1b548448
  cout << "endereço de 'p' = " << &p << endl; // endereço de p 0x7fff1b548450
  cout << "conteúdo APONTADO por 'p' = " << *p << endl;

  // int *p1 = 100; // ponteiro precisa apontar para endereço


  return 0;
}