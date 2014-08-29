#include <libalux/print>
#include <libalux/task>
#include "memory.hpp"

using namespace libalux;

extern "C" {

int main() {
  PrintLine("Alux profiler started, PID ", GetPid());
  ProfileMemoryStats();
  ProfilePhysicalAllocation();
  ProfileVirtualMap();
  ProfileVirtualReserve();
  ProfileSecondVirtualMap();
  ProfileVirtualRead();
  ProfilePlacementMapUnmap();
  return 0;
}

}