#include <iostream>

using namespace std;

int main() {
  int a = 1, b = 2;
  // captura a e b por valor; retorno da lambda deduzido do return do corpo (int):
  int x1 =[=]() { return a + b; }();
  // captura a e b por valor; retorno especificado explicitamente como double:
  double x2 = [=]() -> double { return double(a + b)/2; } ();
  // não captura nada; "a" e "b" são copiados para os parâmetros "x" e "y":
  int x3 = [](int x, int y) { return x + y; } (a, b);
  
  cout << "int x1 = " << x1 << ", double x2 = " << x2 << ", int x3 = " << x3 << '\n';

  // Resultado: int x1 = 3, double x2 = 1.5, int x3 = 3
  return 0;
}