#include <iostream>
#include <string>

// using namespace std;


int main() {
  int  a = 400;
  char b = a;
  int  c = b;

  float  f = 1.234;
  double g = 42.0009;

  std::string s = "Hello";

  bool z = a >= b;

  std::cout << "c = " << c << "\n";
  std::cout << "z = " << z << "\n";
  return 0;
}
