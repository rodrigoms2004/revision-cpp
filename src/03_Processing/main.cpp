#include <iostream>
#include "funcoes.h"

using namespace std;

//  g++ main.cpp funcoes.cpp -o main.o

int main(int argc, char *argv[]) {
  cout << "Numero de parametros: " << argc << endl;

  for (int i = 0; i < argc; ++i) {
    // cout << "Parâmetros: " << *(argv + i ) << endl;
    cout << "Parâmetros: " << argv[i] << endl;
  }

  cout << fatorial(10) << endl;
  cout << fatorial_recursivo(10) << endl;
  
  return 0;
}

