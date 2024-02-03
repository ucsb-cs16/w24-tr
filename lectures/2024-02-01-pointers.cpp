#include <iostream>
#include <string>

// No effect!  This changes the local variable i,
// but not whatever it's pointing at.
void inc1(int* i) {
  i = i + 1;
}

// This changes the thing i is pointing at.
void inc2(int* i) {
  *i = *i + 1;
}

// Make sure you pass a length, so you know how big the array is!
// And use const if you're not going to modify the pointer's target.
void print_array(const int* data, size_t length) {
  if(data == nullptr) {
    std::cout << "nullptr\n";
    return;
  }

  for(size_t i = 0; i < length; ++i) {
    std::cout << data[i] << ' ';
  }

  std::cout << '\n';
}

int main() {
  int array[4] = {0, 10, 20, 40};
  print_array(array, 4);

  int* p = array; // Arrays auto-convert to pointers
  // p += 1; // You can technically do math with pointers

  std::cout << "p = " << p << '\n';
  std::cout << "a = " << array << '\n';

  print_array(a, 4); // These two calls...
  print_array(p, 4); // ...are identical.

  int a = 1234;
  int b = 5678;
  inc2(&a); // Use the & prefix to get the address of a non-array variable

  inc2(&array[1]); // This is cleaner
  inc2(array + 2); // But this works too

  std::cout << "a = " << a << '\n';
  std::cout << "b = " << b << '\n';
  print_array(array, 4);

  int* q = &a;
  std::cout << "*q = " << *q << '\n'; // Get the varget of a non-array pointer with the * prefix

  // If we didn;t have a null check in print_array()
  // this would crash (with a segmentation fault)
  int* r = nullptr;
  print_array(r, 4);

  return 0;
}
