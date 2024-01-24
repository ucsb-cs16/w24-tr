#include <iomanip>
#include <iostream>

#include <cinttypes>

// returntype funcname(argtype argname...) {
//   // code
// }

void print_money(uint64_t cents) {
  std::cout << '$';
  std::cout << cents / 100;
  std::cout << '.';
  std::cout << std::setw(2) << std::setfill('0');
  std::cout << cents % 100;
  return;
}

int main() {
// ask for budget / total money
  uint64_t budget;
  std::cout << "Enter budget: ";
  std::cin >> budget;

// ask for item price
  uint64_t price;
  std::cout << "Enter price: ";
  std::cin >> price;

  if(budget >= price) {
    std::cout << "You can afford it!\n";
    std::cout << "You'll have ";
    print_money(budget - price);
    std::cout << " left over.\n";
  }
  else {
    std::cout << "You can't afford it.\n";
    std::cout << "You'll need ";
    print_money(price - budget);
    std::cout << " more.\n";
  }

  return 0;
}
