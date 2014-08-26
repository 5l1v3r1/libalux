#include "cxa.hpp"
#include "globals.hpp"

extern "C" {

void * __dso_handle;

namespace {

struct _LibaluxExitRoutine {
  void (* destructor)(void *);
  void * arg;
};

const int routineMax = 0x800;
_LibaluxExitRoutine routines[routineMax];
int routineCount = 0;

}
 
int __cxa_atexit(void (* destructor) (void *), void * arg, void *) {
  if (routineCount == routineMax) return -1;
  _LibaluxExitRoutine routine = {destructor, arg};
  routines[routineCount++] = routine;
  return 0;
}

void __cxa_finalize(void *) {
  libentry::RunGlobalDestructors();
  while (routineCount) {
    auto routine = routines[--routineCount];
    routine.destructor(routine.arg);
  }
}

}