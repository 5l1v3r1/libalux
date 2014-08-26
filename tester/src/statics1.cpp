#include "statics1.hpp"
#include "statics2.hpp"

int StaticInt1 = 1;

struct _Incrementor1 {
  _Incrementor1() {
    ++StaticInt2;
  }
};

static _Incrementor1 myIncrementor;

bool CheckStaticIncrement1() {
  return StaticInt2 == 2;
}
