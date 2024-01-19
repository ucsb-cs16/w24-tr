#include <cmath>
#include <iostream>

//  &&  and
//  ||  or

int main() {
  int number;

  std::cout << "Enter an integer: ";
  std::cin >> number;

  if(number < 2 || number % 2 == 0) {
    std::cout << "Not prime.\n";
    return 0;
  }

  int limit = sqrt(number);
  for(int factor = 3; factor <= limit; factor += 2) {
    if(number % factor == 0) {
      std::cout << "Not prime.\n";
      return 0;
    }
  }

  std::cout << "Prime!\n";
  return 0;
}
