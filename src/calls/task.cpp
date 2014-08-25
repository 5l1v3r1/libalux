#include "task.hpp"
#include <libalux/arch/syscall>

namespace libalux {

void Exit(int status) {
  Syscall call(1);
  call.PushBool(status != 0);
  call.Run();
  __builtin_unreachable();
}

}
