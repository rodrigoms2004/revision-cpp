#include <iostream>
#include <limits>

using namespace std;

/* 
  Função que oferece dois retornos.
  Essa função pega uma entrad ano telcado.
  - o retorno formal (bool) indica se a operação foi bem sucedida
  - e o parâmetro ponteiro devolve o valor digitado
*/

bool validar_entrada(int* param_ptr) {
  // Imprime linhas para exibir conteúdo e endereço do parâmetro
  // (apenas para teste, já que isto não tem nada a ver
  // com o objetivo da função):

  cout << "\n-validar_entrada: testando conteudo\n"
            << "e endereco do parametro 'param_ptr'\n";
  cout << "conteudo de 'param_ptr' = " << param_ptr << '\n';
  cout << "endereco de 'param_ptr' = " << &param_ptr << '\n';
  cout << "conteudo inicialmente APONTADO por 'param_ptr' = " << *param_ptr << '\n';

  // Agora sim, faz o trabalho real desta função:
  cout << "\n-validar_entrada: entre com um numero inteiro: ";
  cin >> *param_ptr ; // alterando a memória APONTADA

  if (cin.fail()) {
    cout << "entrada invalida\n";
    // Limpa erros:
    cin.clear();
    // Ignora "new-lines" pendentes no buffer:
    cin.ignore( numeric_limits<int>::max() , '\n' );

    return false ; // entrada inválida
  }
  return true; // entrada válida
} 

int main() {
  int x = 5 ; // 'x' é o apelido de um endereço de memória
              // onde armazenei o NÚMERO INTEIRO 5;
  cout << "-main: conteudo de 'x': "<< x << '\n';
  cout << "-main: endereco de 'x': "<< &x << '\n';
  
  // Chama a função 'validar_entrada', passando o endereco de 'x'
  if ( validar_entrada ( &x ) )
    cout << "\n-main: conteudo de 'x' apos 'validar_entrada' = " << x << '\n';

  return 0;
}

/*
  -main: conteudo de 'x': 5
  -main: endereco de 'x': 0x7ffc67a58024

  -validar_entrada: testando conteudo
  e endereco do parametro 'param_ptr'
  conteudo de 'param_ptr' = 0x7ffc67a58024
  endereco de 'param_ptr' = 0x7ffc67a58008
  conteudo inicialmente APONTADO por 'param_ptr' = 5

  -validar_entrada: entre com um numero inteiro: 15

  -main: conteudo de 'x' apos 'validar_entrada' = 15
*/