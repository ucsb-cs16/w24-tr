#include <cstdlib>
#include <iostream>

int main() {
  srand(time(0));
  int target = rand() % 20 + 1;

  while(true) {
    std::cout << "Enter a number: ";

    int number;
    std::cin >> number;

    if(number > target) {
      std::cout << "Too big.\n";
    }
    else if(number < target) {
      std::cout << "Too small.\n";
    }
    else {
      std::cout << "Got it!\n";
      return 0;
    }
  }
}
