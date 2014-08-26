#ifndef __LIBALUX_MEMORY_HPP__
#define __LIBALUX_MEMORY_HPP__

#include <libalux/types>
#include <cstddef>

namespace libalux {

struct VMCapabilities {
  bool placementReserve;
  bool placementMap;
  bool executableFlag;
  bool writableFlag;
  bool cachableFlag;
};

int CountPageSizes();
size_t GetPageSize(int idx);
size_t GetPageAlign(int idx);
VMCapabilities GetVMCapabilities();

bool AllocPhysical(PhysAddr &, PhysSize size, PhysSize align);
void FreePhysical(PhysAddr);

}

#endif
