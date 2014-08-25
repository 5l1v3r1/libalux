#include <libalux/task>

extern "C" {

int main();

void libalux_main() __asm__("libalux_main");

void libalux_main() {
  libalux::Exit(main());
}

}
