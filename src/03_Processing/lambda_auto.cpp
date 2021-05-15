#include <iostream>

using namespace std;

double menor(double a, double b) {
  return a < b ? a : b;
}

// "lambdaMenor" armazena uma expressão lambda
auto lambdaMenor = [](double a, double b) -> double { return a < b ? a : b; };

int main() {
  cout << menor(10, 20) << "\n\n"; // chama diretamente a função "menor"
  cout << lambdaMenor(10, 20) << '\n'; // chama a expressão lambda através
                                       // da variável "lambdaMenor"; com isso a função "menor" será chamada pela lambda
  return 0;
}