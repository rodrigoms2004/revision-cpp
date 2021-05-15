#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main() {
  vector<int> vec;
  string str;
  
  const char inicial_min = 'A';
  const char final_max = 'Z';
  
  bool continuar = true;
  
  while (continuar) {
    bool valores_validos = true;
    char inicial, final;
    int razao;

    cout << "Informe Inicial, Final e Razao." << endl;
    cout << "Limites: A <= Inicial <= Final <= Z." << endl;
    cout << "Razao: maior que zero e menor ou igual a (Final - Inicial + 1)" << endl;

    cin >> inicial >> final >> razao;

    // falha na entrada
    if (cin.fail()) {
      cout << "valores incorretos\n";
      // como houve falha é preciso limpar os flags de erro de "cin":
      cin.clear();
      // e desprezar quebras de linha pendentes no buffer de "cin":
      cin.ignore(numeric_limits<int>::max(), '\n');

      valores_validos = false;
    }

    if (valores_validos) {
      inicial = char(toupper(inicial)); // se 'a' -> 'A'...
      final = char(toupper(final)); // se 'b' -> 'B'...

      if (razao < 0) {
        cout << "Razao deve ser maisor que zero.\n";
        valores_validos = false;
      }
      if (inicial < inicial_min) {
        cout << "Inicial deve ser maior ou igual a " << inicial_min << endl;
        valores_validos = false;
      }
      if (final > final_max) {
        cout << "Final deve ser menor ou igual a " << final_max << endl;
        valores_validos = false;
      }
      if (inicial > final) {
        cout << "Inicial deve ser menor ou igual a Final.\n";
        valores_validos = false;
      }
      if (razao > (final - inicial + 1)) {
        cout << "Razao nao pode ser maior que " << " (Final + Inicial + 1).\n";
        valores_validos = false;
      }
    }
    if (valores_validos) {
      unsigned int quant_num = (final - inicial + razao) / razao;
      vec.resize(quant_num);
      str.resize(quant_num);
      unsigned int index;
      char r = char(razao);

      for (index = 0; inicial <= final; inicial += r) {
        vec[index] = inicial; // char para int
        str[index] = inicial;
        index++;
      }

      int soma = 0;
      for (index = 0; index < vec.size(); index++) {
        soma += vec[index];
        cout << vec[index] << endl;
      }

      cout << "\nTotal de numeros no intervalo: " << quant_num << endl;
      cout << "Resultado da soma: " << soma << endl;
      cout << "String: " << str << endl;
      cout << "\ndeseja realizar novo calculo?\n" << "(o para encerrar, 1 para continuar)\n\n";
      cin >> continuar;


      if ( std::cin.fail() ) {
        std::cout << "entrada incorreta - entendida como " << "encerramento\n" ;
        continuar = false ; // o laço "while" será encerrado
      }
      std::cout << "\n";
    } else {
      std::cout << "Tente outra vez\n";
    }

  }
  cout << "fim do procesamento\n";
  return 0;
}