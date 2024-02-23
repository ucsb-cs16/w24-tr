#include <iostream>
#include <string>

// A custom type that can hold a pointer AND
// the size of the arrai it points to.
struct StringArray {
  std::string* strings;
  size_t       count;
};

void print_strings(const StringArray* sarray) {
  for(size_t i = 0; i < sarray->count; ++i) {
    // Note: -> instead of . 'cause sarray is a pointer.
    std::cout << sarray->strings[i] << '\n';
  }
}

// We can now return the data and its length together.
StringArray read_strings() {
  std::string* data = new std::string[2];
  size_t capacity = 2;
  size_t count    = 0;

  while(true) {
    std::string line;
    std::cout << "str> ";
    if(!std::getline(std::cin, line)) {
      StringArray sarray;
      sarray.strings = data;
      sarray.count   = count;
      return sarray;
    }

    if(count == capacity) {
      std::cout << "Resizing: " << count*2 << '\n';
      std::string* temp = new std::string[2*count];
      for(size_t i = 0; i < count; ++i) {
        temp[i] = data[i];
      }

      capacity *= 2;
      delete [] data;
      data = temp;
    }

    data[count] = line;
    count += 1;
  }
}

int main() {
  // Store the result in a variable of our new type.
  StringArray sarray = read_strings();

  std::cout << '\n';
  print_strings(&sarray);

  delete [] sarray.strings;
  return 0;
}
