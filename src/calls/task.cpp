#include "task.hpp"

namespace alux {

void Exit(int) {
  __asm__(""); // fool the compiler into thinking we did something
  __builtin_unreachable();
}

}
