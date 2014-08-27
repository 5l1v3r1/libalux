#include <libalux/arch/syscall>
#include "syscalls.hpp"

namespace libalux {

uint64_t GetBootNanoTime() {
  return Syscall(GetNanoTimeSyscall).Run().integer64;
}

}