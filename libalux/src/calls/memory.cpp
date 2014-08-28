#include "memory.hpp"
#include "syscalls.hpp"
#include <cassert>
#include <libalux/arch/syscall>

namespace libalux {

int CountPageSizes() {
  return Syscall(CountPageSizesSyscall).Run().value.integer;
}

size_t GetPageSize(int idx) {
  Syscall call(GetPageSizeSyscall);
  call.PushInt(idx);
  Syscall::RetVal result = call.Run();
  assert(result.error == 0);
  return result.value.vSize;
}

size_t GetPageAlign(int idx) {
  Syscall call(GetPageAlignSyscall);
  call.PushInt(idx);
  Syscall::RetVal result = call.Run();
  assert(result.error == 0);
  return result.value.vSize;
}

VMCapabilities GetVMCapabilities() {
  int flags = Syscall(GetVMCapabilitiesSyscall).Run().value.integer;
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
  Syscall::RetVal result = call.Run();
  if (result.error) return false;
  addrOut = result.value.phys;
  return true;
}

bool FreePhysical(PhysAddr addr) {
  Syscall call(FreeSyscall);
  call.PushPhysAddr(addr);
  return call.Run().error == 0;
}

bool VMRead(PhysAddr * physOut, VMAttributes * attrsOut, size_t * sizeOut,
            VirtAddr address) {
  Syscall call(VMReadSyscall);
  call.PushVirtAddr((VirtAddr)physOut);
  call.PushVirtAddr((VirtAddr)sizeOut);
  call.PushVirtAddr(address);
  Syscall::RetVal result = call.Run();
  if (result.error) return false;
  if (attrsOut) *attrsOut = VMAttributes(result.value.integer);
  return true;
}

bool VMMap(VirtAddr & addrOut, PhysAddr phys, VMSize size,
           const VMAttributes & attrs) {
  Syscall call(VMMapSyscall);
  call.PushPhysAddr(phys);
  call.PushVirtSize(size.pageSize);
  call.PushVirtSize(size.pageCount);
  call.PushInt((int)attrs);
  Syscall::RetVal result = call.Run();
  if (result.error) return false;
  addrOut = result.value.virt;
  return true;
}

bool VMMapAt(VirtAddr dest, PhysAddr source, VMSize size,
             const VMAttributes & attrs) {
  Syscall call(VMMapAtSyscall);
  call.PushVirtAddr(dest);
  call.PushPhysAddr(source);
  call.PushVirtSize(size.pageSize);
  call.PushVirtSize(size.pageCount);
  call.PushInt((int)attrs);
  return call.Run().error == 0;
}

bool VMUnmap(VirtAddr address, VMSize size) {
  Syscall call(VMUnmapSyscall);
  call.PushVirtAddr(address);
  call.PushVirtSize(size.pageSize);
  call.PushVirtSize(size.pageCount);
  return call.Run().error == 0;
}

bool VMUnmapAndReserve(VirtAddr address, VMSize size) {
  Syscall call(VMUnmapAndReserveSyscall);
  call.PushVirtAddr(address);
  call.PushVirtSize(size.pageSize);
  call.PushVirtSize(size.pageCount);
  return call.Run().error == 0;
}

bool VMReserve(VirtAddr & addrOut, VMSize size) {
  Syscall call(VMReserveSyscall);
  call.PushVirtSize(size.pageSize);
  call.PushVirtSize(size.pageCount);
  Syscall::RetVal ret = call.Run();
  if (ret.error) return false;
  addrOut = ret.value.virt;
  return true;
}

bool VMReserveAt(VirtAddr address, VMSize size) {
  Syscall call(VMReserveAtSyscall);
  call.PushVirtAddr(address);
  call.PushVirtSize(size.pageSize);
  call.PushVirtSize(size.pageCount);
  return call.Run().error == 0;
}

bool VMUnreserve(VirtAddr address, VMSize size) {
  Syscall call(VMUnreserveSyscall);
  call.PushVirtAddr(address);
  call.PushVirtSize(size.pageSize);
  call.PushVirtSize(size.pageCount);
  return call.Run().error == 0;
}

bool VMRereserve(VirtAddr address, VMSize size, size_t newPage) {
  Syscall call(VMRereserveSyscall);
  call.PushVirtAddr(address);
  call.PushVirtSize(size.pageSize);
  call.PushVirtSize(size.pageCount);
  call.PushVirtSize(newPage);
  return call.Run().error == 0;
}

}
