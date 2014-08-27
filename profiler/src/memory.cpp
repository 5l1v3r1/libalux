#include <libalux/memory>
#include <libalux/print>
#include <libalux/time>
#include <cassert>

using namespace libalux;

void ProfileMemoryStats() {
  uint64_t start = GetBootNanoTime();
  
  for (int i = 0; i < 1000000; ++i) {
    int count = CountPageSizes();
    for (int j = 0; j < count; ++j) {
      GetPageSize(j);
      GetPageAlign(j);
    }
    GetVMCapabilities();
  }
  
  PrintLine("ProfileMemoryStats() - ", (GetBootNanoTime() - start), " nanos");
}

void ProfilePhysicalAllocation() {
  uint64_t start = GetBootNanoTime();
  for (int i = 0; i < 20000; ++i) {
    PhysAddr addr;
    bool res = AllocPhysical(addr, 0x1000, 0x1000);
    assert(res);
    FreePhysical(addr);
  }
  PrintLine("ProfilePhysicalAllocation() - ", (GetBootNanoTime() - start),
            " nanos");
}
