#ifndef __LIBALUX_TIME_H__
#define __LIBALUX_TIME_H__

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CLOCK_MONOTONIC 0

struct timespec {
  time_t tv_sec;
  long tv_nsec;
};

int clock_gettime(clockid_t clockId, struct timespec * timeOut);

#ifdef __cplusplus
}
#endif

#endif
