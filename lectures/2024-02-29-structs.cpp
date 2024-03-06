#include <iostream>
#include <string>

struct Student {
  std::string  name;
  unsigned int age;
  float        gpa;
};

void print(int i) {
  std::cout << i << '\n';
}

void print(Student student) {
  std::cout
    << "Student " << student.name
    << " (age = " << student.age
    << "; gpa = " << student.gpa
    << ")\n";
}

void make_older(Student* student) {
  std::cout << student << '\n';
  student->age += 1;
  std::cout << student << '\n';
  std::cout << &student->name << '\n';
  std::cout << &student->age  << '\n';
  std::cout << &student->gpa  << '\n';
}

int main() {
  Student alice;
  alice.name = "Alice";
  alice.age  = 19;
  alice.gpa  = 3.70;

  int x = 12;
  int y = 42;

  print(alice);
  make_older(&alice);
  print(alice);

  return 0;
}
