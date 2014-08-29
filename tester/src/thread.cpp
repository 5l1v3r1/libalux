#include <libalux/thread>
#include <libalux/time>
#include <libalux/print>
#include <cassert>

using namespace libalux;

namespace {

typedef void (* ThreadFunc)(void *);

ThreadFunc BasicThreadFunction() {
#ifdef __LIBALUX_TARGET_X64__
  ThreadFunc result;
  __asm__("movabsq $_end_test_basic_launch_function, %%rax\n"
          "jmp *%%rax\n"
          "_test_basic_launch_function:\n"
          // set 1 in the char* passed to our function
          "movb $1, (%%rdi)\n"
          // exit syscall
          "mov $20, %%rdi\n"
          "syscall\n"
          "_end_test_basic_launch_function:\n"
          "movabsq $_test_basic_launch_function, %0"
          : "=d" (result) : : "rax");
  return result;
#endif
}

}

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

void TestLaunchThread() {
  Print("testing LaunchThread()...");
  volatile char value = 0;
  LaunchThread(BasicThreadFunction(), (void *)&value);
  while (!value) {}
  PrintLine(" passed!");
}
