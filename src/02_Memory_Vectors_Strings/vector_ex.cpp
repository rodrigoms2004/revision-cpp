#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "Using std::vector" << endl;
  vector<int> v1;
  v1.resize(5);
  size_t v1_size = v1.size();
  for(size_t index = 0; index < v1_size; ++index) {
    v1[index] = 1001 + int (index);
    cout << v1[index] << ", ";
  }
  cout << endl;

  cout << "Using C Style" << endl;
  const size_t v2_size = 5;
  int v2[v2_size];
  for (size_t index = 0; index < v2_size; ++index) {
    v2[index] = 2001 + int(index);
    cout << v2[index] << ", ";
  }
  cout << endl;

  cout << "Two types using if" << endl;
  int x = 10;
  if (x < v1.size()) 
    v1[x] = 30;
  else 
    cout << "try to access non-allocated element in v1\n";

  if (x < v2_size)
    v2[x] = 30;
  else
    cout << "try to access non-allocated element in v2\n";
    
  return 0;
}