#include <iostream>
#include <string>

int* get_ten_ints() {
  int my_ints[10];

  for(int i = 0; i < 10; ++i) {
    std::cout << "int> ";
    std::cin >> my_ints[i];
  }

  return my_ints;
}

int main() {
  int* my_ints = get_ten_ints();

  // // This would work if it were in main():
  // int my_ints[10];
  // for(int i = 0; i < 10; ++i) {
  //   std::cout << "int> ";
  //   std::cin >> my_ints[i];
  // }

  for(int i = 0; i < 10; ++i) {
    std::cout << my_ints[i] << '\n';
  }
}
