#include "assert.h"
#include <libalux/console>
#include <libalux/task>

extern "C" {

int __assert(const char * msg) {
  libalux::PrintConsole(msg);
  libalux::Exit(1);
}

}
