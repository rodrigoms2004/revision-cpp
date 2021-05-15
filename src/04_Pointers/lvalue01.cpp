#include <iostream>
#include <limits>

using namespace std;

// Função que oferece dois retornos. Essa função pega uma entrada no teclado.
// - o retorno formal (bool) indica se a operação foi bem sucedida
// - e o parâmetro referência devolve o valor digitado.
bool validar_entrada(int & param_ref) { // 'param_ref' é uma referência
  // Imprime linhas para exibir conteúdo e endereço do parâmetro
  // (apenas para teste, já que isto não tem nada a ver
  // com o objetivo da função):
  cout << "n-validar_entrada: testando conteudo\n"
       << "e endereço do parametro referencia 'param_ref'\n";
  cout << "conteudo inicial de 'param_ref' = " << param_ref << endl;
  cout << "endereço de 'param_ref' = " << &param_ref << endl;

  // Agora sim, faz o trabalho real desta função:
  cout << "\n-validar_entrada: entre com um numero inteiro: ";
  cin >> param_ref ; // alterando a memória referenciada
  if ( cin.fail() ) {
    cout << "entrada invalida\n";
    // Limpa erros:
    cin.clear();
    // Ignora "newlines" pendentes no buffer:
    cin.ignore( numeric_limits<int>::max() , '\n' );
    return false; // entrada inválida
  }
  return true; // entrada válida

}


int main() {
  int x = 5 ; // 'x' é o apelido de um endereço de memória
              // onde armazenei o número inteiro 5;
  int * p = &x ; // 'p' é o apelido de um outro endereço de memória
                 // onde armazenei o endereço de 'x'
  int & r = x ; // 'r' é uma referência para 'x': ou seja, um novo apelido
                // (um sinônimo) para a mesma posição de memória
                // já apelidada anteriormente como 'x'

  cout << "conteudo de 'x' = " << x << endl;
  cout << "endereço de 'x' = " << &x << endl;  
  cout << "conteudo de 'r' = " << r << endl;
  cout << "endereço de 'r' = " << &r << endl;  
  cout << "conteudo de 'p' = " << p << endl;
  cout << "endereço de 'p' = " << &p << endl;  
  
  // Chama a função 'validar_entrada', passando uma referência para 'x'
  if (validar_entrada(x))
    cout << "\n-main: conteúdo de 'x' após 'validar_entrada' = " << x << endl;
  
  return 0;
}

/*
  conteudo de 'x' = 5
  endereço de 'x' = 0x7ffc5a959f04
  conteudo de 'r' = 5
  endereço de 'r' = 0x7ffc5a959f04
  conteudo de 'p' = 0x7ffc5a959f04
  endereço de 'p' = 0x7ffc5a959f08
  n-validar_entrada: testando conteudo
  e endereço do parametro referencia 'param_ref'
  conteudo inicial de 'param_ref' = 5
  endereço de 'param_ref' = 0x7ffc5a959f04

  -validar_entrada: entre com um numero inteiro: 20

  -main: conteúdo de 'x' após 'validar_entrada' = 20

*/