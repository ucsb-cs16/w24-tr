#include "xps.h"

#include <iomanip>
#include <iostream>
#include <string>

// Implementation if the XPS input/output functions.
// You can edit this file, but you shouldn't need to.
// Gradescope will use the original version.


void xps_debug(const char* str) {
  // Save the original configuration of std::cout:
  // https://stackoverflow.com/questions/2273330
  std::ios old_state(nullptr);
  old_state.copyfmt(std::cout);

  // Reconfigure std::cout to print zero-filled hex:
  std::cout << std::hex << std::setfill('0');

  while(true) {
    unsigned char len = *str;
    std::cout << std::setw(2) << size_t(str[0]);

    if(len > 15) {
      // Error case for invalid block lengths.
      std::cout << "\n!!\n";
      break;
    }

    for(size_t i = 1; i <= len; ++i) {
      std::cout << ' ' << std::setw(2) << size_t(str[i]);
    }

    std::cout << "\n##";

    for(size_t i = 1; i <= len; ++i) {
      if(str[i] == '\0') {
        std::cout << " \\0";
      }
      else if(str[i] == '\t') {
        std::cout << " \\t";
      }
      else if(str[i] == '\n') {
        std::cout << " \\n";
      }
      else if(str[i] == '\r') {
        std::cout << " \\r";
      }
      else if(str[i] < ' ' || str[i] > '~') {
        std::cout << " ??";
      }
      else {
        std::cout << ' ' << str[i] << ' ';
      }
    }

    std::cout << '\n';

    if(len != 15) {
      break;
    }
    else {
      str += 16;
    }
  }

  // Restore std::cout to its original state:
  std::cout.copyfmt(old_state);
}

char* xps_readline() {
  std::string line;

  if(!std::getline(std::cin, line)) {
    return nullptr;
  }

  size_t len = line.length();
  char*  xps = new char[len + len / 15 + 1];

  size_t dst = 0;
  for(size_t src = 0; src < len; ++src) {
    if(src % 15 == 0) {
      xps[dst] = 15;
      dst += 1;
    }

    xps[dst] = line[src];
    dst += 1;
  }

  xps[16 * (len / 15)] = len % 15;
  return xps;
}

void xps_write(const char* str) {
  while(true) {
    unsigned char len = *str;
    std::cout.write(str + 1, len);

    if(len != 15) {
      break;
    }
    else {
      str += 16;
    }
  }
}

void xps_writeline(const char* str) {
  xps_write(str);
  std::cout << '\n';
}
