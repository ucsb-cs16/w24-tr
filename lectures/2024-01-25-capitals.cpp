#include <iostream>
#include <string>

bool is_letter(char c) {
  if(c >= 'a' && c <= 'z') {
    return true;
  }

  if(c >= 'A' && c <= 'Z') {
    return true;
  }

  return false;
}

char capitalize(char c) {
  if(is_letter(c)) {
    return c & ~(1 << 5);
    // return c | (1 << 5);
    // return c ^ (1 << 5);
  }

  return c;
}

std::string capitalize(std::string str) {
  for(int i = 0; i < str.length(); i += 1) {
    str[i] = capitalize(str[i]);
  }

  return str;
}

int main() {

  while(true) {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    if(str == "") {
      break;
    }

    str = capitalize(str);
    std::cout << "> " << str << '\n';
  }

  return 0;
}
