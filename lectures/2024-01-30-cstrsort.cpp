#include <iostream>
#include <string>

bool less_than(char* lhs, char* rhs) {
  int i = 0;
  while(lhs[i] != '\0' && rhs[i] != '\0') {
    if(lhs[i] != rhs[i]) {
      return lhs[i] < rhs[i];
    }

    i += 1;
  }

  return lhs[i] < rhs[i];
}

void sort(char** array, int length) {
  for(int i = 0; i < length; ++i) {
    for(int j = i + 1; j < length; ++j) {
      if(less_than(array[j], array[i])) {
        char* temp = array[i];
        array[i]   = array[j];
        array[j]   = temp;
      }
    }
  }
}

// argc: argument count
// argv: argument values (as C strings)
int main(int argc, char** argv) {
  // for(int i = 0; i < argc; i += 1) {
  //   char* cstring = argv[i];
  //   std::cout << cstring << '\n';
  // }

  // const char* cstring = "abcdef";
  // // c string: {'a', 'b', 'c', 'd', 'e', 'f', '\0'}

  // for(int i = 0; i < 7; i += 1) {
  //   int ascii = cstring[i];
  //   std::cout << ascii << '\n';
  // }

  sort(argv, argc);
  for(int i = 0; i < argc; ++i) {
    std::cout << argv[i] << '\n';
  }

  return 0;
}
