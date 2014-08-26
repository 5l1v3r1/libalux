#include "memory.hpp"
#include "syscalls.hpp"
#include <libalux/arch/syscall>

namespace libalux {

int CountPageSizes() {
  return Syscall(CountPageSizesSyscall).Run().integer;
}

size_t GetPageSize(int idx) {
  Syscall call(GetPageSizeSyscall);
  call.PushInt(idx);
  return call.Run().vSize;
}

size_t GetPageAlign(int idx) {
  Syscall call(GetPageAlignSyscall);
  call.PushInt(idx);
  return call.Run().vSize;
}

VMCapabilities GetVMCapabilities() {
  int flags = Syscall(GetVMCapabilitiesSyscall).Run().integer;
  VMCapabilities ret;
  if (flags & 1) ret.placementReserve = true;
  if (flags & 2) ret.placementMap = true;
  if (flags & 4) ret.executableFlag = true;
  if (flags & 8) ret.writableFlag = true;
  if (flags & 0x10) ret.cachableFlag = true;
  return ret;
}

bool AllocPhysical(PhysAddr & addrOut, PhysSize size, PhysSize align) {
  Syscall call(AllocateSyscall);
  call.PushPhysSize(size);
  call.PushPhysSize(align);
  PhysAddr addr = call.Run().phys;
  if (addr == 0) return false;
  addrOut = addr - 1;
  return true;
}

void FreePhysical(PhysAddr addr) {
  Syscall call(FreeSyscall);
  call.PushPhysAddr(addr);
  call.Run();
}

}
