extern "C" {

// I know what you're thinking: why the __asm__? Well, Clang sometimes adds an
// extra underscore to symbols.

void _libentry_inits_start() __asm__("_libentry_inits_start");
void _libentry_inits_end() __asm__("_libentry_inits_end");
void _libentry_deinits_start() __asm__("_libentry_deinits_start");
void _libentry_deinits_end() __asm__("_libentry_deinits_end");

}

namespace libentry {

typedef void (* Function)();

void RunGlobalConstructors() {
  Function * startPtr = (Function *)&_libentry_inits_start;
  Function * endPtr = (Function *)&_libentry_inits_end;
  for (; startPtr < endPtr; ++startPtr) {
    (*startPtr)();
  }
}

void RunGlobalDestructors() {
  Function * startPtr = (Function *)&_libentry_deinits_start;
  Function * endPtr = (Function *)&_libentry_deinits_end;
  for (; startPtr < endPtr; ++startPtr) {
    (*startPtr)();
  }
}

}