#include <iostream>

using namespace std;

// bool funcao(int *p, int n) {
//   for (int contador = 0; contador < n; ++contador)
//     *p += 3; // ...*p = *p + 3 ... // duplos acessos repetidamente
    
//     if (*p > 100) 
//       return false;
//     else
//       return true;
// }

// mesma função acima mas minimizando duplos acessos
bool funcao( int * p, int n ) {
  int temp = * p ; // faz uma cópia inicial do valor apontado por 'p'
                   // aqui tempos um primeiro duplo acesso.
  for ( int contador = 0 ; contador < n ; ++contador )
    temp += 3 ; // acumula o valor em 'temp', com um único acesso
  
  if ( temp > 100 )
    return false ;
  else {
    *p = temp;  // Altera, de uma única vez, a memória apontada por 'p'
                // com o resultado acumulado em 'temp'.
                // Aqui temos um segundo duplo acesso - e não mais que isso.
    return true;
  }
}

int main() {
  int x = 5;

  // Na chamada abaixo, não teremos muitos duplos acessos em 'funcao':
  if (funcao(&x, 2)) 
    cout << "- 'x' agora contém : " << x << endl;
  else
    cout << "- 'x' com valor inválido após 'funcao'" << endl;

  // Mas agora teremos:
  if (funcao(&x, 100)) 
    cout << "- 'x' agora contém : " << x << endl;
  else
    cout << "- 'x' com valor inválido após 'funcao'" << endl;

  return 0; 
}