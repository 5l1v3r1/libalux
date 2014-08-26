#include "task.hpp"
#include "syscalls.hpp"
#include <libalux/arch/syscall>
#include <libalux/arch/globals>

namespace libalux {

void Exit(int status) {
  RunGlobalDestructors();
  
  Syscall call(ExitSyscall);
  call.PushBool(status != 0);
  call.Run();
  __builtin_unreachable();
}

uint32_t GetPid() {
  Syscall call(GetPidSyscall);
  return call.Run().integer32;
}

}
