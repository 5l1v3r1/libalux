#include "console.hpp"
#include "syscalls.hpp"
#include <libalux/arch/syscall>

namespace libalux {

void PrintConsole(const char * str) {
  Syscall call(PrintSyscall);
  call.PushVirtAddr((VirtAddr)str);
  call.Run();
}

}
