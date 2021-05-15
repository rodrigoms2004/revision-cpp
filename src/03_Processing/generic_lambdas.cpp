#include <iostream>

using namespace std;

auto soma = [](auto a, auto b) -> auto { return a + b; };

int main() {
  string nome = "Agit", sobrenome = "Informatica";
  double x = 20.5, y = 79.5;
  // Qual será o tipo dos parâmetros "a" e "b" e do retorno na expressão lambda,
  // nas chamadas abaixo?
  cout << soma(nome, sobrenome) << '\n'; // "a", "b" e o retorno são do tipo string
  cout << soma(x, y) << '\n'; // "a", "b" e o retorno são do tipo double.

  return 0;
}