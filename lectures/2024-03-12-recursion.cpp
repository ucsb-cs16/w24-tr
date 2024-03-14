#include <iostream>
#include <string>

size_t factorial(size_t n) {
  size_t result = 1;
  while(n > 1) {
    result *= n;
    n -= 1;
  }

  return result;
}

size_t recfac(size_t n) {
  if(n == 0) {
    return 1;
  }

  return n * recfac(n - 1);
}

size_t recstrlen(const char* str) {
  if(str[0] == '\0') {
    return 0;
  }

  return 1 + recstrlen(&str[1]);
}

size_t fib(size_t n) {
  if(n <= 1) {
    return n;
  }

  return fib(n - 1) + fib(n - 2);
}

void print_factorial(size_t n) {
  std::cout << n << "! = " << recfac(n) << '\n';
}

void print_strlen(const char* str) {
  std::cout << "strlen(\"" << str << "\") = " << recstrlen(str) << '\n';
}

void print_fib(size_t n) {
  std::cout << "fib(" << n << ") = " << fib(n) << '\n';
}

int main() {
  // print_factorial(0);
  // print_factorial(1);
  // print_factorial(3);
  // print_factorial(5);
  print_factorial(0xffff);

  // print_strlen("");
  // print_strlen("~");
  // print_strlen("Hello");
  // print_strlen("123456789012345678901234567890");

  // print_fib(0);
  // print_fib(1);
  // print_fib(2);
  // print_fib(3);
  // print_fib(4);
  // print_fib(5);
  // print_fib(6);
  // print_fib(7);
  // print_fib(8);

  return 0;
}
