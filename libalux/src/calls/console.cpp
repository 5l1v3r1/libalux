#include "console.hpp"
#include "syscalls.hpp"
#include <libalux/arch/syscall>

namespace libalux {

void PrintConsole(const char * str) {
  Syscall call(PrintSyscall);
  call.PushVirtAddr((VirtAddr)str);
  call.Run();
}

void SetColor(Color c, bool bright) {
  Syscall call(SetColorSyscall);
  call.PushInt((int)c);
  call.PushBool(bright);
  call.Run();
}

}
