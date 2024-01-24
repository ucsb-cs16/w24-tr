#include <iostream>

void print_bits(unsigned int number);


int main() {
  unsigned int x = 0xf0f0;
  unsigned int y = 0xff00;

  std::cout << "     x = ";
  print_bits(x);

  std::cout << "     y = ";
  print_bits(y);

  std::cout << "    ~x = ";
  print_bits(~x);

  std::cout << " x & y = ";
  print_bits(x & y);

  std::cout << " x | y = ";
  print_bits(x | y);

  std::cout << " x ^ y = ";
  print_bits(x ^ y);

  std::cout << "x << 3 = ";
  print_bits(x << 3);

  std::cout << "x >> 3 = ";
  print_bits(x >> 3);

  unsigned int z = 0xf0f00000;
  int w = 0xf0f00000;
  int v = 0x70f00000;

  std::cout << '\n';

  // unsigned: zero-extended
  std::cout << "z >> 3 = ";
  print_bits(z >> 3);

  // signed: sign-extended
  std::cout << "w >> 3 = ";
  print_bits(w >> 3);

  // signed: sign-extended
  std::cout << "v >> 3 = ";
  print_bits(v >> 3);

  return 0;
}


void print_bits(unsigned int number) {
  for(int bit = 31; bit >= 0; --bit) {
    unsigned int mask = 1 << bit;
    if((number & mask) == 0) {
      std::cout << '0';
    }
    else {
      std::cout << '1';
    }
  }

  std::cout << '\n';
}
