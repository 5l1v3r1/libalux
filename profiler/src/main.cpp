#include <libalux/print>
#include <libalux/task>

using namespace libalux;

extern "C" {

int main() {
  PrintLine("Alux profiler started, PID ", GetPid());
  return 0;
}

}