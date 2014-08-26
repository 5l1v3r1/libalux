#include <libalux/task>
#include <libalux/arch/globals>

extern "C" {

int main();

void libalux_main() __asm__("libalux_main");

void libalux_main() {
  libalux::RunGlobalConstructors();
  libalux::Exit(main());
}

}
