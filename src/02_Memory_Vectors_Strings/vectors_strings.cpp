#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // === a.string():
  cout << "===a.testing string\n";
  string name;
  name = "Suely";
  cout << name << "\n"; 
  name = name + " Silveira";
  cout << name << "\n"; 

  // === b.vector:
  cout << "===a.testing vector\n";
  const size_t trimester_year = 4;
  vector<double> sales_trimester;
  sales_trimester.resize(trimester_year); // vector for 4 elements

  cout << "Inform total sales for each trimester:\n";
  size_t index;
  for (index = 0; index < trimester_year; index++) {
    cout << "Inform trimester" << index + 1 << "\n";
    cin >> sales_trimester[index];
  }
  cout << "\nInformed values:\n";
  double total_year = 0;
  for (index = 0; index < trimester_year; index++) {
    cout << sales_trimester[index] << endl;
    total_year = total_year + sales_trimester[index];
  }

  cout << "\nTotal sales in the year: " << total_year << endl;
  return 0;
}