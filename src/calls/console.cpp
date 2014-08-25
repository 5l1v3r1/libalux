#include "console.hpp"
#include <libalux/arch/syscall>

namespace libalux {

void PrintConsole(const char * str) {
  Syscall call(0);
  call.PushVirtAddr((VirtAddr)str);
  call.Run();
}

}
