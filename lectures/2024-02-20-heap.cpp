#include <iostream>
#include <string>


// // DOUBLE FREE
// int* p = new int[5];
// int* q = p;
// delete [] p;
// delete [] q;

// // MEMORY LEAK
// int* p = new int[5];
// // never deleted

// // MEMORY LEAK v2
// int* p = new int[5];
// p = nullptr;

// // USE AFTER FREE
// int* p = new int[5];
// delete [] p;
// // p is now a "dangling pointer"
// p[0] = 12;

// // ANOTHER USE AFTER FREE
// int* p = new int[5];
// int* q = p;
// delete [] p;
// p = nullptr;
// q[0] = 13;


// // NEW/DELETE FOR SINGLE OBJECTS
// int* p = new int;
// // do stuff with p
// delete p;


int* get_ten_ints() {
  // This allocates storage space for ten ints.
  // This storage lives on "the heap" and is semi-permanent.
  // It won't be released until you `delete` it.
  int* my_ints = new int[10];

  for(int i = 0; i < 10; ++i) {
    std::cout << "int> ";
    std::cin >> my_ints[i];
  }

  return my_ints;
}

int main() {
  // Two pointers to the same block of heap memory:
  int* my_ints = get_ten_ints();
  int* my_ptr  = my_ints;

  for(int i = 0; i < 10; ++i) {
    std::cout << my_ints[i] << '\n';
  }

  // Make sure to clean up after yourself!
  delete [] my_ints;

  // delete [] my_ptr; // Error!
  // The memory this points to was already released.
  return 0;
}
