#include "globals.hpp"
#include "cxa.hpp"

extern "C" {

int main();

// once again, inline __asm__ so that clang doesn't add an underscore to the
// symbol name
void libentry_main() __asm__("libentry_main");

void libentry_main() {
  libentry::RunGlobalConstructors();
  int res = main();
  __cxa_finalize((void *)0);
  __asm__ __volatile__("syscall" : : "D" (1), "S" (res ? 1 : 0));
}

}
