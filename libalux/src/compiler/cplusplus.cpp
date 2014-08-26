#include "cplusplus.hpp"
#include <libalux/console>
#include <libalux/task>

extern "C" {

void __cxa_pure_virtual() {
  libalux::PrintConsole("__cxa_pure_virtual()");
  libalux::Exit(1);
}

}
