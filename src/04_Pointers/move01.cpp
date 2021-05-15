#include <iostream>
#include <vector>
#include <string>

using namespace std;

void push_back_default() {
  string str = "Ola mundo";
  vector<string> v;
  cout << "str antes push_back default: " << str << endl;
  v.push_back(str);
  cout << "str depois push_back default: " << str << endl; // "str" manteve o seu valor

  cout << "v[0]: " << v[0] << "\n\n\n"; // o valor de "str" foi copiado para "v[0]"
}

void push_back_move() {
  string str = "Ola mundo";
  vector<string> v;
  cout << "str antes push_back move: " << str << endl;
  v.push_back(move(str)); // chama o push_back que recebe um rvalue
  cout << "str depois push_back move: " << str << endl; // "str" foi movido; não manteve o seu valor (agora é nulo)

  cout << "v[0]: " << v[0] << "\n\n\n"; // "v[0]" agora contem o antigo valor se "str"
}

int main() {
  push_back_default();
  push_back_move();

  return 0;
}

/* 
  str antes push_back default: Ola mundo
  str depois push_back default: Ola mundo
  v[0]: Ola mundo

  str antes push_back move: Ola mundo
  str depois push_back move: 
  v[0]: Ola mundo
*/

