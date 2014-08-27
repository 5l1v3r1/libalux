#ifndef __LIBALUX_X64_SYSCALL__
#define __LIBALUX_X64_SYSCALL__

#include <libalux/types>
#include <cstdint>
#include <cstddef>

namespace libalux {

namespace x64 {

class Syscall {
public:
  union RetVal {
    bool boolean;
    int integer;
    uint32_t integer32;
    uint64_t integer64;
    PhysAddr phys;
    VirtAddr virt;
    PhysSize pSize;
    size_t vSize;
  };
  
  static_assert(sizeof(RetVal) == 8, "invalid RetVal size");
  
  Syscall(uint16_t number);
  
  void PushBool(bool);
  void PushInt(int);
  void PushUInt32(uint32_t);
  void PushUInt64(uint64_t);
  void PushPhysAddr(PhysAddr);
  void PushVirtAddr(VirtAddr);
  void PushPhysSize(PhysSize);
  void PushVirtSize(size_t);
  
  RetVal Run();
  
private:
  uint64_t arguments[5];
  int idx = 0;
  uint16_t number;
};

}

using x64::Syscall;

}

#endif
