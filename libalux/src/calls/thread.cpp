#include "thread.hpp"
#include "syscalls.hpp"
#include <libalux/arch/syscall>

namespace libalux {

void ExitThread() {
  Syscall(ExitThreadSyscall).Run();
  __builtin_unreachable();
}

uint32_t GetThreadId() {
  return Syscall(GetThreadIdSyscall).Run().value.integer32;
}

bool LaunchThread(void (* func)(void *), void * arg, uint32_t * ident) {
  Syscall call(LaunchThreadSyscall);
  call.PushVirtAddr((VirtAddr)func);
  call.PushVirtAddr((VirtAddr)arg);
  Syscall::RetVal res = call.Run();
  if (res.error) return false;
  if (ident) *ident = res.value.integer32;
  return true;
}

void Sleep(uint64_t nanos) {
  Syscall call(SleepSyscall);
  call.PushUInt64(nanos);
  call.Run();
}

void SleepInfinite() {
  Syscall(SleepInfiniteSyscall).Run();
}

void Wakeup(uint32_t ident) {
  Syscall call(WakeupSyscall);
  call.PushUInt32(ident);
  call.Run();
}

}
