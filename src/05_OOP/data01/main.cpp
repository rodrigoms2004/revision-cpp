#include <iostream>
#include "data.h"

// g++ data.cpp main.cpp -o main.o

using namespace std;

void imprime(const Data & dt) /// função auxiliar para imprimir Data
{
  cout << dt.toString() << endl;
}

int main() {
  Data d1;
  d1.altera(31,1,2001); imprime(d1); // resultado: 31/01/2001
  d1.altera(29,2,2001); imprime(d1); // resultado: ERRO
  d1.altera(29,2,1997); imprime(d1); // resultado: ERRO
  d1.altera(29,2,1800); imprime(d1); // resultado: ERRO
  d1.altera(29,2,1996); imprime(d1); // resultado: 29/02/1996
  d1.altera(29,2,2000); imprime(d1); // resultado: 29/02/2000
  d1.altera(31,6,2001); imprime(d1); // resultado: ERRO
  d1.altera(31,7,2001); imprime(d1); // resultado: 31/07/2001
  d1.altera(31,8,2001); imprime(d1); // resultado: 31/08/2001
  d1.altera(31,9,2001); imprime(d1); // resultado: ERRO
  d1.altera(31,12,2001); imprime(d1); // resultado: 31/12/200

  cout << endl;

  Data d2;
  d2.altera(1, 1, 2001);
  int comp = d1.Compara(d2);

  if (d1 > d2) //(comp > 0) 
    cout << "d1 maior\n";
  else if (d1 < d2) //(comp < 0) 
    cout << "d1 menor\n";
  else
    cout << "iguais\n";
  return 0;



}