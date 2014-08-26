#include <cstdint>
#include <libalux/print>

extern "C" {

void _libalux_inits_start() __asm__("_libalux_inits_start");
void _libalux_inits_end() __asm__("_libalux_inits_end");
void _libalux_deinits_start() __asm__("_libalux_deinits_start");
void _libalux_deinits_end() __asm__("_libalux_deinits_end");

}

namespace libalux {

void RunGlobalConstructors() {
  uint64_t * startPtr = (uint64_t *)&_libalux_inits_start;
  uint64_t * endPtr = (uint64_t *)&_libalux_inits_end;
  PrintLine("startPtr is ", (uint64_t)startPtr, " end is ", (uint64_t)endPtr);
  for (; startPtr < endPtr; ++startPtr) {
    ((void (*)())*startPtr)();
  }
}

void RunGlobalDestructors() {
  uint64_t * startPtr = (uint64_t *)&_libalux_deinits_start;
  uint64_t * endPtr = (uint64_t *)&_libalux_deinits_end;
  for (; startPtr < endPtr; ++startPtr) {
    ((void (*)())*startPtr)();
  }
}

}