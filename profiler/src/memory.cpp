#include <libalux/memory>
#include <libalux/print>
#include <libalux/time>

using namespace libalux;

void ProfileMemoryStats() {
  PrintLine("ProfileMemoryStats() - run at ", GetBootNanoTime() / 1000000,
            " millis after boot");
}

void ProfilePhysicalAllocation() {
  
}
