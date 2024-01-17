#include <iostream>
#include <string>

// using namespace std;


int main() {
  int a = 4;
  int b = 4;

  if(a < b) {
    std::cout << "a < b\n";
  }
  else if(a > b) {
    std::cout << "a > b\n";
  }
  else {
    std::cout << "a == b\n";
  }


  int x = 10;
  while(x > 0) {
    if(x == 8) {
      x -= 2;
      // Skip back to the beginningof the loop
      continue;
    }

    std::cout << x << "...\n";
    // x = x - 1;

    if(x == 4) {
      // Skip to the end of the loop
      break;
    }

    --x;
    x--;
  }

  std::cout << "x = " << x << '\n';
  std::cout << "Done!\n";

  // int z = 5; // init
  // while(z > 0) { // cond
  //   std::cout << "z = " << z << '\n';
  //   z -= 1; // inc
  // }

  // if(true) {
  //   // k only exists within these curly braces
  //   int k = 42;
  // }
  // else {
  //   // ERROR: unknown variable k
  //   std::cout << k << '\n';
  // }

  for(int z = 5; z > 0; --z) {
    std::cout << "z = ";
    std::cout << z << '\n';
  }

  // ERROR: unknown variable z
  // Declare d before the loop to fix this
  // std::cout << "Final z = " << z << '\n';

  return 0;
}
