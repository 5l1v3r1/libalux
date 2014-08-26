#include "task.hpp"
#include "syscalls.hpp"
#include <libalux/arch/syscall>

extern "C" {

extern void __cxa_finalize(void *);

}

namespace libalux {

void Exit(int status) {
  __cxa_finalize(NULL);
  
  Syscall call(ExitSyscall);
  call.PushBool(status != 0);
  call.Run();
  __builtin_unreachable();
}

uint32_t GetPid() {
  Syscall call(GetPidSyscall);
  return call.Run().integer32;
}

uint32_t GetUid() {
  Syscall call(GetUidSyscall);
  return call.Run().integer32;
}

}
