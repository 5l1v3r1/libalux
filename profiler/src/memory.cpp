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

void ProfileVirtualMap() {
  size_t pageSize = GetPageSize(0);
  size_t pageAlign = GetPageAlign(0) ?: 1;
  assert(pageSize > 0);
  
  PhysAddr physical;
  VMSize size(pageSize, 1);
  bool status = AllocPhysical(physical, pageSize, pageAlign);
  assert(status);
  
  VirtAddr mapped;
  VMAttributes attributes;
  
  uint64_t start = GetBootNanoTime();
  for (int i = 0; i < 10000; ++i) {
    status = VMMap(mapped, physical, size, attributes);
    assert(status);
    
    // attempt to set it to verify it was mapped
    *(char *)mapped = 0x7f;

    VMUnmap(mapped, size);
  }
  uint64_t end = GetBootNanoTime();
  
  FreePhysical(physical);
  
  PrintLine("ProfileVirtualMap() - ", (end - start), " nanos");
}

void ProfileVirtualReserve() {
  size_t pageSize = GetPageSize(0);
  assert(pageSize > 0);
  VMSize size(pageSize, 1);
  
  VirtAddr reserved;
  
  uint64_t start = GetBootNanoTime();
  for (int i = 0; i < 100000; ++i) {
    bool status = VMReserve(reserved, size);
    assert(status);
    VMUnreserve(reserved, size);
  }
  uint64_t end = GetBootNanoTime();
  
  PrintLine("ProfileVirtualReserve() - ", (end - start), " nanos");
}

void ProfileSecondVirtualMap() {
  size_t pageSize = GetPageSize(0);
  size_t pageAlign = GetPageAlign(0) ?: 1;
  assert(pageSize > 0);
  
  PhysAddr physical;
  VMSize size(pageSize, 1);
  bool status = AllocPhysical(physical, pageSize * 2, pageAlign);
  assert(status);
  VirtAddr mapped;
  VirtAddr firstMapped;
  VMAttributes attributes;
  
  status = VMMap(firstMapped, physical, size, attributes);
  assert(status);
  
  uint64_t start = GetBootNanoTime();
  for (int i = 0; i < 10000; ++i) {
    status = VMMap(mapped, physical + pageSize, size, attributes);
    assert(status);
    
    // attempt to set it to verify it was mapped
    *(char *)mapped = 0x7f;

    VMUnmap(mapped, size);
  }
  uint64_t end = GetBootNanoTime();
  
  VMUnmap(firstMapped, size);
  FreePhysical(physical);
  PrintLine("ProfileSecondVirtualMap() - ", (end - start), " nanos");
}
