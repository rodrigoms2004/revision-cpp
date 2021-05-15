#include <iostream>

using namespace std;

int main() {

  int x = 5; // 'x' é o apelido de um endereço na memoria onde 5 está armazenado
  int* p = &x; // 'p' é o apelido de um outro endereço de memória onde o endereço de 'x' está armazenado

  cout << "conteúdo de 'x' = " << x << endl;
  cout << "endereço de 'x' = " << &x << endl;
  cout << "conteúdo de 'p' = " << p << endl;
  cout << "endereço de 'p' = " << &p << endl;
  cout << "conteúdo APONTADO por 'p' = " << *p << endl;

  return 0;
}

/*
  conteúdo de 'x' = 5
  endereço de 'x' = 0x7ffc8a2e6b6c
  conteúdo de 'p' = 0x7ffc8a2e6b6c
  endereço de 'p' = 0x7ffc8a2e6b70
  conteúdo APONTADO por 'p' = 5
*/

