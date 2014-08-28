#include "syscall.hpp"
#include <cassert>

namespace libalux {

namespace x64 {

Syscall::Syscall(uint16_t num) : number(num) {
}

void Syscall::PushBool(bool arg) {
  PushUInt64(arg ? 1 : 0);
}

void Syscall::PushInt(int arg) {
  PushUInt64((uint64_t)arg);
}

void Syscall::PushUInt32(uint32_t arg) {
  PushUInt64((uint64_t)arg);
}

void Syscall::PushUInt64(uint64_t arg) {
  assert(idx < 5);
  arguments[idx++] = arg;
}

void Syscall::PushPhysAddr(PhysAddr arg) {
  PushUInt64((uint64_t)arg);
}

void Syscall::PushVirtAddr(VirtAddr arg) {
  PushUInt64((uint64_t)arg);
}

void Syscall::PushPhysSize(PhysSize arg) {
  PushUInt64((uint64_t)arg);
}

void Syscall::PushVirtSize(size_t arg) {
  PushUInt64((uint64_t)arg);
}

Syscall::RetVal Syscall::Run() {
  RetVal r;
  __asm__("mov 8(%%rbx), %%r8\n"
          "mov 0x10(%%rbx), %%r9\n"
          "mov (%%rbx), %%rbx\n"
          "syscall"
          : "=a" (*((uint64_t *)&r)), "=d" (*((uint64_t *)&r + 1))
          : "D" (number), "S" (arguments[0]), "d" (arguments[1]),
            "b" (&arguments[2])
          : "rcx", "r10", "r11", "memory");
  return r;
}

}

}
