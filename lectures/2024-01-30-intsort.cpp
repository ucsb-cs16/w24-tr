#include <iostream>
#include <string>

void sort(int* array, int length) {
  for(int i = 0; i < length; ++i) {
    for(int j = i + 1; j < length; ++j) {
      if(array[j] < array[i]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

int main() {
  int myints[100];

  // int data[4][3];

  int index = 0;
  int myint;

  std::cout << "int> ";
  while(std::cin >> myint) {
    myints[index] = myint;
    index += 1;

    std::cout << "int> ";
  }

  sort(myints, index);

  for(int i = 0; i < index; ++i) {
    std::cout << "myints[" << i << "] = " << myints[i] << '\n';
  }

  return 0;
}
