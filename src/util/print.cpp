#include "print.hpp"

namespace libalux {

void Print() {
  
}

void PrintLine() {
  PrintConsole("\n");
}

void PrintArg(const char * arg) {
  PrintConsole(arg);
}

void PrintArg(char c) {
  char myChars[2] = {c, 0};
  PrintConsole(myChars);
}

void PrintArg(unsigned short s) {
  PrintArg((unsigned long long)s);
}

void PrintArg(unsigned int i) {
  PrintArg((unsigned long long)i);
}

void PrintArg(unsigned long l) {
  PrintArg((unsigned long long)l);
}

void PrintArg(unsigned long long number) {
  const char * chars = "0123456789abcdef";
  unsigned char _buf[32] = {0};
  _buf[0] = '0';
  _buf[1] = 'x';
  unsigned char * buf = _buf + 2;
  unsigned char len = 2, i;
  do {
    unsigned char nextDig = (unsigned char)(number & 0xf);
    buf[len++] = chars[nextDig];
    number >>= 4;
  } while (number > 0);
  for (i = 0; i < len / 2; i++) {
    unsigned char a = buf[len - i - 1];
    buf[len - i - 1] = buf[i];
    buf[i] = a;
  }
  PrintConsole((const char *)_buf);
}

}