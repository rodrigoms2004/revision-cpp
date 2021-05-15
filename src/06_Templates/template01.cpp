#include <iostream>

using namespace std;

// para identificar um parâmetro template
// podemos usar "class" ou "typename"
// a função template pode ser inline ou não, dependendo do caso,

template<typename TIPO_PARAM>
TIPO_PARAM inline Minimo(TIPO_PARAM a, TIPO_PARAM b) {
  return (a < b) ? a : b;
}

int main() {

  int X = 5, Y = 5;
  double A = 3.4, B = 5.6;

  cout << Minimo<double>(A, X) << endl; // TIPO_PARAM será double
  cout << Minimo<int>(X,Y) << endl;     // TIPO_PARAM será double
  cout <<  Minimo(X,Y) << endl;         // TIPO_PARAM será int já que os tipos de x e y estão claros

  cout << Minimo(A, (double)X) << endl; // TIPO_PARAM será double já que A é double e X foi convertido para double

  cout << Minimo( X , Y ) << endl; // o TIPO Parametrizado será int
  cout << Minimo( A , B ) << endl; // o TIPO Parametrizado será double

  return 0;
}