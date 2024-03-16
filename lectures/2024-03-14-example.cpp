#include <cstring>
#include <iostream>
#include <string>

void copy_cstr(char* dst, const char* src, size_t len) {
  for(size_t i = 0; i <= len; ++i) {
      dst[i] = src[i];
    }
}

class Thing {
  char*  mData;
  char*  mBackup;
  size_t mCount;

public:
  Thing(const char* str) {
    mCount  = strlen(str);
    mData   = new char[mCount + 1];
    mBackup = nullptr;

    copy_cstr(mData, str, mCount);
  }

  Thing(const Thing& other) {
    mCount  = other.mCount;
    mData   = new char[mCount + 1];
    mBackup = nullptr;

    copy_cstr(mData, other.mData, mCount);
  }

  ~Thing() {
    delete [] mData;
    delete [] mBackup;
  }

  void backup() {
    if(mBackup == nullptr) {
      mBackup = new char[mCount + 1];
    }

    copy_cstr(mBackup, mData, mCount);
  }

  void restore() {
    copy_cstr(mData, mBackup, mCount);
  }

  size_t count() const {
    return mCount;
  }

  char* data() {
    return mData;
  }

  char get(size_t i) const {
    return mData[i];
  }

  void set(size_t i, char c) {
    mData[i] = c;
  }
};

void print_thing(Thing thing) {
  std::cout << thing.data() << '\n';
}

int main() {
  Thing  thing1("Hello!");
  Thing* thing2 = new Thing("Goodbye.");

  thing1.backup();
  thing1.set(5, '?');
  print_thing(thing1);

  thing1.restore();
  print_thing(thing1);
  return 0;
}
