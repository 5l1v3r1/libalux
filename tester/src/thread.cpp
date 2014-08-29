#include <libalux/thread>
#include <libalux/time>
#include <libalux/print>
#include <cassert>

using namespace libalux;

void TestThreadId() {
  Print("testing GetThreadId()...");
  assert(GetThreadId() == 0);
  PrintLine(" passed!");
}

void TestSleep() {
  Print("testing Sleep()...");
  uint64_t start = GetBootNanoTime();
  Sleep(1000000000);
  uint64_t diff = GetBootNanoTime() - start;
  
  // ensure that it was more than 0.5 seconds and less than 1.5 seconds
  assert(diff > 500000000 && diff < 1500000000);
  PrintLine(" passed!");
}
