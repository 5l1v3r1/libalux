#include "cplusplus.hpp"
#include <libalux/console>
#include <libalux/task>

extern "C" {

void * __dso_handle = 0;

int __cxa_atexit(void (*) (void *), void *, void *) {
  return 0;
}

void __cxa_finalize(void *) {
}

void __cxa_pure_virtual() {
  libalux::PrintConsole("__cxa_pure_virtual()");
  libalux::Exit(1);
}

}
