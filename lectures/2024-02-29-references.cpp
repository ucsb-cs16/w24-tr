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

void print(const Student& student) {
  // student.age += 3;
  std::cout
    << "Student " << student.name
    << " (age = " << student.age
    << "; gpa = " << student.gpa
    << ")\n";
}

void make_older(Student& student) {
  student.age += 1;
}

int main() {
  Student alice;
  alice.name = "Alice";
  alice.age  = 19;
  alice.gpa  = 3.70;

  Student bob;
  bob.name = "Bob";
  bob.age  = 17;
  bob.gpa  = 3.25;

  //            Pointer  Reference
  // Type       T*       T&
  // Get One    p = &x   r = x
  // Deref      *p       r
  // Nullable   Yes      No
  // Repoint    p = &y   NOPE
  // # of Objs  0-N      1
  // Get Member p->m     r.m

  Student* ptr;
  ptr = &alice;
  Student& ref = alice;

  // ptr = &bob;
  // ref = bob;

  // alice = bob;

  // print(alice);
  // print(bob);

  // print(*ptr);

  print(alice);
  make_older(alice);
  print(alice);

  return 0;
}
