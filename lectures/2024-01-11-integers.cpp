#include <iostream>

// char   8-bit         -128  127
// short 16-bit signed  -32k  32k
// int   32-bit signed   -2b   2b

// long int  ???-bit signed
// long long int 64-bit siged

// unsigned int x = 8
// signed int y = -12

int main() {
  int a;
  a = 2;
  // std::cout << "a = " << a << "\n";

  a = 4;

  int b = 2;
  int sum = a + b;

  a = 123;

  // std::cout << "Hello!";
  // std::cout << "a = " << a << "\n";
  // std::cout << "b = " << b << "\n";
  // std::cout << "sum = " << sum << "\n";

  int i = 0x80000000;
  int j = 0x7fffffff;
  std::cout << "sizeof(i) = " << sizeof(i) << "\n";
  std::cout << "i = " << i << "\n";
  std::cout << "j = " << j << "\n";
  return 0;
}

