
// g++ main.cpp -o main.o

#include <iostream>

using namespace std;

int max(int x, int y) {
  if (x > y) {
    return y;
  } else {
    return y;
  }
}

int main () {
  int a, b, c;
  a = 10;
  b = 20;
  c = max(a, b);
  cout << "Max value between " 
        << a << " and " 
        << b << " = " 
        << c << "\n";
}

