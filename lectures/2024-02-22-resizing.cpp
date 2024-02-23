#include <iostream>
#include <string>

void print_strings(std::string* strings, size_t n) {
  for(int i = 0; i < n; ++i) {
    std::cout << strings[i] << '\n';
  }
}

std::string* read_strings(size_t* nstrings) {
  // Start with storage space for two strings:
  std::string* data = new std::string[2];
  size_t capacity = 2;
  size_t count    = 0;

  while(true) {
    std::string line;
    std::cout << "str> ";
    if(!std::getline(std::cin, line)) {
      // No more strings to read.
      *nstrings = count;
      return data;
    }

    if(count == capacity) {
      // Out of space?  Double your storage!
      std::cout << "Resizing: " << count*2 << '\n';
      std::string* temp = new std::string[2*count];
      for(size_t i = 0; i < count; ++i) {
        temp[i] = data[i];
      }

      capacity *= 2;
      delete [] data;
      data = temp;
    }

    // Store another string...
    data[count] = line;
    count += 1;
  }
}

int main() {
  size_t nstrings;
  std::string* strings = read_strings(&nstrings);

  std::cout << '\n';
  print_strings(strings, nstrings);

  delete [] strings;
  return 0;
}
