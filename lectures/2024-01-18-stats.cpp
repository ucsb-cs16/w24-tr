#include <iostream>

int main() {
  // will be used as accumulators
  int total = 0;
  int count = 0;

  while(true) {
    std::cout << "Enter a number (0 to stop): ";

    int number;
    std::cin >> number;

    if(number == 0) {
      break;
    }

    total += number;
    count += 1;
  }

  float mean = float(total) / count;

  std::cout << "Count: " << count << '\n';
  std::cout << "Mean:  " << mean  << '\n';
  std::cout << "Total: " << total << '\n';
  return 0;
}
