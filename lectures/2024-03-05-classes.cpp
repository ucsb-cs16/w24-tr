#include <iostream>
#include <string>

class StringArray {
// In a `class`, members are private by default.
  std::string* strings;
  size_t       count;
  size_t       capacity;

// We can use the `public:` statement to make members accessible:
public:
  StringArray() {
    // Default constructor makes an empty array.
    strings  = new std::string[2];
    capacity = 2;
    count    = 0;
  }

  StringArray(const StringArray& other) {
    // Copy constructor copies some other array.
    count    = other.count;
    capacity = other.capacity;
    strings  = new std::string[capacity];
    for(size_t i = 0; i < count; ++i) {
      strings[i] = other.strings[i];
    }
  }

  StringArray(std::string* strings, size_t count) {
    // Custom constructor for your programming convenience.
    this->strings  = strings;
    this->count    = count;
    this->capacity = count;
  }

  ~StringArray() {
    // Destructor cleans up heap memory.
    delete [] strings;
  }

  void add(const std::string& str) {
    if(count == capacity) {
      std::cout << "Resizing: " << count*2 << '\n';
      std::string* temp = new std::string[2*count];
      for(size_t i = 0; i < count; ++i) {
        temp[i] = strings[i];
      }

      capacity *= 2;
      delete [] strings;
      strings = temp;
    }

    strings[count] = str;
    count += 1;
  }

  std::string* getStrings() const {
    return this->strings;
  }

  size_t getCount() const {
    return this->count;
  }

  void print() const {
    for(size_t i = 0; i < count; ++i) {
      std::cout << strings[i] << '\n';
    }
  }
};

StringArray read_strings() {
  StringArray array;

  while(true) {
    std::string line;
    std::cout << "str> ";
    if(!std::getline(std::cin, line) || line == "") {
      return array;
    }

    array.add(line);
  }
}

int main() {
  std::cout << "Reading string array 1:\n";
  StringArray sarray1 = read_strings();

  std::cout << "Reading string array 2:\n";
  StringArray sarray2 = read_strings();

  // You can allocate classes on the heap if you want:
  // StringArray* sarray3 = new StringArray();

  std::cout << '\n';

  // The `this` pointer will point to the StringArray to the left of the dot:
  std::cout << "String array 1 (" << sarray1.getCount() << " strings):\n";
  sarray1.print();

  std::cout << "String array 2 (" << sarray2.getCount() << " strings):\n";
  sarray2.print();

  return 0;
}
