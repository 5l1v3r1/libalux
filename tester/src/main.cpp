#include <libalux/print>
#include <libalux/task>
#include <cassert>
#include "statics1.hpp"
#include "statics2.hpp"

using namespace libalux;

extern "C" {

int main() {
  PrintLine("Alux tester started, PID ", GetPid());
  assert(CheckStaticIncrement1());
  assert(CheckStaticIncrement2());
  return 0;
}

}