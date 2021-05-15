#include <iostream>
using namespace std;

// Passagem de parametros por referencia lvalue
int soma(int &a, int &b) {
  return a + b;
}

// Passagem de parametros por referencia rvaluue
int somaComRvalue(int &&a, int &&b) {
  return a + b;
}

int main() {
  int a = 10;
  int &b = a; // referencia lvalue
  // int &c = 10; // Erro, não pode referenciar uma rvalue (10, que é temporário)
  int &&d = 10; // Ok, 'd' é rvalue, logo pode referenciar 10 (que é temporário: rvalue)
  // cout << soma(10, 10) << endl; // Erro, tentando passar temporários para lvalues...
  cout << "Soma Lvalue:" << soma(a, b) << endl; // Correto: "a" e "b" não temporários

  cout << "Soma Rvalue:" << somaComRvalue(20, 20) << endl; // Ok: rvalues
  return 0;
}