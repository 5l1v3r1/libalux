#include <libalux/memory>
#include <libalux/print>
#include <cassert>

using namespace libalux;

void TestAllocAndMap() {
  Print("testing VMAllocPhysical() and VMMap()...");
  PhysAddr physical;
  VMSize size(GetPageSize(0), 1);
  assert(size.pageSize > 0);
  bool status = AllocPhysical(physical, size.pageSize, GetPageAlign(0) ?: 1);
  assert(status);
  
  VirtAddr mapped = 0;
  VMAttributes attributes;
  status = VMMap(mapped, physical, size, attributes);
  assert(status);
  assert(mapped != 0);
  
  char * ptr = (char *)mapped;
  for (size_t i = 0; i < size.pageSize; ++i) {
    ptr[i] = (char)i;
    assert(ptr[i] == (char)i);
  }
  PrintLine(" passed!");
  
  Print("testing VMUnmap() and FreePhysical()...");
  VMUnmap(mapped, size);
  FreePhysical(physical);
  PrintLine(" passed!");
}