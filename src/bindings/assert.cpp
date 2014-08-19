#include "assert.h"
#include <libalux/console>
#include <libalux/task>

extern "C" {

int __assert(const char * msg) {
  PrintConsole(msg);
  Exit(1);
}

}
