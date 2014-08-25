#ifndef __LIBALUX_PRINTF_HPP__
#define __LIBALUX_PRINTF_HPP__

#include <libalux/console>

namespace libalux {

void PrintArg(const char * arg);
void PrintArg(char c);
void PrintArg(unsigned short s);
void PrintArg(unsigned int i);
void PrintArg(unsigned long l);
void PrintArg(unsigned long long number);

void Print();

template <typename T, typename... Args>
void Print(T arg, Args... args) {
  PrintArg(arg);
  Print(args...);
}

void PrintLine();

template <typename T, typename... Args>
void PrintLine(T arg, Args... args) {
  PrintArg(arg);
  PrintLine(args...);
}

}

#endif
