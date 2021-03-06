#include <libalux/print>
#include <libalux/task>
#include <cassert>
#include "statics1.hpp"
#include "statics2.hpp"
#include "console.hpp"
#include "memory.hpp"
#include "thread.hpp"

using namespace libalux;

extern "C" {

void TestStaticInit();

int main() {
  PrintLine("Alux tester started, PID ", GetPid(), " UID ", GetUid());
  TestColors();
  TestStaticInit();
  TestAllocAndMap();
  TestVMRead();
  TestThreadId();
  TestLaunchThread();
  TestSleep();
  return 0;
}

void TestStaticInit() {
  Print("testing static variable initialization...");
  assert(CheckStaticIncrement1());
  assert(CheckStaticIncrement2());
  PrintLine(" passed!");
}

}