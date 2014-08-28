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

struct VMAttributes {
  bool executable = true;
  bool writable = true;
  bool cachable = true;
  
  VMAttributes(int value)
    : executable((value & 1) != 0), writable((value & 2) != 0),
      cachable((value & 4) != 0) {}
  
  operator int() const {
    return (executable ? 1 : 0) | (writable ? 2 : 0) | (cachable ? 4 : 0);
  }
};

struct VMSize {
  size_t pageSize;
  size_t pageCount;
};

int CountPageSizes();
size_t GetPageSize(int idx);
size_t GetPageAlign(int idx);
VMCapabilities GetVMCapabilities();

bool AllocPhysical(PhysAddr &, PhysSize size, PhysSize align);
bool FreePhysical(PhysAddr);

bool VMRead(PhysAddr *, VMAttributes *, size_t *, VirtAddr);
bool VMMap(VirtAddr &, PhysAddr, VMSize, const VMAttributes &);
bool VMMapAt(VirtAddr, PhysAddr, VMSize, const VMAttributes &);
bool VMUnmap(VirtAddr, VMSize);
bool VMUnmapAndReserve(VirtAddr, VMSize);
bool VMReserve(VirtAddr &, VMSize);
bool VMReserveAt(VirtAddr, VMSize);
bool VMUnreserve(VirtAddr, VMSize);
bool VMRereserve(VirtAddr, VMSize, size_t);

}

#endif
