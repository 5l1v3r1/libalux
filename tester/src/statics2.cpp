#include "statics2.hpp"
#include "statics1.hpp"

int StaticInt2 = 1;

struct _Incrementor2 {
  _Incrementor2() {
    ++StaticInt1;
  }
};

static _Incrementor2 myIncrementor;

bool CheckStaticIncrement2() {
  return StaticInt1 == 2;
}
