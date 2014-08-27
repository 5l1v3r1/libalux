#include "time.h"
#include <cassert>
#include <libalux/time>

extern "C" {

int clock_gettime(clockid_t clockId, struct timespec * timeOut) {
  if (clockId != CLOCK_MONOTONIC) return -1;
  assert(timeOut != NULL);
  uint64_t nanos = libalux::GetBootNanoTime();
  timeOut->tv_sec = nanos / 1000000000;
  timeOut->tv_nsec = nanos % 1000000000;
}

}
