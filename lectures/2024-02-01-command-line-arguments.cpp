#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::string mode;
  int key;

  // // DOES NOT WORK
  // std::cin >> mode;
  // std::cin >> key;

  if(argc != 3) {
    std::cout << "USAGE!\n";
    return 1;
  }

  mode = argv[1];
  key  = std::atoi(argv[2]);

  std::cout << mode << "\n";
  std::cout << key  << "\n";
  return 0;
}

