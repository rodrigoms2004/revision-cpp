#include <iostream>

using namespace std;

int main () {
  cout << "\n testEnum\n\n";

  enum:char { const_1, const_2};
  cout << "sizeof const_1 = " << sizeof(const_1) << endl;
  
  {
    cout << "\n -- enum with type but no scope\n";
    enum Week:short { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
    cout << "sizeof enum Week = " << sizeof(Week) << endl;
    int var = Sunday;
    cout << "var (=Sunday) = " << var << endl; // prints 0
  }
  {
    // from C++ 11 enum with type and scope, integer is default
    cout << "\n -- enum with type and scope\n";
    enum class Week:long { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
    cout << "sizeof enum Week = " << sizeof(Week) << endl;
    int var = int(Week::Sunday); // explicit conversion from Week to int
    cout << "var (=Week::Sunday) = " << var << endl; // prints 0
    int Sunday = 5; // "in Sunday" has not nothing to do with "Week::Sunday"
    cout << "int Sunday = " << Sunday << endl; // reference to "int Sunday": 5
  }

  cout << endl;
  return 0;
}

